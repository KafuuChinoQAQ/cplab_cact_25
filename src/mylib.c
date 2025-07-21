#include <stdio.h>

void print_int(int x) {
    printf("%d\n", x);
}

void print_float(float x) {
    printf("%f\n", x);
}

void print_char(char x) {
    printf("%c\n", x);
}

int get_int() {
    int x;
    scanf("%d", &x);
    return x;
}

float get_float() {
    float x;
    scanf("%f", &x);
    return x;
}

char get_char() {
    char x;
    scanf(" %c", &x);
    return x;
}