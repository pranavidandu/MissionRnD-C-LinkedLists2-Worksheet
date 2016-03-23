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

struct node * reverseLinkedList(struct node *head) {
	if (head == NULL || head->next == NULL)
		return head;
	struct node* prev_ptr;
	struct node* next_ptr;
	struct node* temp_ptr;
	prev_ptr = head;
	next_ptr = head->next;
	head->next = NULL;
	while (next_ptr->next != NULL){
		temp_ptr = next_ptr->next;
		next_ptr->next = prev_ptr;
		prev_ptr = next_ptr;
		next_ptr = temp_ptr;
	}
	head = next_ptr;
	next_ptr->next = prev_ptr;
	return head;
	
}
