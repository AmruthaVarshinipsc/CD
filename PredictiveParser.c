#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char a[10];
int top = -1, i;

void error() {
    printf("Syntax Error");
}

void push(char k[]) {
    for (i = 0; k[i] != '\0'; i++) {
        if (top < 9)
            a[++top] = k[i];
    }
}

char TOS() {
    return a[top];
}

void pop() {
    if (top >= 0)
        a[top--] = '\0';
}

void display() {
    for (i = 0; i <= top; i++)
        printf("%c", a[i]);
}

void display1(char p[], int m) {
    int l;
    printf("\t");
    for (l = m; p[l] != '\0'; l++)
        printf("%c", p[l]);
}

char* stack() {
    return a;
}

int main() {
    char ip[20], r[20], st, an;
    int ir, ic, j = 0, k;
    char t[5][6][10] = {
        {"$", "$", "TH", "$", "TH", "$"},
        {"+TH", "$", "e", "e", "$", "e"},
        {"$", "$", "FU", "$", "FU", "$"},
        {"e", "*FU", "e", "e", "$", "e"},
        {"$", "$", "(E)", "$", "i", "$"}
    };

    printf("\nEnter any String(Append with $): ");
    scanf("%s", ip);

    printf("Stack\tInput\tOutput\n\n");
    push("$E");
    display();
    printf("\t%s\n", ip);

    for (j = 0; ip[j] != '\0';) {
        if (TOS() == ip[j]) {
            pop();
            display();
            display1(ip, j + 1);
            printf("\tPOP\n");
            j++;
            continue;
        }

        an = ip[j];
        st = TOS();

        if (st == 'E') ir = 0;
        else if (st == 'H') ir = 1;
        else if (st == 'T') ir = 2;
        else if (st == 'U') ir = 3;
        else if (st == 'F') ir = 4;
        else {
            error();
            break;
        }

        if (an == '+') ic = 0;
        else if (an == '*') ic = 1;
        else if (an == '(') ic = 2;
        else if (an == ')') ic = 3;
        else if ((an >= 'a' && an <= 'z') || (an >= 'A' && an <= 'Z')) {
            ic = 4;
            an = 'i';
        }
        else if (an == '$') ic = 5;
        else {
            error();
            break;
        }

        if (strcmp(t[ir][ic], "$") == 0) {
            error();
            break;
        }

        strcpy(r, t[ir][ic]);
        strrev(r);
        pop();
        push(r);

        if (TOS() == 'e') {
            pop();
            display();
            display1(ip, j);
            printf("\t%c->%c\n", st, 238); // 238 used for epsilon
        }
        else {
            display();
            display1(ip, j);
            printf("\t%c->%s\n", st, t[ir][ic]);
        }

        if (TOS() == '$' && an == '$')
            break;

        if (TOS() == '$') {
            error();
            break;
        }
    }

    k = strcmp(stack(), "$");
    if (k == 0)
        printf("\n Given String is accepted");
    else
        printf("\n Given String is not accepted");

    return 0;
}




OUTPUT:

Enter any String(Append with $): i+i*i$
Stack   Input   Output

$E      i+i*i$
$HT     i+i*i$  E->TH
$HUF    i+i*i$  T->FU
$HUi    i+i*i$  F->i
$HU     +i*i$   POP
$H      +i*i$   U->¯
$HT+    +i*i$   H->+TH
$HT     i*i$    POP
$HUF    i*i$    T->FU
$HUi    i*i$    F->i
$HU     *i$     POP
$HUF*   *i$     U->*FU
$HUF    i$      POP
$HUi    i$      F->i
$HU     $       POP
$H      $       U->¯
$       $       H->¯

 Given String is accepted
