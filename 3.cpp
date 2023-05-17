#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 200

int arr[MAX_SIZE];

typedef struct alfa* alfaptr;

struct alfa {
    long long x;
    alfaptr next;
};

alfaptr rear = NULL, front = NULL;

void push(int x)
{
    alfaptr node;
    node = (alfaptr)malloc(sizeof(struct alfa));
    node->x = x;
    if (!front)
        front = node;
    else {
        rear->next = node;
        rear = node;
    }
}

void pop()
{
    if (!front)
    {
        printf("List is empty\n");
        return;
    }
    alfaptr node = front;
    front = front->next;
    free(node);
}

void search(int x)
{
    alfaptr node = front;
    int counter = 0;
    while (node)
    {
        if (node->x == x)
        {
            printf("%d\n", counter);
            return;
        }
        node = node->next;
        counter++;
    }
    printf("Element not found\n");
}

void rpop() // pop last element
{
    if (!front)
    {
        printf("List is empty\n");
        return;
    }
    alfaptr node = front;
    if (!node->next)
    {
        front = NULL;
        rear = NULL;
        free(node);
        return;
    }
    while (node->next != rear)
        node = node->next;
    rear = node;
    node = node->next;
    rear->next = NULL;
    free(node);
}

void set()
{
    alfaptr node = front;
    for (int i = 0; i < MAX_SIZE && node; i++, node = node->next)
        arr[i] = node->x;
}

int size()
{
    alfaptr node = front;
    int count = 0;
    for (; node; count++, node = node->next);
    return count;
}

void show()
{
    if (!front)
    {
        printf("List is empty\n");
        return;
    }
    alfaptr node = front;
    while (node)
    {
        printf("%lld ", node->x);
        node = node->next;
    }
    printf("\n");
}

int average()
{
    if (!front)
    {
        printf("List is empty\n");
        return 0;
    }
    alfaptr node = front;
    int sum = 0, count = 0;
    while (node)
    {
        sum += node->x;
        count++;
        node = node->next;
    }
    return sum / count;
}

int main()
{
    int cmd;
    long long int x;
    while (1)
    {
        scanf("%d", &cmd);
        switch (cmd)
        {
        case 0:
            return 0;
        case 1:
            scanf("%lld", &x);
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            scanf("%lld", &x);
            search(x);
            break;
        case 4:
            set();
            break;
        case 5:
            printf("%d\n", size());
            break;
        case 6:
            show();
            break;
        case 7:
            printf("%d\n", average());
            break;
        case 8:
            rpop();
            break;
        default:
            printf("Invalid command\n");
            break;
        }
    }
    return 0;
}

//خطا در تعریف متغیر count:
//مشکل در تابع search:
//مشکل در تابع rpop:
//مشکل در تابع show:
//مشکل در تابع average:
//مشکل در تابع main:
//خطای size:
//