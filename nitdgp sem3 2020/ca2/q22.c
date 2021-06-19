#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void red()
{
    printf("\033[0;31m");
}

void yellow()
{
    printf("\033[0;33m");
}

void green()
{
    printf("\033[1;32m");
}

void blue()
{
    printf("\033[1;33m");
}

void reset()
{
    printf("\033[0m");
}

void printError(char s[])
{
    red();
    puts(s);
    reset();
}

void printYellow(char s[])
{
    yellow();
    puts(s);
    reset();
}

void printGreen(char s[])
{
    green();
    puts(s);
    reset();
}

typedef struct stack stack;

struct stack
{
    int top, size;
    char *items;
};

void create(stack *new_stack, int size)
{
    new_stack->size = size;
    new_stack->top = -1;
    new_stack->items = (char *)malloc(size * sizeof(char));
}

void push(stack *s, int value)
{
    if (s->top == (s->size - 1))
    {
        printError("\nStack overflow !!!!!");
        exit(1);
    }

    s->items[++s->top] = value;
}
int isEmpty(stack *s)
{
    return s->top == -1;
}
void display(stack *s)
{
    int i;
    printYellow("\nAttmpting to print stack contents......");
    if (isEmpty(s))
    {
        printError("\nStack underflow !!!!");
        exit(1);
    }
    for (i = 0; i < s->top; i++)
        printf("%c ", s->items[i]);
    printGreen("\nPrinting of stack contents done.");
}
int pop(stack *s)
{
    if (isEmpty(s))
    {
        printError("Stack underflow !!!!");
        exit(1);
    }
    return s->items[s->top--];
}
void main()
{
    char exp[10] = "7+2*3-4";
    int i;
    stack s, *s1;
    s1 = &s;
    create(s1, 10);

    if (exp[0] != '(')
        push(s1, '(');

    for (i = 0; i <= 7; i++)
    {

        if (i == 7)
            push(s1, ')');
        else
        {
            printf("\ngot char %c", exp[i]);
            push(s1, exp[i]);
        }
    }
    if (exp[0] != ')')
        push(s1, ')');
    display(s1);
    // if (exp[0] == '(')
    //     exp = '(' + exp + ')';
    // strcpy(exp, "arnab");
    // printf("%s", exp);
}