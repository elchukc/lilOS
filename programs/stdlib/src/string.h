#ifndef LILOS_STRING_H
#define LILOS_STRING_H

#include <stdbool.h>

int strlen(const char* ptr);
int strnlen(const char* ptr, int max);
char* strcpy(char* dest, const char* src);
char* strncpy(char* dest, const char* src, int n);
bool isdigit(char c);
int tonumericdigit(char c);
int strncmp(const char* s1, const char* s2, int n);
int istrncmp(const char* s1, const char* s2, int n);
int strnlen_terminator(const char* str, int max, char terminator);
char tolower(char s1);
char* strtok(char* str, const char* delimiters);

#endif