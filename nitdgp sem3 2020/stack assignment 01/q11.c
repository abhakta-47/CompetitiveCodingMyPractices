#include <stdio.h>

#define STACKSIZE 100
struct list
{
    int top;
    int items[STACKSIZE];
};
typedef struct list stack;
stack s;

void create(stack *s)
{
    s->top = -1;
    /* s->top points to
last element
pushed in;
initially -1 */
}

void push(stack *ps, int value)
{
    if (ps->top == (STACKSIZE - 1))
    {
        printf("\n Stack overflow");
        exit(1);
    }
    else
    {
        ps->top++;
        ps->items[s->top] = value;
    }
}

int pop(stack *ps)
{
    if (s->top == -1)
    {
        printf("\n Stack underflow");
        exit(1);
    }
    else
    {
        return (ps->items[s->top--]);
    }
}

void main()
{
    int input;
    create(&s);
    while (input != 0)
    {
        printf("\nEnter 1 to push an element.\nEnter 2 to pop an element.\nEnter 0 to exit.\n");
        scanf("%d", &input);
        if (input == 1)
        {
            printf("Enter value to push : ");
            scanf("%d", &input);
            push(&s, input);
            input = 1;
        }
        else if (input == 2)
        {
            printf("Popped value : ");
            pop(&s);
        }
        else
            break;
    }
}