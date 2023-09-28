#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the Node structure
struct Node {
    char* data;
    struct Node* next;
};

// Define the LinkedList structure
struct Linkedlist {
    struct Node* head;
};

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Linkedlist* LL, char ele[]) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Allocate memory for data and copy the element
    newNode->data = (char*)malloc(strlen(ele) + 1);
    strcpy(newNode->data, ele);

    // Set the next pointer to the current head
    newNode->next = LL->head;

    // Update the head to point to the new node
    LL->head = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtTheEnd(struct Linkedlist* LL, char ele[]) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Allocate memory for data and copy the element
    newNode->data = (char*)malloc(strlen(ele) + 1);
    strcpy(newNode->data, ele);

    // Set the next pointer of the new node to NULL since it will be the last node
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (LL->head == NULL) {
        LL->head = newNode;
        return;
    }

    // Find the last node and update its next pointer to the new node
    struct Node* current = LL->head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

// Function to delete a node with a specific data value
void deleteNode(struct Linkedlist* LL, char ele[]) {
    if (LL->head == NULL) {
        return; // List is empty, nothing to delete
    }

    // If the head node contains the element to be deleted
    if (strcmp(LL->head->data, ele) == 0) {
        struct Node* temp = LL->head;
        LL->head = LL->head->next;
        free(temp->data);
        free(temp);
        return;
    }

    // Search for the node with the given data
    struct Node* current = LL->head;
    while (current->next != NULL && strcmp(current->next->data, ele) != 0) {
        current = current->next;
    }

    // If found, remove it from the list
    if (current->next != NULL) {
        struct Node* temp = current->next;
        current->next = current->next->next;
        free(temp->data);
        free(temp);
    }
}

// Function to find a node with a specific data value
int findNode(struct Linkedlist LL, char ele[]) {
    struct Node* current = LL.head;
    while (current != NULL) {
        if (strcmp(current->data, ele) == 0) {
            return 1; // Found
        }
        current = current->next;
    }
    return 0; // Not found
}

// Function to display the linked list
void displayLinkedList(struct Linkedlist LL) {
    struct Node* current = LL.head;
    while (current != NULL) {
        printf("%s, ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    // Check if there are arguments
    if (argc < 2) {
        printf("No arguments provided.\n");
        return 1;
    }

    // Declare and initialize the linked list
    struct Linkedlist LL;
    LL.head = NULL;

    // Process the arguments
    for (int i = 1; i < argc; i++) {
        char* arg = argv[i];
        // Check if the first character is uppercase
        if (isupper(arg[0])) {
            // Check if the element already exists in the list, and delete if it does
            if (findNode(LL, arg)) {
                deleteNode(&LL, arg);
                continue
            }
            // Insert at the beginning
            insertAtBeginning(&LL, arg);
        } else if (islower(arg[0])) {
            // Check if the element already exists in the list, and delete if it does
            if (findNode(LL, arg)) {
                deleteNode(&LL, arg);
                continue;
            }
            // Insert at the end
            insertAtTheEnd(&LL, arg);
        }
    }

    // Display the linked list
    displayLinkedList(LL);

    // Free memory
    struct Node* current = LL.head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }

    return 0;
}
