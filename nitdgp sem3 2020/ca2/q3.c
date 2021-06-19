//  assignment CA2 for CSC303
// Submitted by Arnab Bhakta 19CS8121
// 3. Write a C program to implement a
// priority queue using array that support
// insert and remove the maximum as efficiently as possible.

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue Queue;

// for colors
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

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q; // array with dynamic size
};

void create(Queue *q, int size)
{

    printYellow("\nAttempting to creatd Queue......");
    q->size = size;
    q->front = q->rear = -1;
    // dynamiccaly allocating array size
    q->Q = (int *)malloc(q->size * sizeof(int));
    printGreen("Queue successfully created.\n");
}

void priority_queue(Queue *q, int item)
{
    int pos;
    if (q->rear == q->size - 1)
        printf("Queue is full !");
    else
    {
        pos = q->rear;
        q->rear++;
        while (pos >= 0 && q->Q[pos] <= item)
        {
            q->Q[pos + 1] = q->Q[pos];
            pos--;
        }
        q->Q[pos + 1] = item;
    }
}

int dequeue(Queue *q)
{
    printYellow("Attempting deQueu an element from Queue");
    int x = -1;
    if (q->front == q->rear)
        printError("queue is empty");
    else
    {

        q->front++;
        x = q->Q[q->front];
    }
    printGreen("Successfully deQueued");
    return x;
}

void Dispaly(Queue q)
{
    printYellow("\nAttempting to diplay Queue elements");
    int i;
    for (i = q.front + 1; i <= q.rear; i++)
    {
        printf("%d ", q.Q[i]);
    }
    printGreen("\nAll elements of Queue successfully printed.\n");
}

int main()
{
    int n, v, i;
    printf("\nEnter number of elements : ");
    scanf("%d", &n);
    Queue q;
    create(&q, n);
    printYellow("Add elemts to Queue : ");
    for (i = 0; i < n; i++)
    {
        printf("Enter value : ");
        scanf("%d", &v);
        priority_queue(&q, v);
    }
    printGreen("All elements successfully added.");
    Dispaly(q);
    printf("\nDequed value is %d \n", dequeue(&q));
    Dispaly(q);

    return 0;
}