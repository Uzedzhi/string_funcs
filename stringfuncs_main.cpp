#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "stringfuncs.h"

int main(void) {
    char s[DEFAULT_SIZE]  = "Hello";
    char s2[DEFAULT_SIZE] = "hellooooooo";
    // strlen
    unitest_universal();
    return 0;
}