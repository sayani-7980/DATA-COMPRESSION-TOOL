#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to perform Run-Length Encoding (compression)
void compressFile(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (in == NULL || out == NULL) {
        printf("Error opening file.\n");
        return;
    }
char current, previous;
    int count = 1;

    previous = fgetc(in);

    while ((current = fgetc(in)) != EOF) {
        if (current == previous) {
            count++;
        } else {
            fprintf(out, "%c%d", previous, count);
            previous = current;
            count = 1;
        }
    }
if (previous != EOF) {
        fprintf(out, "%c%d", previous, count);
    }

    fclose(in);
    fclose(out);

    printf("Compression complete. Output saved to '%s'.\n", outputFile);
}
void decompressFile(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (in == NULL || out == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char ch;
    int count;
 while ((ch = fgetc(in)) != EOF) {
        // Read the number (count)
        char countStr[10];
        int i = 0;

        while (isdigit(ch = fgetc(in)) && ch != EOF) {
            countStr[i++] = ch;
        }

        countStr[i] = '\0';
        count = atoi(countStr);

        for (int j = 0; j < count; j++) {
            fputc(ch == EOF ? '\0' : ch, out);
        }

        if (ch != EOF)
            ungetc(ch, in); // Put back non-digit character if any
    }
fclose(in);
    fclose(out);

    printf("Decompression complete. Output saved to '%s'.\n", outputFile);
}
int main() {
    int choice;
    char inputFile[100], outputFile[100];

    while (1) {
        printf("\n--- RLE Compression Tool ---\n");
        printf("1. Compress File\n");
        printf("2. Decompress File\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline after number input

        switch (choice) {
case 1:
                printf("Enter input file name to compress: ");
                scanf("%s", inputFile);
                printf("Enter output file name to save compressed data: ");
                scanf("%s", outputFile);
                compressFile(inputFile, outputFile);
                break;
            case 2:
                printf("Enter input file name to decompress: ");
                scanf("%s", inputFile);
                printf("Enter output file name to save decompressed data: ");
                scanf("%s", outputFile);
                decompressFile(inputFile, outputFile);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
