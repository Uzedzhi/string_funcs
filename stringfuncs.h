
#define DEFAULT_SIZE 20
const char * str1_default = "hello";
const char * str2_default = "world";


int strlen(const char * str);
char * strchr(char * str1, char ch);
char * strcat(char * str1, const char * str2);
char * strstr(char * str1, const char * src);
int strcmp(char * str1, char * str2);
char * strcpy(char * str1, const char * str2);
void print_before(const char * func_name, char * s, char * s2);
void print_after(char * s, char * s2);