#include "node.h"
#include<stdlib.h>
 

int ListSize(node* head);

void BubbleSort(node** head);

void freeList(node* head);

int isListEmpty(node* head);

char* SkrivEttMeddelande(const char* prompt);

void removeElement(node** head, int target);

void ItIsEmpty(void);
