// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;
typedef uint8_t HEADER;
int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);
    // TODO: Copy header from input file to output file
    HEADER bytes[HEADER_SIZE];
    // ヘッダをコピー
    // printf("%lu",sizeof(bytes));
    // fread(&bytes,sizeof(HEADER),HEADER_SIZE,input);


        fread(&bytes,sizeof(HEADER),44,input);

        fwrite(&bytes,sizeof(HEADER), 44, output);


    // TODO: Read samples from input file and write updated data to output file
    int16_t buffer[HEADER_SIZE];
    // 音を二倍にする
    printf("%lu\n",sizeof(HEADER));
    for(int i=0;i<sizeof(buffer);i++)
    {
        // if(43>sizeof(buffer[i]))
        // {
        //     fread(&buffer,sizeof(buffer),1,input);
        //     buffer[i]=buffer[i] *factor;
        //     fwrite(&buffer,sizeof(buffer),1,output);
        // }
    }
    // while (fread(&buffer,sizeof(buffer),1,input))
    // {
    //     fwrite(&buffer,sizeof(buffer), 1, output);
    // }

    fclose(input);
    fclose(output);
}
