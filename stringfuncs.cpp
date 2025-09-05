#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "stringfuncs.h"

#define SCAN_AND_COMPARE(func_name, count, ...)\
    if (fscanf(fp, "%[^,\n], %[^,\n], %d", ##__VA_ARGS__) != count) { \
            printf("%s %s", s, s2); \
            printf("invalid tests file");\
            return FATAL_ERROR_CODE;\
    }\
    clear_line(fp);\
    if ((func_name ## _)(__VA_ARGS__) != func_name(__VA_ARGS__)) {\
        printf("[%s], [%s]\n", (func_name ## _)(__VA_ARGS__), func_name(__VA_ARGS__));\
        print_error(s, s2, n, #func_name);\
        is_everything_okay = 0;\
    }

#define CHECK_CORRECT(func_name, fp) \
    if (is_everything_okay)\
        print_everything_right(#func_name);\
    is_everything_okay = 1;\

#define DO_TEST(func_name, count, s, ...) \
    fp = fopen("tests_" #func_name ".txt", "r");\
    clear_line(fp); \
    while ((ch = fgetc(fp)) != EOF) {\
        ungetc(ch, fp);\
        SCAN_AND_COMPARE(func_name, count, s, ##__VA_ARGS__)\
    }\
    CHECK_CORRECT(func_name, fp)\
    fclose(fp);


size_t strlen_(const char * str) {
    assert(str != NULL);

    const char * str_start = str;
    while (*str != '\0')
        str++;
    return str - str_start;
}
void print_fatal_error() {
    printf("fatal error has occured");
}

void init_hash(const char *str, long int *hash, int strlen_str) {
    hash[0] = 0;

    for (int i = 1; i <= strlen_str; ++i)
    {
        hash[i] = hash[i-1] + str[i-1];
    }
}

long int get_hash(int left, int right, long int hash[]) {
    return hash[right] - hash[left];
}

int unitest_universal() {
    int ch = 0;
    int is_everything_okay = 1;
    char s[DEFAULT_SIZE] = {};
    char s2[DEFAULT_SIZE] = {};
    int n = 0;
    FILE *fp;

    // strlen
    DO_TEST(strlen, 1, s);
    DO_TEST(strstr, 2, s, s2);
    DO_TEST(strcat, 2, s, s2);
    return 1;
}

void print_everything_right(const char * name) {
    printf(GREEN_COLOR_CODE "every test for function [%s] was done correctly, great job\n" NORMAL_COLOR_CODE, name);
}

void print_error(const char *s, const char *s2, int n, const char * name) {
    printf(RED_COLOR_CODE "error this testing str functions\n");
    printf("%s: with strings s1: [%s]\n"
           "                 s2: [%s]\n"
           "                  n: [%d]\n\n" NORMAL_COLOR_CODE, name, s, s2, n);
}

void clear_line(FILE *fp) {
    assert(fp != NULL);

    int ch = 0;
    while ((ch = getc(fp)) != EOF && ch != '\n')
        ;
}

void print_before(const char * func_name, char * s, char * s2) {
    assert(func_name != NULL && s != NULL && s2 != NULL);

    printf("%s\n", func_name);
    printf("before: s = [%s]\n"
           "        s2 = [%s]\n", s, s2);
}

void print_after(char * s, char * s2) {
    assert(s != NULL && s2 != NULL);

    printf("after: s = [%s]\n"
           "       s2 = [%s]\n\n", s, s2);
}

char * strcpy_(char * str1, const char * str2) {
    assert(str1 != NULL && str2 != NULL);

    if (is_overlapping(str1, str2))
        return NULL;

    while ((*str1++ = *str2++) != '\0')
        ;
    return str1;
}

char * strncpy_(char * str1, const char * str2, int n) {
    assert(str1 != NULL && str2 != NULL);

    if (is_overlapping(str1, str2))
        return NULL;

    while (n-- > 0 && (*str1++ = *str2++) != '\0')
        ;
    *str1 = '\0';

    return str1;
}

char * strchr_(char * str1, char ch) {
    assert(str1 != NULL);

    while (*str1 != '\0') {
        if (*str1 == ch) 
            return str1;
        str1++;
    }
    return NULL;
}
bool is_overlapping(const char * str1, const char * str2) {
    if (strlen_(str2) - strlen_(str1) == (long long unsigned int) (str1 - str2))
        return 1;
    return 0;
}

char * strdup_(const char * str) {
    char * str_dup = (char *) calloc(strlen_(str)+1, sizeof(char));
    strcpy_(str_dup, str);
    return str_dup;
}

char * fgets_(char * s, int size, FILE * stream) {
    assert(s != NULL && stream != NULL);

    char ch = 0;
    char * start_s = s;
    while ((ch = (char)getc(stream)) != EOF && size-- > 0) {
        *s++ = ch;
        if (ch == '\n')
            return start_s;
    }
    return start_s;
}

void puts_(const char * str) {
    assert(str != NULL);

    while (*str != '\0')
        putchar(*str++);
    
}

const char * strstr_(const char * str, const char * src) {
    assert(str != NULL && src != NULL);
    long int strhash[SIZE] = {};
    long int srchash[SIZE] = {};
    int strlen_str = strlen(str);
    int strlen_src = strlen(src);

    init_hash(str, strhash, strlen_str);
    init_hash(src, srchash, strlen_src);

    for (int i = 0; i <= strlen_str-strlen_src; i++) {
        if (get_hash(i, i + strlen_src, strhash) == srchash[strlen_src])
            return str+i;
    }
    return NULL;
}

int strncmp_(const char * str1, const char * str2, int n) {
    assert(str1 != NULL && str2 != NULL);

    while (--n > 0 && *str1 == *str2)
        if (*str1++ == '\0' || *str2++ == '\0')
            return 0;
    return str1[0] - str2[0];
}

int strcmp_(const char * str1, const char * str2) {
    assert(str1 != NULL && str2 != NULL);

    while (*str1 == *str2)
        if (*str1++ == '\0' || *str2++ == '\0')
            return 0;
    return str1[0] - str2[0];

}

char * strcat_(char * str1, const char * str2) {
    assert(str1 != NULL && str2 != NULL);

    if (is_overlapping(str1, str2))
        return NULL;
    char* start_of_str1 = str1;
    while (*str1 != '\0')
        str1++;
    while ((*str1++ = *str2++) != '\0') 
        ;
    return start_of_str1;  
}

char * strncat_(char * str1, const char * str2, int n) {
    assert(str1 != NULL && str2 != NULL);

    if (is_overlapping(str1, str2))
        return NULL;
    
    char* start_of_str1 = str1;
    while (*str1 != '\0')
        str1++;
    while (n-- > 0 && (*str1++ = *str2++) != '\0') 
        ;
    *str1 = '\0';

    return start_of_str1;
    
}