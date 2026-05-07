#include "../include/string_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int my_strlen(const char* s){
    int i;
    while (s[i] != '\0') {
        i++;
    }

    return i;
}
char* my_strcpy(char* dest, const char* src){
    int i = 0;

    
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    
    dest[i] = '\0';

    
    return dest;
}
char* my_strncpy(char* dest, const char* src, int n){
    char* start = dest;

    while (n > 0 && *src != '\0') {
        *dest++ = *src++;
        n--;
    }
    while (n > 0) {
        *dest++ = '\0';
        n--;
    }
    
    return start;
}
char* my_strcat(char* dest, const char* src){
    
    int i = 0;
    int j = 0;

    
    while (dest[i] != '\0') {
        i++;
    }

    
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }

    
    dest[i] = '\0';

    return dest;

}
int my_strcmp(const char* a, const char* b){
    int i = 0;

    
    while (a[i] != '\0' && a[i] == b[i]) {
        i++;
    }

    
    return (unsigned char)a[i] - (unsigned char)b[i];
}
int my_strncmp(const char* a, const char* b, int n){
    while (n > 0 && *a && (*a == *b)) {
        a++;
        b++;
        n--;
    }
    
    
    if (n == 0) return 0;
    
    return *(unsigned char*)a - *(unsigned char*)b;
}
void toUpperCase(char* s){
    int i = 0;

    while (s[i] != '\0') {
        
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 32; 
        }
        i++;
    }
}
void toLowerCase(char* s){
    int i = 0;

    
    while (s[i] != '\0') {
        
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32;
        }
        i++;
    }
}
void reverseString(char* s){
    if (s == NULL) return; 

    int i = 0;
    int j = strlen(s) - 1;
    char temp;

    while (i < j) {
       
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;

        
        i++;
        j--;
    }
}
int countVowels(const char* s){
    int count = 0;
    bool inWord = false;

    for (int i = 0; s[i] != '\0'; i++) {
        
        if (isspace((unsigned char)s[i])) {
            inWord = false;
        } 
        
        else if (!inWord) {
            inWord = true;
            count++;
        }}
 }
int countWords(const char* s){
    int count = 0;
    bool inWord = false; 

    for (int i = 0; s[i] != '\0'; i++) {
        
        if (isspace((unsigned char)s[i])) {
            inWord = false; 
        } 
        
        else if (!inWord) {
            inWord = true; 
            count++;       
        }
}
}
int isPalindrome(const char* s){
    


    if (s == NULL) return 0;

    int i = 0;
    int j = strlen(s) - 1;

    
    while (i < j) {
        
        if (s[i] != s[j]) {
            return 0; 
        }
        i++;
        j--;
    }

    
    return 1; 
}

void removeChar(char* s, char c){
    int j = 0; 

    for (int i = 0; s[i] != '\0'; i++) {
        
        if (s[i] != c) {
            
            s[j] = s[i];
            j++;
        }
}
}
void removeSpaces(char* s){
    int j = 0; 

    for (int i = 0; s[i] != '\0'; i++) {
       
        if (!isspace((unsigned char)s[i])) {
            s[j] = s[i];
            j++;
        }
    }

    
    s[j] = '\0';
}
void substring(const char* src, int start, int len, char* dest){
    


    int src_len = strlen(src);

    
    if (start < 0 || start >= src_len || (start + len) > src_len) {
        
        dest[0] = '\0';
        return;
    }

    
    int i;
    for (i = 0; i < len; i++) {
        dest[i] = src[start + i];
    }

    
    dest[i] = '\0';

}
int compareIgnoreCase(const char* a, const char* b){
    


    
    while (*a && (tolower((unsigned char)*a) == tolower((unsigned char)*b))) {
        a++;
        b++;
    }

    
    return (unsigned char)tolower((unsigned char)*a) - (unsigned char)tolower((unsigned char)*b);

}
//bghghgg