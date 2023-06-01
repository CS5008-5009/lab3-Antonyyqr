#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

int searchElement(int element) {
    struct Node* current = head;
    int position = 1;
    int found = 0;

    while (current != NULL) {
        if (current->value == element) {
            found = 1;
            break;
        }
        position++;
        current = current->next;
    }

    if (found) {
        printf("Element %d found at position %d\n", element, position);
    } else {
        printf("Element %d not found\n", element);
    }
}

void insertElement(int element, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = element;

    if (position == 1) {
        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL) {
            head->prev = newNode;
        }

        head = newNode;
    } else {
        struct Node* current = head;
        int count = 1;

        while (count < position - 1 && current != NULL) {
            current = current->next;
            count++;
        }

        if (current == NULL) {
            printf("Invalid position\n");
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL) {
            current->next->prev = newNode;
        }

        current->next = newNode;
    }
}

void deleteElement(int element) {
    struct Node* current = head;
    int found = 0;

    while (current != NULL) {
        if (current->value == element) {
            found = 1;
            break;
        }
        current = current->next;
    }

    if (found) {
        if (current->prev == NULL) {
            head = current->next;

            if (head != NULL) {
                head->prev = NULL;
            }
        } else {
            current->prev->next = current->next;

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
        }

        free(current);
        printf("Element %d deleted from the list\n", element);
    } else {
        printf("Element %d not found\n", element);
    }
}

void printReverseList() {
    struct Node* current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    printf("Reverse order: ");

    while (current != NULL) {
        printf("%d ", current->value);
        current = current->prev;
    }

    printf("\n");
}

int main() {
    // Inserting elements into the linked list
    insertElement(23, 1);
    insertElement(52, 2);
    insertElement(19, 3);
    insertElement(9, 4);
    insertElement(100, 5);

    // Printing the linked list
    printf("Original linked list: ");
    struct Node* current = head;

    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");

    // Searching for an element in the linked list
    int searchElementValue;
    printf("Enter the element to search: ");
    scanf("%d", &searchElementValue);
    searchElement(searchElementValue);

    // Inserting an element in the middle of the linked list
    int insertElementValue, insertPosition;
    printf("Enter the element to insert: ");
    scanf("%d", &insertElementValue);
    printf("Enter the position to insert: ");
    scanf("%d", &insertPosition);
    insertElement(insertElementValue, insertPosition);
    printf("After insertion: ");
    current = head;

    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");

    // Inserting an element at the head of the linked list
    printf("Enter the element to insert at the head: ");
    scanf("%d", &insertElementValue);
    insertElement(insertElementValue, 1);
    printf("After insertion at the head: ");
    current = head;

    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");

    // Inserting an element at the end of the linked list
    printf("Enter the element to insert at the end: ");
    scanf("%d", &insertElementValue);
    insertElement(insertElementValue, 8);
    printf("After insertion at the end: ");
    current = head;

    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");

    // Deleting an element from the linked list
    int deleteElementValue;
    printf("Enter the element to delete: ");
    scanf("%d", &deleteElementValue);
    deleteElement(deleteElementValue);
    printf("After deletion: ");
    current = head;

    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");

    // Printing the linked list in reverse order
    printf("Printing in reverse order: ");
    printReverseList();

    return 0;
}
