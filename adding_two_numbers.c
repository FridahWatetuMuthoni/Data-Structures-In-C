#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *head = NULL;

void create_linked_list(int val)
{
    struct ListNode *node, *last;

    // creating a new node
    node = malloc(sizeof(struct ListNode));

    if (node == NULL)
        return;

    node->val = val;
    node->next = head;
    head = node;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *temp;
    int sum, curry, reminder;

    // travessing both linked lists
    while (l1 && l2)
    {
        sum = curry + l1->val + l2->val;
        reminder = sum % 10;
        curry = sum / 10;
        create_linked_list(reminder);
        l1 = l1->next;
        l2 = l2->next;
    }

    temp = (l1 == NULL ? l1 : l2);
    while (temp)
    {
        sum = curry + temp->val;
        reminder = sum % 10;
        curry = sum / 10;
        create_linked_list(reminder);
        temp = temp->next;
    }
    return (head);
}

int main()
{

    struct ListNode a, b, *result;

    a.val = 3;
    a.next = NULL;

    b.val = 9;
    b.next = NULL;

    result = addTwoNumbers(&a, &b);

    return 0;
}