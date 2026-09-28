#include <stdio.h>

// Function prototypes
int my_strlen(const char *str);
void my_strcpy(char *dest, const char *src);

int main(void) {
    char test[] = "Programming in C";
    char copy[100];

    int len = my_strlen(test);
    printf("Length: %d\n", len);

    my_strcpy(copy, test);
    printf("Copy: %s\n", copy);

    return 0;
}

int my_strlen(const char *str) {
    int count = 0;

    while (str[count]  != '\0') {
        count++;
    }
    return count;
}

void my_strcpy(char *dest, const char *src) {
    int i = 0;

    while (src[i]  != '\0') {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
}
