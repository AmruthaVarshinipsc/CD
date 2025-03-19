#include <stdio.h>
#include <conio.h>

int constantpropagation() {
    int a = 30;
    int b = 3;
    int c;

    c = b * 4;

    if (c > 10) {
        c = c - 10;
    }

    return c * 2;
}

void main() {
    
    printf("Result of constant propagation is %d", constantpropagation());
    getch();
}



OUTPUT:
Result of constant propagation is 4
