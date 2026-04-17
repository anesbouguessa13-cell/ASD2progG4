#include <stdio.h>
#include "include/array.h"
#include "include/linked_list.h"
#include "include/stack.h"
#include "include/queue.h"
#include "include/file_utils.h"
#include "include/string_utils.h"

void arrayMenu() {
    int choice, arr[MAX_1D], size = 0, value, index;
    do {
        printf("\n=== ARRAY MENU ===\n");
        printf("1. Insert element\n2. Delete element\n"
               "3. Search\n4. Sort\n5. Display\n0. Back\nChoice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Index and value: ");
                scanf("%d %d", &index, &value);
                insertAt(arr, &size, index, value);
                break;
            /* ... other cases ... */
        }
    } while (choice != 0);
}

int main() {
    int choice;
    do {
        printf("\n=== ADS2 PROJECT DEMO ===\n");
        printf("1. Arrays\n2. Linked Lists\n3. Stacks\n"
               "4. Queues\n5. File Handling\n6. String Utils\n0. Exit\nChoice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: arrayMenu(); break;
            /* ... */
        }
    } while (choice != 0);
    return 0;
}

