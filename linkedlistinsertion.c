// A complete working C program to demonstrate 
// all insertion methods on Linked List
#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node
{
int data;
struct Node *next;
};

// Given a reference (pointer to pointer) to 
// the head of a list and an int, inserts a 
// new node on the front of the list. 
void push(struct Node** head_ref, 
		int new_data)
{
	// 1. Allocate node 
	struct Node* new_node = 
		(struct Node*) malloc(sizeof(struct Node));

	// 2. Put in the data 
	new_node->data = new_data;

	// 3. Make next of new node as head 
	new_node->next = (*head_ref);

	// 4. move the head to point to 
	// the new node 
	(*head_ref) = new_node;
}

// Given a node prev_node, insert a 
// new node after the given prev_node 
void insertAfter(struct Node* prev_node, 
				int new_data)
{
	// 1. Check if the given prev_node 
	// is NULL 
	if (prev_node == NULL)
	{
	printf("the given previous node cannot be NULL");
	return;
	}

	// 2. Allocate new node 
	struct Node* new_node =
		(struct Node*) malloc(sizeof(struct Node));

	// 3. Put in the data 
	new_node->data = new_data;

	// 4. Make next of new node as next 
	// of prev_node 
	new_node->next = prev_node->next;

	// 5. Move the next of prev_node 
	// as new_node 
	prev_node->next = new_node;
}

// Given a reference (pointer to pointer) to 
// the head of a list and an int, appends a 
// new node at the end 
void append(struct Node** head_ref, 
			int new_data)
{
	// 1. Allocate node 
	struct Node* new_node = 
		(struct Node*) malloc(sizeof(struct Node));

	// Used in step 5
	struct Node *last = *head_ref; 

	// 2. Put in the data 
	new_node->data = new_data;

	// 3. This new node is going to be the 
	// last node, so make next of it as NULL
	new_node->next = NULL;

	// 4. If the Linked List is empty, then make 
	// the new node as head 
	if (*head_ref == NULL)
	{
	*head_ref = new_node;
	return;
	}

	// 5. Else traverse till the last node 
	while (last->next != NULL)
		last = last->next;

	// 6. Change the next of last node 
	last->next = new_node;
	return;
}

// This function prints contents of the 
// linked list starting from head
void printList(struct Node *node)
{
while (node != NULL)
{
	printf(" %d ", node->data);
	node = node->next;
}
}

// Driver code
int main()
{
// Start with the empty list 
struct Node* head = NULL;

// Insert 6. So linked list 
// becomes 6->NULL
append(&head, 6);

// Insert 7 at the beginning. 
// So linked list becomes 7->6->NULL
push(&head, 7);

// Insert 1 at the beginning. So 
// linked list becomes 1->7->6->NULL
push(&head, 1);

// Insert 4 at the end. So linked list 
// becomes 1->7->6->4->NULL
append(&head, 4);

// Insert 8, after 7. So linked list 
// becomes 1->7->8->6->4->NULL
insertAfter(head->next, 8);

printf("Created Linked list is: ");
printList(head);

return 0;
}
