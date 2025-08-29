#include <stdio.h>

#include "stringfuncs.h"
//  
int main(void) {
    char s[DEFAULT_SIZE]  = "Hello";
    char s2[DEFAULT_SIZE] = "hellooooooo";

    // strlen
    print_before("strlen", s, s2);
    printf("len of s: %d\n"
           "len of s2: %d\n\n", strlen(s), strlen(s2));

    // strcat
    print_before("strcat", s, s2);
    strcat(s, s2);
    print_after(s, s2);

    // strcpy
    print_before("strcpy", s, s2);
    strcpy(s, "Hell-");
    strcpy(s2, "helo");
    print_after(s, s2);

    // strcmp
    strcpy(s, "Hello");
    strcpy(s2, "hello");
    print_before("strcmp", s, s2);
    int is_equal = strcmp(s, s2);
    printf("strcmp: [%d]\n\n", is_equal);

    // strchr
    print_before("strchr", s, s2);
    char ch = '\0';
    printf("num_of_chr %c in %s:\n%s\n\n", ch, s, strchr(s, ch));

    // strstr
    print_before("strstr", s, s2);
    const char * need_to_find = "lol";
    strcat(s, "hellolhello");
    printf("location of %s in %s:\n%s\n\n", need_to_find, s, strstr(s, need_to_find));

    return 0;
}

int strlen(const char * str) {
    const char * str_start = str;
    while (*str != '\0')
        str++;
    return str - str_start;
}

void print_before(const char * func_name, char * s, char * s2) {
    printf("%s\n", func_name);
    printf("before: s = [%s]\n"
           "        s2 = [%s]\n", s, s2);
}

void print_after(char * s, char * s2) {
    printf("after: s = [%s]\n"
           "       s2 = [%s]\n\n", s, s2);
}

// aaaaaafasdfasdfsadfsadfasdf\0
//  ^               ^
// str2            str1

char * strcpy(char * str1, const char * str2) { // todo what if str1 and str2 overlap?
    int num_of_symbol = 0;

    while (*str2) {
        str1[num_of_symbol++] = *str2++;
    }
    str1[num_of_symbol] = '\0';

    return str1;
}

char * strchr(char * str1, char ch) {
    while (*str1 != '\0') {
        if (*str1 == ch) 
            return str1;
        str1++;
    }
    return NULL;
}

char * strstr(char * str1, const char * src) {
    int len_of_src = strlen(src);

    while (*(str1 + len_of_src) != '\0') {
        int is_same = 1;
        for (int i = 0; i < len_of_src; i++) {
            if (str1[i] != src[i]) {
                is_same = 0;
                break;
            }
        }
        if (is_same)
            return str1;
        str1++;
    }

    return NULL;
}

int strcmp(char * str1, char * str2) {
    while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
        str1++; 
        str2++;
    }
    if (*str1 == '\0' && *str2 == '\0')
        return 0;
    return str1[0] - str2[0];

}

char * strcat(char * str1, const char * str2) {
    char* start_of_str1 = str1;
    while (*str1 != '\0')
        str1++;
    while ((*str1++ = *str2++) != '\0') 
        ;
    return start_of_str1;
    
}