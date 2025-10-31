#include <stdlib.h>
#include <stdio.h>
#define BUFFER_SIZE 10
#define OFFSET_MASK 0b111111111111
#define PAGES 8
#define OFFSET_BITS 12
#define PAGE_SIZE 32768
int page_table[PAGES] = {6, 4, 3, 7, 0, 1, 2, 5};


void part1();
void part2();
void part3();
int main() {
    //part1();
    //part2();
    part3();
    return 0;
}


void part1() {
    FILE *fptr = fopen("labaddr.txt", "r");
    char buff[BUFFER_SIZE];
    while (fgets(buff, BUFFER_SIZE, fptr) != NULL) {
        printf("%s", buff);
    }
    // Extra newline since last character line doesn't have newline
    printf("\n");
    fclose(fptr);
}

void part2() {
    FILE *fptr = fopen("labaddr.txt", "r");
    char buff[BUFFER_SIZE];
    while (fgets(buff, BUFFER_SIZE, fptr) != NULL) {
        int address = atoi(buff);
        // Assume the text file doesn't have 0 as an address in it
        if (address == 0) {
            printf("Not a valid address");
            continue;
        }

        int page_number = address >> OFFSET_BITS;
        int offset = address & OFFSET_MASK;
        printf("The logical address %d has page number %d and offset %d\n", address, page_number, offset);

    }
    fclose(fptr);
}

void part3() {
    int page_table[PAGES] = {6, 4, 3, 7, 0, 1, 2, 5};

    FILE *fptr = fopen("labaddr.txt", "r");
    char buff[BUFFER_SIZE];
    while (fgets(buff, BUFFER_SIZE, fptr) != NULL) {
        int address = atoi(buff);
        // Assume the text file doesn't have 0 as an address in it
        if (address == 0) {
            printf("Not a valid address");
            continue;
        }

        int page_number = address >> OFFSET_BITS;
        int offset = address & OFFSET_MASK;

        int frame_number = page_table[page_number];
        int physical_address = (frame_number << OFFSET_BITS) | offset;
        printf("The logical address %d has physical address %d, has page number %d, and has offset %d\n", address, physical_address, page_number, offset);

    }
    fclose(fptr);
}