#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include "common.h"

int my_strlen(const char* s);
char* my_strcpy(char* dest, const char* src);
char* my_strncpy(char* dest, const char* src, int n);
char* my_strcat(char* dest, const char* src);
int my_strcmp(const char* a, const char* b);
int my_strncmp(const char* a, const char* b, int n);
void toUpperCase(char* s);
void toLowerCase(char* s);
void reverseString(char* s);
int countVowels(const char* s);
int countWords(const char* s);
int isPalindrome(const char* s);
void removeChar(char* s, char c);
void removeSpaces(char* s);
void substring(const char* src, int start, int len, char* dest);
int compareIgnoreCase(const char* a, const char* b);

#endif