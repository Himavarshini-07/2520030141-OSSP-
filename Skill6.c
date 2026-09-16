#include <stdio.h>
#include <string.h>

int main() {
    char input[200];
    char output[200];
    int i, j = 0;

    printf("Enter a string with escape sequences:\n");
    fgets(input, sizeof(input), stdin);

    for(i = 0; input[i] != '\0'; i++) {
        if(input[i] == '\\') {
            i++;
            switch(input[i]) {
                case 'n':
                    output[j++] = '\n';
                    break;
                case 't':
                    output[j++] = '\t';
                    break;
                case '\\':
                    output[j++] = '\\';
                    break;
                case ' ':
                    output[j++] = ' ';
                    break;
                case '"':
                    output[j++] = '"';
                    break;
                case '\'':
                    output[j++] = '\'';
                    break;
                default:
                    output[j++] = '\\';
                    output[j++] = input[i];
            }
        } else {
            output[j++] = input[i];
        }
    }

    output[j] = '\0';

    printf("\n--- Parser Output ---\n");
    printf("%s\n", output);

    printf("\nLength: %lu\n", strlen(output));

    return 0;
}
