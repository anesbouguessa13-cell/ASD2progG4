#include "include/file_utils.h"



int createBinaryFile(const char* filename) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        return -1;
    }
    fclose(fp);
    return 0;
}

int writeRecord(const char* filename, Record* r) {
    FILE* fp = fopen(filename, "ab");
    if (fp == NULL) {
        return -1;
    }
    
    size_t written = fwrite(r, sizeof(Record), 1, fp);
    fclose(fp);
    
    return (written == 1) ? 0 : -1;
}

int readRecord(const char* filename, int index, Record* r) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        return -1;
    }
    
    long offset = (long)index * sizeof(Record);
    if (fseek(fp, offset, SEEK_SET) != 0) {
        fclose(fp);
        return -1;
    }
    
    size_t read = fread(r, sizeof(Record), 1, fp);
    fclose(fp);
    
    return (read == 1) ? 0 : -1;
}

int countRecords(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        return -1;
    }
    
    if (fseek(fp, 0, SEEK_END) != 0) {
        fclose(fp);
        return -1;
    }
    
    long sizeInBytes = ftell(fp);
    fclose(fp);
    
    if (sizeInBytes < 0) {
        return -1;
    }
    
    return (int)(sizeInBytes / sizeof(Record));
}

int appendRecord(const char* filename, Record* r) {
    return writeRecord(filename, r);
}

int searchRecordById(const char* filename, int id, Record* result) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        return -1;
    }
    
    Record current;
    int index = 0;
    int found = 0;
    
    while (fread(&current, sizeof(Record), 1, fp) == 1) {
        if (current.id == id) {
            *result = current;
            found = 1;
            break;
        }
        index++;
    }
    
    fclose(fp);
    return found ? index : -1;
}

int updateRecord(const char* filename, int index, Record* newData) {
    int totalRecords = countRecords(filename);
    if (index < 0 || index >= totalRecords) {
        return -1;
    }

    FILE* fp = fopen(filename, "r+b");
    if (fp == NULL) {
        return -1;
    }
    
    long offset = (long)index * sizeof(Record);
    if (fseek(fp, offset, SEEK_SET) != 0) {
        fclose(fp);
        return -1;
    }
    
    size_t written = fwrite(newData, sizeof(Record), 1, fp);
    fclose(fp);
    
    return (written == 1) ? 0 : -1;
}

int copyBinaryFile(const char* src, const char* dest) {
    FILE* fpSrc = fopen(src, "rb");
    if (fpSrc == NULL) {
        return -1;
    }
    
    FILE* fpDest = fopen(dest, "wb");
    if (fpDest == NULL) {
        fclose(fpSrc);
        return -1;
    }
    
    Record buffer;
    int status = 0;
    
    while (fread(&buffer, sizeof(Record), 1, fpSrc) == 1) {
        if (fwrite(&buffer, sizeof(Record), 1, fpDest) != 1) {
            status = -1;
            break;
        }
    }
    
    fclose(fpSrc);
    fclose(fpDest);
    return status;
}