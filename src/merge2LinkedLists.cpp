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
	if (head1 == NULL && head2 == NULL)
		return NULL;
	if (head1 == NULL){
		return head2;
	}
	else if (head2 == NULL){
		return head1;
	}
	struct node *ptr1 = head1;
	struct node *ptr2 = head2;
	if (ptr1->num < ptr2->num){// if the condition head1 is the main pointer
		while (ptr1->next != NULL){
			if (ptr1->num <= ptr2->num && ptr1->next->num >= ptr2->num){
				head2 = ptr2->next;
				ptr2->next = ptr1->next;
				ptr1->next = ptr2;
				ptr1 = ptr1->next->next;
				ptr2 = head2;
			}
			else if (ptr1->num >= ptr2->num && ptr2->next->num <= ptr1->num){
				head2 = ptr2->next;
				ptr2->next = ptr1->next->next;
				ptr1->next->next = ptr2;
				ptr2 = ptr1->next->next;
				ptr2 = head2;

			}
			else{
				ptr1 = ptr1->next;
			}
		}
		if (ptr1->next == NULL){
			ptr1->next = head2;
		}
		return head1;
	}
	else{
		while (ptr2->next != NULL){
			if (ptr2->num <= ptr1->num && ptr2->next->num >= ptr1->num){
				head1 = ptr1->next;
				ptr1->next = ptr2->next;
				ptr2->next = ptr1;
				ptr2 = ptr2->next->next;
				ptr1 = head1;
			}
			else if (ptr2->num >= ptr1->num && ptr1->next->num <= ptr2->num){
				head1 = ptr1->next;
				ptr1->next = ptr2->next->next;
				ptr2->next->next = ptr1;
				ptr1 = ptr2->next->next;
				ptr1 = head1;

			}
			else{
				ptr2 = ptr2->next;
			}
		}
		if (ptr2->next == NULL){
			ptr2->next = head1;
		}
		return head2;
	}
}