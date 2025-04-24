#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

char ip_sym[15], stack[15];
int ip_ptr = 0, st_ptr = 0, len;
char act[20];

void check();

void main()
{
    clrscr();
    printf("\n\t\t SHIFT REDUCE PARSER\n");
    printf("\n GRAMMAR\n E->E+E\n E->E/E\n E->E*E\n E->a/b");

    printf("\n\n Enter the input symbol:\t");
    gets(ip_sym);

    printf("\n\t Stack Implementation Table");
    printf("\n Stack\t\t Input Symbol\t\t Action");
    printf("\n ______\t\t ____________\t\t ______");

    printf("\n $\t\t%s$\t\t\t--", ip_sym);

    len = strlen(ip_sym);

    for (int i = 0; i < len; i++)
    {
        stack[st_ptr++] = ip_sym[ip_ptr];
        stack[st_ptr] = '\0';
        ip_sym[ip_ptr++] = ' ';

        sprintf(act, "shift %c", stack[st_ptr - 1]);
        printf("\n $%s\t\t%s$\t\t\t%s", stack, ip_sym, act);

        check();
    }

    check(); // Final check after full shift
}

void check()
{
    char top = stack[st_ptr - 1];
    int flag = 0;

    if (top == 'a' || top == 'b')
    {
        stack[st_ptr - 1] = 'E';
        printf("\n $%s\t\t%s$\t\t\tE->%c", stack, ip_sym, top);
        flag = 1;
    }

    while (st_ptr >= 3)
    {
        if ((stack[st_ptr - 3] == 'E' && (stack[st_ptr - 2] == '+' || stack[st_ptr - 2] == '/' || stack[st_ptr - 2] == '*') && stack[st_ptr - 1] == 'E'))
        {
            stack[st_ptr - 3] = 'E';
            st_ptr -= 2;
            stack[st_ptr] = '\0';
            printf("\n $%s\t\t%s$\t\t\tE->E%cE", stack, ip_sym, stack[st_ptr - 1]);
            flag = 1;
        }
        else
            break;
    }

    if (strcmp(stack, "E") == 0 && ip_ptr == len)
    {
        printf("\n $%s\t\t%s$\t\t\tACCEPT", stack, ip_sym);
        getch();
        exit(0);
    }

    if (!flag)
    {
        printf("\n %s\t\t\t%s\t\t reject", stack, ip_sym);
        getch();
        exit(0);
    }
}
