#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node_t;

node_t *head;

void inserting_at_n_position(int x, int position);
void print();

int main(void)
{
    head = NULL;
    inserting_at_n_position(2, 1);
    inserting_at_n_position(3, 2);
    inserting_at_n_position(4, 1);
    inserting_at_n_position(5, 2);
    print();
    return (0);
}

void print()
{
    node_t *temp;
    temp = head;
    printf("List is : ");
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void inserting_at_n_position(int x, int position)
{
    // creating a new node
    node_t *node, *temp;
    int i;

    node = malloc(sizeof(node_t));
    if (node == NULL)
        return;
    node->data = x;
    node->next = NULL;

    // connecting the new node to the linked list at a specific position
    // inserting at first position
    if (position == 1)
    {
        node->next = head;
        head = node;
        return;
    }

    /*We are using `position-2` in the `for` loop in the `inserting_at_n_position()`
    function because we want to stop the loop at the node immediately before the desired position in the list,
    so that we can insert the new node after that node.For example, if we want to insert a node at position `2`,
    we need to stop the loop at the first node, so that we can insert the new node after it.
    If we used `position-1` instead of `position-2`, we would be stopping the loop at the second node,
    which is not what we want.So, in general, if we want to insert a node at position `n`,
    we need to stop the loop at the node at position `n-1` in the list, which is why we use `position-2` in the loop.
    */

    temp = head;
    for (i = 0; i < position - 2; i++)
    {
        temp = temp->next;
    }
    node->next = temp->next;
    temp->next = node;
}