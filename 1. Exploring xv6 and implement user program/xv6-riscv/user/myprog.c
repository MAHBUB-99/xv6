#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define BUF_SIZE 10

int main() {
    char buf[BUF_SIZE];
    int num;

    printf("Hello world from myprog.c\n");
    printf("Enter a number: ");
    if (gets(buf, BUF_SIZE) <= 0) {
        printf("Error reading input\n");
        exit(1);
    }
    num = atoi(buf);
    printf("%d^2 = %d\n", num, num * num);
    
    exit(0);
}