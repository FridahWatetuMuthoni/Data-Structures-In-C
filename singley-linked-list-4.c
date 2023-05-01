// Delete a node an given position in a linked list

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
void delete(int n);

int main(void)
{
    int n = 3;
    head = NULL;
    insert(2);
    insert(4);
    insert(6);
    insert(5);
    print();
    delete (n);
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

void delete(int n)
{
    node_t *temp, *temp2;
    int i;

    temp = head;

    if (n == 1)
    {
        head = temp->next; // head now points to the second node
        free(temp);
        return;
    }

    for (i = 0; i < n - 2; i++)
        temp = temp->next;

    // temp points to (n-1)th Node
    temp2 = temp->next;       // nth node
    temp->next = temp2->next; //(n+1)th node
    free(temp2);
}