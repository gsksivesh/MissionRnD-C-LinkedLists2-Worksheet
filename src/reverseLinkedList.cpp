/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverse(struct node *head, struct node *rhead)
{
	if (head->next->next == NULL)
	{
		rhead = head->next;
		head->next->next = head;
		return rhead;
	}
	else if (head->next->next != NULL)
	{
		rhead = reverse(head->next, rhead);
		head->next->next = head;
	}
	return rhead;
}
struct node * reverseLinkedList(struct node *head) {
	struct node *rhead = NULL;
	if (head == NULL)
	{
		return NULL;
	}
	if (head->next == NULL)
		return head;
	rhead = reverse(head, rhead);
	head->next = NULL;
	return rhead;
}
