#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

#define PAGESIZE 4096

// This code show what happend if we used the same address
int main()
{
    u_int8_t* first = mmap((void*)0xAAAAAAAA, PAGESIZE, PROT_READ | PROT_WRITE,
                        MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    u_int8_t* second = mmap((void*)0xAAAAAAAA, PAGESIZE, PROT_READ | PROT_WRITE,
                        MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    printf("First: %p\n", first);
    printf("Second: %p\n", second);
}