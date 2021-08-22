import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True


# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    usersID=session["user_id"]
    cash = db.execute("SELECT cash FROM users WHERE id = ?", usersID)
    rowBuys = db.execute("SELECT * FROM buys WHERE id = ?", usersID)
    sum=0
    for row in rowBuys:
        sum=sum+(row["shares"]*row["money"])

    total=cash[0]["cash"]-sum
    return render_template("index.html",rowBuys=rowBuys,cash=cash,total=total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "POST":
        symbol=request.form.get("symbol")
        shares=request.form.get("shares")
        usersID=session["user_id"]
        lookQuote=lookup(symbol)
        if not symbol:
            return apology("must provide symbol", 400)

        elif not shares:
            return apology("missing share", 400)

        elif db.execute("SELECT * FROM buys WHERE name = ?AND id= ?", lookQuote["symbol"],usersID):
            oldShares=db.execute("SELECT shares FROM buys WHERE name = ? AND id= ?", lookQuote["symbol"],usersID)
            sum=int(oldShares[0]["shares"])+int(shares)
            db.execute("UPDATE buys SET shares=? WHERE name = ? AND id=?", sum,lookQuote["symbol"],usersID)
            return redirect("/")

        rows = db.execute("INSERT INTO buys (id,user_name,name,money,shares) VALUES(?,?,?,?,?)",usersID,lookQuote["name"],lookQuote["symbol"],lookQuote["price"],shares)
        return redirect("/")
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return render_template("history.html")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol=request.form.get("symbol")
        if not symbol:
            return apology("Missing symbol", 400)
        lookQuote=lookup(symbol)
        return render_template("quoted.html",quote=lookQuote)

    else:
        return render_template("quote.html")

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        name=request.form.get("username")
        password=request.form.get("password")
        confirmation=request.form.get("confirmation")
        if not name:
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not password:
            return apology("must provide password", 400)

        elif not confirmation == password:
            return apology("must match password", 400)

        elif db.execute("SELECT * FROM users WHERE username = ?", name):
            return apology("this name is already exist", 400)
        # Query database for username
        hashed_password = generate_password_hash(password)

        rows = db.execute("INSERT INTO users (username,hash) VALUES(?,?)", name,hashed_password)
        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        symbol=request.form.get("symbol")
        shares=request.form.get("shares")
        usersID=session["user_id"]
        current_shares=db.execute("SELECT shares FROM buys WHERE name = ? AND id= ?", symbol,usersID)
        if not symbol:
            return apology("must provide symbol", 400)

        elif not shares:
            return apology("missing share", 400)

        elif int(current_shares[0]["shares"]) < int(shares):
            return apology("too many share", 400)

        elif db.execute("SELECT * FROM buys WHERE name = ?AND id= ?",symbol ,usersID):
            oldShares=db.execute("SELECT shares FROM buys WHERE name = ? AND id= ?", symbol,usersID)
            sum=int(oldShares[0]["shares"])-int(shares)
            db.execute("UPDATE buys SET shares=? WHERE name = ? AND id=?", sum,symbol,usersID)
            return redirect("/")
    else:
        usersID=session["user_id"]
        names = db.execute("SELECT name FROM buys WHERE id = ?", usersID)
        return render_template("sell.html",names=names)


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
