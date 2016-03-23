/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head == NULL || K < 1)
		return NULL;
	struct node *ptr = head;//creating a temporary pointer
	int pos = 1;
	struct node* cur;
	while (ptr -> next != NULL){
		if (pos++ % K == 0){
			cur = (struct node*) malloc(sizeof(struct node));
			cur->num = K;
			cur->next = ptr->next;
			ptr->next = cur;
			ptr = ptr->next->next;
		}
		else{
			ptr = ptr->next;
		}
	}
	if (pos % K == 0){//if K node is to placed at the end of the list
		cur = (struct node*) malloc(sizeof(struct node));
		cur->num = K;
		cur->next = NULL;
		ptr->next = cur;
	}
	return head;
}
