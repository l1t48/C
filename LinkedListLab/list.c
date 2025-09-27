#include "list.h"
#include "node.h"

int ListSize(node* head) {
    int size = 0;
    const node* current = head;

    while (current != NULL) {
        size++;
        current = current->next;
    }

    return size;
}

void BubbleSort(node** head) {
    int swapped;
    node* ptr1;
    node* lptr = NULL;

    if (*head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            if (ptr1->el > ptr1->next->el) {
                // Swap the nodes
                int temp = ptr1->el;
                ptr1->el = ptr1->next->el;
                ptr1->next->el = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int isListEmpty(node* head) { //Kolla om listan är töm.
    return (head == NULL);
}

void freeList(node* head) { //Töma listan.
    while (head != NULL) {
        node* temp = head;
        head = head->next;
        free(temp);
    }
    
}

// Function to return the element at a specific position in the linked list
int getElementAtPosition(node* head, int position) {
    if (head == NULL) {
        // List is empty
        ItIsEmpty();
    }

    int index = 0;
    node* current = head;

    while (current != NULL) {
        if (index == position) {
            return current->el;
        }

        current = current->next;
        index++;
    }

    // If the specified position is out of bounds
    //printf("Position %d is out of bounds in the list.\n", position);
}

// Funktion för att avgöra om ett element finns i den länkade listan
int elementExists(node* head, int target) {
    node* current = head;
    
    while (current != NULL) {
        if (current->el == target) {
            return 1; // Elementet finns i listan
        }
        current = current->next;
    }
    
    return 0; // Elementet hittades inte i listan
}

// Funktion för att hitta platsen för den första förekomsten av ett visst element
int findFirstOccurrence(node* head, int target) {
    int index = 0;
    node* current = head;

    while (current != NULL) {
        if (current->el == target) {
            return index; // Returnera platsen om elementet hittas
        }

        current = current->next;
        index++;
    }

    return -1; // Returnera -1 om elementet inte hittas
}
// Function to add an element at a specific position in the linked list
void addElementAtPosition(node** head, int element, int position) {
    if (position < 0) {
        // Position is negative, do nothing
        SkrivEttMeddelande("Negative position is not allowed.\n");
        return;
    }

    // Create a new node with the element
    node* newNode = (node*)malloc(sizeof(node));
    newNode->el = element;
    newNode->next = NULL;

    // If position is 0, insert at the beginning
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Traverse the list to find the node before the specified position
    node* current = *head;
    int index = 0;

    while (current != NULL && index < position - 1) {
        current = current->next;
        index++;
    }

    if (current == NULL) {
        // Handle an invalid position
        SkrivEttMeddelande("Invalid position.\n");
        free(newNode); // Free the memory of the new node
    } else {
        // Insert the new node in between
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to remove an element at a specific position in the linked list
void removeElementAtPosition(node** head, int position) {
    if (*head == NULL) {
        SkrivEttMeddelande("Listan är töm.\n");
        return;
    }

    int elementToRemove = getElementAtPosition(*head, position);

    if (!elementExists(*head, elementToRemove)) {
        SkrivEttMeddelande("Elementet i önskade positionen finns inte\n");
        return;
    }

    // If we reach this point, the element exists and can be removed.

    if (position == 0) {
        // Remove the element at the beginning
        node* temp = *head;
        *head = (*head)->next;
        free(temp);
    } else {
        // Find the node before the specified position
        int index = 0;
        node* current = *head;
        while (index < position - 1 && current->next != NULL) {
            current = current->next;
            index++;
        }

        if (index != position - 1 || current->next == NULL) {
            // The specified position is out of bounds
            SkrivEttMeddelande("Ogiltig position,\n");
            return;
        }

        // Remove the element at the specified position
        node* temp = current->next;
        current->next = temp->next;
        free(temp);
    }
}


// Function to remove the first occurrence of a given integer from the linked list
void removeElement(node** head, int target) {
    node* current = *head;
    node* prev = NULL;

    while (current != NULL) {
        if (current->el == target) {
            // Found the target integer, remove it from the list
            if (prev == NULL) {
                // If the target is in the first node
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current); // Free the memory
            SkrivEttMeddelande("Önskade talet togs bort.\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    SkrivEttMeddelande("Talet finns ej.\n");
}
