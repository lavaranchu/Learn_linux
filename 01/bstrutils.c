#include "strutils.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

void str_reverse(char *s) {
    if (!s) return;
    int len = strlen(s);
    for (int i = 0; i < len / 2; ++i) {
        char tmp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = tmp;
    }
}

void str_trim(char *s) {
    if (!s) return;
    char *start = s;
    while (isspace((unsigned char)*start)) start++;
    char *end = s + strlen(s) - 1;
    while (end > start && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';
    if (start != s) memmove(s, start, end - start + 2);
}

int str_to_int(const char *s, int *out_value) {
    if (!s || !out_value) return 0;
    char *endptr;
    long val = strtol(s, &endptr, 10);
    if (*endptr != '\0') return 0; // Không phải toàn bộ là số
    *out_value = (int)val;
    return 1;
}
