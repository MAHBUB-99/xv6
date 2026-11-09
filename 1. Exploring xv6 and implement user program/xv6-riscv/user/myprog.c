#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define BUF_SIZE 16

int readint(char *prompt) {
    char buf[BUF_SIZE];

    printf("%s", prompt);
    gets(buf, BUF_SIZE);
    if (buf[0] == '\0') {
        printf("Error reading input\n");
        exit(1);
    }
    if (buf[0] == '-')
        return -atoi(buf + 1);
    return atoi(buf);
}

int main() {
    char op[BUF_SIZE];
    int a, b;

    printf("Hello world from myprog.c\n");
    a = readint("First number: ");
    printf("Operator (+ - * /): ");
    gets(op, BUF_SIZE);
    b = readint("Second number: ");

    switch (op[0]) {
    case '+': printf("%d + %d = %d\n", a, b, a + b); break;
    case '-': printf("%d - %d = %d\n", a, b, a - b); break;
    case '*': printf("%d * %d = %d\n", a, b, a * b); break;
    case '/':
        if (b == 0)
            printf("Error: division by zero\n");
        else
            printf("%d / %d = %d\n", a, b, a / b);
        break;
    default:
        printf("Unknown operator '%c'\n", op[0]);
    }

    exit(0);
}
