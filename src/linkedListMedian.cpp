/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if (head == NULL)
		return -1;
	struct node *ptr1 = head, *ptr2 = head;
	while (1){
		if (ptr2 == NULL || ptr2->next == NULL)//odd length
			return ptr1->num;
		if (ptr2->next->next == NULL){
			return (ptr1->num + ptr1->next->num) / 2;//even length
		}
		ptr1 = ptr1->next;//traversing one node at a time
		ptr2 = ptr2->next->next;//traversing alternate node at a time
	}

}