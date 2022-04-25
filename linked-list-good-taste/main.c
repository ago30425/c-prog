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

void list_print(node_t *head)
{
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

    /* Append numbers */
    list_append(head, 1);
    list_append(head, 2);
    list_append(head, 3);

    list_print(*head);

    free(head);

    return 0;
}
