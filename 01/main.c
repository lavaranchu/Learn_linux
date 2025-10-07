#include <stdio.h>
#include "strutils.h"

int main() {
    char s1[] = " Hello World ";
    char s2[] = "ABCDE";
    int value;

    printf("Before trim: '%s'\n", s1);
    str_trim(s1);
    printf("After trim: '%s'\n", s1);

    printf("Before reverse: %s\n", s2);
    str_reverse(s2);
    printf("After reverse: %s\n", s2);

    if (str_to_int("12345", &value))
        printf("Converted value: %d\n", value);
    else
        printf("Conversion failed.\n");

    return 0;
}
