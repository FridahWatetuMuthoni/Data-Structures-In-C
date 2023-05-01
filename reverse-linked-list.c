// Reserving a linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node_t;

node_t *head;

void insert(int x);
void print();
void reverse();

int main(void)
{
    int n = 3;
    head = NULL;
    insert(2);
    insert(4);
    insert(6);
    insert(5);
    print();
    return (0);
}

void print()
{
    node_t *temp;
    temp = head;

    printf("The list is: ");
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert(int x)
{
    node_t *node;

    node = malloc(sizeof(node_t));
    if (node == NULL)
        return;

    node->data = x;
    node->next = head;

    head = node;
}

void reverse()
{
    node_t *current, *previous, *next;

    current = head;
    previous = NULL;

    while (current)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
}