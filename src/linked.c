#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int number;
	struct node* next;
} node;

node* init_node(int number, node* next) {
	node* anon_node;
	anon_node = malloc(sizeof(node)*1);

	anon_node->number = number;
	anon_node->next = next;

	return anon_node;
}


node* push_node(node* head, int num) {
	/*
	Adds a node to the end of the linkedlist
	*/
	node* next = init_node(num, NULL);

	node* temp = head;

	// get to the final node
	while (temp->next !=NULL) {
		temp = temp->next;
	}

	// append next to the former final node
	temp->next = next;
	return next;
}


void del_node(node* head, int index) {
	/*
	Deletes the n'th + 1 element of the linked list
	*/
	node* temp = head;
	for (int i = 0; i < index; i++) {
		temp = temp->next;
	}
	node* delete = temp->next;
	temp->next = temp->next->next;
	free(delete);
}

void printf_list(node* head) {
	/*
	Prints the element of the linkedlist to stdout
	*/
	node* temp = head;
	printf("number is %i\n", temp->number);
	while (temp->next != NULL) {
		temp = temp->next;
		printf("number is %i\n", temp->number);
	}
}

float sum_linked(node* head) {
	// recursive sum of linked nodes
	node* temp = head;
	if (temp->next == NULL) {
		return temp->number;
	}
	float result = 0;
	return temp->number + sum_linked(temp->next);
}

int main(int argc, char **argv) {
	node* head = init_node(0, NULL);
	node* second = push_node(head, 10);
	node* third  = push_node(head, 22);
	node* garbage = push_node(second, 34);
	del_node(head, 1);
	printf_list(head);

	printf("The sum of all our elements in the linkedlist is : %.2f\n",sum_linked(head));
	return 0;
}
