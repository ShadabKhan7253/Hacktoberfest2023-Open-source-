#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define QS 5
#define INF -32768

struct Queue
{
    int items[QS];
    int front, rear;
};

int isFull(struct Queue q)
{
    if (q.rear == QS - 1)
        return 1;
    return 0;
}

int isEmpty(struct Queue q)
{
    if (q.front > q.rear)
        return 1;
    return 0;
}

void insert(struct Queue *pq, int element)
{
    if (isFull(*pq))
        printf("\nQueue Overflow, cannot insert!\n");
    else
    {
        //pq->rear++
        //pq->items[pq->rear]=element;

        pq->items[++pq->rear] = element;
    }
}

int Remove(struct Queue *pq)
{
    if (isEmpty(*pq))
    {
        printf("\nQueue Underflow, cannot remove!\n");
        return INF;
    }
    else
    {
        //temp=pq->items[pq->front];
        //pq->front++;
        //return temp;

        return pq->items[pq->front++];
    }
}

// int modifyRemove(struct Queue *pq)
// {
//     int temp;
//     if (isEmpty(*pq))
//     {
//         printf("\nQueue Underflow, cannot remove!");
//         return INF;
//     }
//     temp = pq->items[pq->front];
//     pq->front++;

//     if (isEmpty(*pq))
//     {
//         pq->front = 0;
//         pq->rear = -1;
//     }
//     return temp;
// }

void show(struct Queue q)
{
    int i;
    if (isEmpty(q))
        printf("\nNothing to show as Queue is Empty\n");
    else
    {
        printf("\nQueue Elements: ");
        for (i = q.front; i <= q.rear; i++)
            printf("%d ", q.items[i]);
    }
}

void main()
{
    int ch, element;
    struct Queue q;
    q.front = 0;
    q.rear = -1;

    while (1)
    {
        printf("\n------------------Menu------------------");
        printf("\n1. Insert \n2. Remove \n3. Show \n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter element to be inserted: ");
            scanf("%d", &element);
            insert(&q, element);
            break;

        case 2:
            element = Remove(&q);
            printf("\nRemove element: %d", element);
            break;

        case 3:
            show(q);
            break;

        case 4:
            exit(0);
            break;
        }
    }
}
