// C program for array implementation of stack
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a stack
struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to add an item to stack. It increases top by 1
void push(struct Stack *stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack", item);
}

// Function to remove an item from stack. It decreases top by 1
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

// Function to return the top from stack without removing it
int peek(struct Stack *stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

void display(struct Stack *stack)
{
    int i;
    for (i = stack->top; i >= 0; i--)
        printf("%d\n", stack->array[i]);
}

// Driver program to test above functions
int main()
{
    int input;
    struct Stack *stack = createStack(100);

    printf("------------------------------------\n");
    printf("    STACK IMPLEMENTATION USING ARRAY PROGRAM    \n");
    printf("------------------------------------\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("0. Exit\n");
    printf("------------------------------------\n\n");

    while (input != 0)
    {
        printf("Enter choice : ");
        scanf("%d", &input);
        if (input == 1)
        {
            printf("Enter value to push : ");
            scanf("%d", &input);
            push(stack, input);
            input = 1;
        }
        else if (input == 2)
        {
            printf("Popped value : ");
            printf("%d", pop(stack));
        }
        else if (input == 3)
        {
            printf("Displaying contents : \n");
            display(stack);
        }
        else if (input == 0)
            break;
        else
            printf("Enter correct input.");
        printf("\n");
    }

    return 0;
}
