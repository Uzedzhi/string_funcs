#ifndef STRINGFUNCS_H
#define STRINGFUNCS_H

const int DEFAULT_SIZE = 20;
const char * str1_default = "hello";
const char * str2_default = "world";

size_t strlen_(const char * str);
char * strchr_(char * str1, char ch);
char * strcat_(char * str1, const char * str2);
char * strstr_(char * str1, const char * src);
int strcmp_(const char * str1, const char * str2);
char * strcpy_(char * str1, const char * str2);
void print_before(const char * func_name, char * s, char * s2);
void print_after(char * s, char * s2);
int strncmp_(const char * str1, const char * str2, int n);
char * fgets_(char * s, int size, FILE * stream);
bool is_overlapping(const char * str1, const char * str2);
char * strdup_(const char * str);
void puts_(const char * str);

#endif // STRINGFUNCS_H