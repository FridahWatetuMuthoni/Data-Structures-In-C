#include <stdio.h>
#include <stdlib.h>

/*
node_t insert(node_t **head, int x);
we are using **head beacuse this is a pointer to a pointer because we passed
the address to the head pointer as the arguement to insert
node_t *head = NULL;
int num = 20;
insert(&head, num); //therefore head is a pointer to a pointer
*/

typedef struct Node
{
    int data;
    struct Node *next;
} node_t;

// creating the header of the linked list
node_t *head;

void inserting_end(int x);
void inserting_start(int x);
void inserting_at_n_position(int x, int position);
void print_list();
void reversing_list();

int main(void)
{
    int numbers, i, num;

    head = NULL;

    printf("How many numbers?\n");
    scanf("%d", &numbers);
    for (i = 0; i < numbers; i++)
    {
        printf("Enter the number:  \n");
        scanf("%d", &num);
        inserting_start(num);
        print_list();
    }

    return (0);
}

void print_list()
{
    node_t *temp = head;
    printf("List is : ");
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void inserting_start(int x)
{
    // creating a new node
    node_t *node;

    node = malloc(sizeof(node_t));
    if (node == NULL)
        return;

    node->data = x;
    node->next = head;

    head = node;
}
