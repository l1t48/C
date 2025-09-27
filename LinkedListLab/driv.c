#include "driv.h"
#include "list.h"
#include "node.h"

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        // Handle memory allocation failure
        return NULL;
    }
    newNode->el = data;
    newNode->next = NULL;
    return newNode;
}

void LäggTillISlutet(node** head, int data) {
    node* newNode = createNode(data);
    if (newNode != NULL) {
        if (*head == NULL) {
            *head = newNode;
        } else {
            node* current = *head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
}

void LäggTillEnHeltalIslutetAvListan(node** head) {
    int num;
    printf("Skriv in ett heltal: ");
    char input[MAX_SIZE];
    fgets(input, sizeof(input), stdin);
    
    if (sscanf(input, "%d", &num) == 1) {
        LäggTillISlutet(head, num);
    } else {
        printf("Ogiltig input. Ange ett heltal.\n");
    }
}


void SkiftaListanEttStegÅtVänster(node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        // The list is empty or has only one element, no need to shift
        return;
    }

    node* current = *head;
    node* newHead = current->next;

    // Traverse the list to find the last node
    while (current->next != NULL) {
        current = current->next;
    }

    // Make the last node point to the current head
    current->next = *head;

    // Update the head pointer to the new head
    *head = newHead;

    // Set the next pointer of the old head to NULL to make it the new tail
    current->next->next = NULL;
}


void SkiftaListanEttStegÅtHöger(node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        // The list is empty or has only one element, no need to shift
        return;
    }

    node* current = *head;
    node* prev = NULL;

    // Traverse the list to find the last two nodes
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    // Make the last node the new head
    prev->next = NULL;
    current->next = *head;
    *head = current;
}


void VändPåListan(node** head) {
    node* prev = NULL;
    node* current = *head;
    node* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    // Update the head to the new first node
    *head = prev;
}


char* TaAnvändarensInput(const char* prompt) {
    static char input_in_char[MAX_SIZE]; // Static to preserve data between function calls
    printf("%s", prompt);
    fgets(input_in_char, MAX_SIZE, stdin);
    // Remove the newline character if present
    size_t len = strlen(input_in_char);
    if (len > 0 && input_in_char[len - 1] == '\n') {
        input_in_char[len - 1] = '\0'; // Replace '\n' with '\0'
    }
    return input_in_char;
}


char* SkrivEttMeddelande(const char* prompt) {
    printf("%s", prompt);
}


void SkrivUtListan(node* head) {
    node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->el);
        current = current->next;
    }
}


void SkrivListSize(node* head) {
    printf("List storleken är: %d", ListSize(head));
}

void SkrivBaseAddress(const node* head) {
    printf("Base adressen är %p\n", (void*)head);
}

void ItIsEmpty(){
    printf("Listan är redan töm!");
}

void SkrivUtMeneyn(){
    printf("0. Avsluta\n");
    printf("1. Skriv ut listan\n");
    printf("2. Skriv ut listan storlek\n");
    printf("3. Lägg till ett heltal sist i listan\n");
    printf("4. Lägg till ett heltal (valfri plats)\n");
    printf("5. Ta bort ett givet heltal\n");
    printf("6. Ta bort ett heltal (valfri plats)\n");
    printf("7. Töm listan\n");
    printf("8. Vänd på listan\n");
    printf("9. Skifta listan ett steg åt vänster (och lägg första heltal sist)\n");
    printf("10. Skifta listan ett steg åt höger (och lägg sista heltal först)\n");
    printf("11. Sortera listan (längsta heltal först)\n");
    printf("12. Skriv ut startadress för listan\n");
}


void SkrivUtMeneynMedError(){
    printf("Ogiltigt val. Ange en siffra mellan 0 och 12.\n");
    SkrivUtMeneyn();
}

