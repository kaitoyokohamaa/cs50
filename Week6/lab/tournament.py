# Simulate a sports tournament

import csv
import sys
import random
from sys import argv

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # TODO: Read teams into memory from file
    with open(argv[1], "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            row["rating"] = int(row["rating"])
            teams.append(row)
    counts = {}
    t = []
    # TODO: Simulate N tournaments and keep track of win counts
    for i in range(N):
        winners = simulate_tournament(teams)
        t.append(winners)

    for f in range(N):
        for i in range(len(teams)):
            counts[teams[i]["team"]] = t.count(teams[i]["team"])

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []
    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])
    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO
    count = teams
    while len(count) != 1:
        winner = simulate_round(count)
        count = winner

    return count[0]["team"]


if __name__ == "__main__":
    main()
