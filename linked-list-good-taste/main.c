#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int val;
    struct node *next;
} node_t;

void list_append(node_t **head, int val)
{
    node_t *new_node, **indirect;

    if (!head)
        return;

    new_node = (node_t *)malloc(sizeof(node_t));
    if (!new_node)
        return;

    memset(new_node, 0, sizeof(node_t));
    new_node->val = val;

    indirect = head;
    while (*indirect) {
        indirect = &((*indirect)->next);
    }

    *indirect = new_node;
}

void list_remove(node_t **head, int val)
{
    node_t **indirect;

    indirect = head;
    while (*indirect && (*indirect)->val != val) {
        indirect = &(*indirect)->next;
    }

    if (*indirect) {
        node_t *tmp = *indirect;

        *indirect = (*indirect)->next;
        free(tmp);
    }
}

/* Insert a new node and make the list in ascending order. */
void list_insert(node_t **head, int val)
{
    node_t *new_node, **indirect;

    if (!head)
        return;

    new_node = (node_t *)malloc(sizeof(node_t));
    if (!new_node)
        return;

    memset(new_node, 0, sizeof(node_t));
    new_node->val = val;

    indirect = head;
    while (*indirect && (*indirect)->val < val) {
        indirect = &(*indirect)->next;
    }

    new_node->next = *indirect;
    *indirect = new_node;
}

void list_print(node_t *head)
{
    if (!head) {
        printf("No any nodes\n");
        return;
    }

    while (head) {
        printf("%d ", head->val);

        if (head->next != NULL)
            printf("-> ");

        head = head->next;
    }

    printf("\n");
}

int main(void)
{
    node_t *head = NULL;

    printf("[Append 1, 2, 3]\n");
    list_append(&head, 1);
    list_append(&head, 2);
    list_append(&head, 3);
    list_print(head);

    printf("[Remove 2]\n");
    list_remove(&head, 2);
    list_print(head);
    printf("[Remove 3]\n");
    list_remove(&head, 3);
    list_print(head);
    printf("[Remove 4]\n");
    list_remove(&head, 4);
    list_print(head);
    printf("[Remove 1]\n");
    list_remove(&head, 1);
    list_print(head);

    printf("[Append 1, 2, 3]\n");
    list_append(&head, 1);
    list_append(&head, 2);
    list_append(&head, 3);
    list_print(head);

    printf("[Insert 7]\n");
    list_insert(&head, 7);
    list_print(head);

    printf("[Insert 4]\n");
    list_insert(&head, 4);
    list_print(head);

    printf("[Insert 5]\n");
    list_insert(&head, 5);
    list_print(head);

    printf("[Insert 8]\n");
    list_insert(&head, 8);
    list_print(head);

    return 0;
}
