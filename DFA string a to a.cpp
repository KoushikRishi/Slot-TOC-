#include <stdio.h>
int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    if (input[0] == 'a' && input[strlen(input) - 1] == 'a')
        printf("Accepted\n");
    else
        printf("Not accepted\n");

    return 0;
}
