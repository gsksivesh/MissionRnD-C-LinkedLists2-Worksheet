/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	struct node *temp1, *temp2, *temp;
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	temp1 = head1;
	temp2 = head2;
	while (temp1 != NULL && temp2 != NULL)
	{
		if (temp1->next != NULL && temp2->num >= temp1->num && temp2->num <= temp1->next->num)
		{
			temp = temp1->next;
			temp1->next = temp2;
			temp1 = temp2;
			temp2 = temp;
		}
		else if (temp2->next != NULL && temp1->num >= temp2->num && temp1->num <= temp2->next->num)
		{
			temp = temp2->next;
			temp2->next = temp1;
			temp2 = temp;
		}
		else if (temp2->num >= temp1->num && temp1->next == NULL)
		{
			temp1->next = temp2;
			temp1 = NULL;
		}
		else if (temp1->num >= temp2->num && temp2->next == NULL)
		{
			temp2->next = temp1;
			temp2 = NULL;
		}
		else if (temp2->num > temp1->num)
		{
			temp1 = temp1->next;
		}
		else if (temp1->num > temp2->num)
		{
			temp2 = temp2->next;
		}
	}
	if (head1->num <= head2->num)
		return head1;
	else
		return head2;;
}
