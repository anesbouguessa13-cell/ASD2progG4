#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

int createBinaryFile(const char* filename);
int writeRecord(const char* filename, Record* r);
int readRecord(const char* filename, int index, Record* r);
int countRecords(const char* filename);
int appendRecord(const char* filename, Record* r);
int searchRecordById(const char* filename, int id, Record* result);
int updateRecord(const char* filename, int index, Record* newData);
int copyBinaryFile(const char* src, const char* dest);

#endif