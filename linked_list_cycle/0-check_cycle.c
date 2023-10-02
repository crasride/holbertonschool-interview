#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @head: pointer to the head of the linked list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *head)
{
    listint_t *current = head;
    listint_t *current_fast = head;

    while (current && current_fast && current_fast->next)
    {
        /* Move the current pointer one step at a time */
        current = current->next;

        /* Move the current_fast pointer two steps at a time */
        current_fast = current_fast->next->next;

        /* If the current and current_fast pointers meet, there is a cycle */
        if (current == current_fast)
            return (1);
    }

    /* If we reach the end of the list, there is no cycle */
    return (0);
}


