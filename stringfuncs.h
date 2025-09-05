#ifndef STRINGFUNCS_H
#define STRINGFUNCS_H

#define RED_COLOR_CODE "\033[91m"
#define GREEN_COLOR_CODE "\033[32m"
#define NORMAL_COLOR_CODE "\033[37m"
#define STRLEN my_current_func = strlen_; \
               current_func = strlen;

enum error_codes {
    FATAL_ERROR_CODE = 10
};

const int DEFAULT_SIZE = 50;
const int SIZE = 100;
const int BASE = 2017;
const int MOD = 1000000009;

size_t strlen_(const char * str);
long int get_hash(int left, int right, long int *hash, long int * powers);
void init_hash(const char *str, long int *hash);
void init_powers(long int * powers);
void print_fatal_error();
char * strncat_(char * str1, const char * str2, int n);
char * strncpy_(char * str1, const char * str2, int n);
char * strchr_(char * str1, char ch);
char * strcat_(char * str1, const char * str2);
const char * strstr_(const char * str1, const char * src);
int strcmp_(const char * str1, const char * str2);
char * strcpy_(char * str1, const char * str2);
void print_before(const char * func_name, char * s, char * s2);
void print_after(char * s, char * s2);
int strncmp_(const char * str1, const char * str2, int n);
char * fgets_(char * s, int size, FILE * stream);
bool is_overlapping(const char * str1, const char * str2);
char * strdup_(const char * str);
void puts_(const char * str);
void print_everything_right(const char * name);
void print_error(const char *s, const char *s2, int n, const char * name);
void clear_line(FILE *fp);
int unitest_universal();

#endif // STRINGFUNCS_H