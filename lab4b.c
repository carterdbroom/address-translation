#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>

#define INT_COUNT 10
#define INT_SIZE 4
#define MEMORY_SIZE INT_COUNT * INT_SIZE
int intArray[MEMORY_SIZE];
int intArry[INT_COUNT];
signed char *mmapfptr;

int main() {
    int mmapfile_fd = open("numbers.bin", O_RDONLY);
    mmapfptr = mmap(0, MEMORY_SIZE, PROT_READ, MAP_PRIVATE, mmapfile_fd, 0);

    for (int i = 0; i < INT_COUNT; i++) {
        memcpy(intArray + i, mmapfptr + 4*i, INT_SIZE);
    }

    munmap(mmapfptr, MEMORY_SIZE);
    int sum = 0;
    for(int i = 0; i < INT_COUNT; i++) {
        sum += intArray[i];
    }
    printf("Sum of numbers = %d\n", sum);
}