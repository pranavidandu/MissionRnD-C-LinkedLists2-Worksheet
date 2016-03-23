/*

Use MainLinkedLists2 File for testing any other function in other Cpp files of the Strings Project.

DO NOT write main function in any other File or else your Build Fails.

Objectives of LinkedLists2 Lesson:

->Merging two Linked Lists
->Reversing a LinkedList
->Inserting at a specific index 

*/
#include <stdio.h>
#include "FunctionHeadersLinkedLists2.h"
#include <malloc.h>
struct node {
	int num;
	struct node *next;
};
struct node * createNode(int num) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;
	return newNode;
}

struct node * createList(int num) {
	struct node *head = createNode(num % 10);
	num /= 10;
	while (num) {
		struct node *newNode = createNode(num % 10);
		newNode->next = head;
		head = newNode;
		num /= 10;
	}
	return head;
}
int main(){

	//Test InsertAtEveryKthNode
	/*struct node *head = createList(298);
	printf("im in main\n");
	struct node *ptr = head;
	while (ptr != NULL){
		printf("%d->", ptr->num);
		ptr = ptr->next;
	}
	head = insertAtEveryKthNode(head, 1);
	ptr = head;
	while (ptr != NULL){
		printf("%d->", ptr->num);
		ptr = ptr->next;
	}*/
	//Test LinkedListMedian
	//int n = linkedListMedian(createList(345));
	//printf("median %d\n", n);
	//Test merge2 LinkedLists
	/*struct node *head = merge2LinkedLists(createList(246), createList(135));
	struct node *ptr = head;
	while (ptr != NULL){
		printf("%d->", ptr->num);
		ptr = ptr->next;
	}*/
	//Test reverse LinkedList
	struct node *head = reverseLinkedList(createList(908234));
	struct node *ptr = head;
	while (ptr != NULL){
		printf("%d->", ptr->num);
		ptr = ptr->next;
	}
	return 0;
}