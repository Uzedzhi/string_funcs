#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "stringfuncs.h"

int main(void) {
    char s[DEFAULT_SIZE]  = "Hello";
    char s2[DEFAULT_SIZE] = "hellooooooo";

    // strlen
    print_before("strlen", s, s2);
    printf("len of s: %lu\n"
           "len of s2: %lu\n\n", strlen_(s), strlen_(s2));

    // strcat
    print_before("strcat", s, s2);
    strcat_(s, s2);
    print_after(s, s2);

    // strcpy
    print_before("strcpy", s, s2);
    strcpy_(s, "Hell-");
    strcpy_(s2, "helo");
    print_after(s, s2);

    // strncmp
    strcpy_(s, "Helloa");
    strcpy_(s2, "HelloA");
    print_before("strcmp", s, s2);
    int is_equal = strncmp_(s, s2, 5);
    printf("strcmp: [%d]\n\n", is_equal);

    // strchr
    print_before("strchr", s, s2);
    char ch = '\0';
    printf("num_of_chr %c in %s:\n%s\n\n", ch, s, strchr_(s, ch));

    // strstr
    print_before("strstr", s, s2);
    const char * need_to_find = "lol";
    strcat_(s, "hellolhello");
    printf("location of %s in %s:\n%s\n\n", need_to_find, s, strstr_(s, need_to_find));

    return 0;
}