#include <stdio.h>
#include <stdlib.h>

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

    new_node->val = val;
    new_node->next = NULL;

    indirect = head;
    while (*indirect) {
        indirect = &((*indirect)->next);
    }

    *indirect = new_node;
}

void list_remove(node_t **head, int val)
{
    node_t **indirect;

    if (!head)
        return;

    indirect = head;
    while (*indirect && (*indirect)->val != val) {
        indirect = &((*indirect)->next);
    }

    if (*indirect) {
        *indirect = (*indirect)->next;
    }
}

/* Insert a new val before the specific val. */
void list_insert(node_t **head, int new_val, int val)
{
    node_t *new_node, **indirect;

    if (!head)
        return;

    new_node = (node_t *)malloc(sizeof(node_t));
    if (!new_node)
        return;

    new_node->val = new_val;
    new_node->next = NULL;

    indirect = head;
    while (*indirect && (*indirect)->val != val) {
        indirect = &((*indirect)->next);
    }

    if (*indirect) {
        new_node->next = *indirect;
        *indirect = new_node;
    }
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
    node_t **head;

    head = (node_t **)malloc(sizeof(node_t *));
    if (!head)
        return -1;

    printf("* Append 1, 2, 3\n");
    list_append(head, 1);
    list_append(head, 2);
    list_append(head, 3);
    list_print(*head);

    printf("* Remove 2\n");
    list_remove(head, 2);
    list_print(*head);
    printf("* Remove 3\n");
    list_remove(head, 3);
    list_print(*head);
    printf("* Remove 4\n");
    list_remove(head, 4);
    list_print(*head);
    printf("* Remove 1\n");
    list_remove(head, 1);
    list_print(*head);

    printf("* Append 1, 2, 3\n");
    list_append(head, 1);
    list_append(head, 2);
    list_append(head, 3);
    list_print(*head);

    printf("* Insert 5 before 3\n");
    list_insert(head, 5, 3);
    list_print(*head);

    printf("* Insert 6 before 1\n");
    list_insert(head, 6, 1);
    list_print(*head);

    printf("* Insert 7 before 5\n");
    list_insert(head, 7, 5);
    list_print(*head);

    printf("* Insert 8 before 9\n");
    list_insert(head, 8, 9);
    list_print(*head);

    free(head);

    return 0;
}
