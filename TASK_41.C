#include <stdio.h>
#include <string.h>

void runLengthEncode(char *str) {
    int len = strlen(str);
    int count;
    
    printf("Encoded Output: ");
    for (int i = 0; i < len; i++) {
        // Count occurrences of current character
        count = 1;
        while (str[i] == str[i + 1]) {
            count++;
            i++;
        }
printf("%c%d", str[i], count);  // Print character followed by count
    }
    printf("\n");
}

int main() {
    char input[100];

    printf("Enter a string to compress using RLE: ");
    scanf("%s", input);

    runLengthEncode(input);

    return 0;
}
