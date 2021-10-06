#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <time.h>
#include <conio.h>

int memory_alloc_with_setting(size_t size) {
    clock_t start, end;
    double duration;

    printf("allocate start\n");
    start = clock();
    void* ptr = malloc(size);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("allocate spent %f sec\n", duration);
    printf("allocate end\n");

    printf("please any key to start memset...");
    getch();

    printf("memset start\n");
    start = clock();
    memset(ptr, 0, size);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("memset spent %f sec\n", duration);
    printf("memset end\n");

    getch();

    return 0;
}

const size_t one_gb = 1024LL * 1024LL * 1024LL;

int main() {
    size_t gb = 10LL;

    printf("please input allocating memory size(unit: GB, Gigabytes):");
    scanf("%zd", &gb);
    size_t size = gb * one_gb;

    printf("Start testing\n");
    memory_alloc_with_setting(size);
    printf("End testing\n");

    return 0;
}
