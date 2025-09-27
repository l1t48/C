#include "node.h" 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
#define MAX_SIZE 30

void freeList(node* head);

void SkrivUtMeneyn(void);

void SkrivUtMeneynMedError(void);

void PrintError(const char* errorMessage);

void VändPåListan(node** head);

void SkiftaListanEttStegÅtHöger(node** head) ;

void SkiftaListanEttStegÅtVänster(node** head);

void SkrivBaseAddress(const node* head);

void SkrivListSize(node* head);

void SkrivUtListan(struct nodeEl* head);

void LäggTillEnHeltalIslutetAvListan(node** head);

void LäggTillISlutet(node** head, int data) ;

void SkrivUtMeneynMedError(void);

void SkrivUtMeneyn(void);

node* createNode(int data);

void BubbleSort(node** head);

void ItIsEmpty(void); 

int isListEmpty(node* head);

char* TaAnvändarensInput(const char* prompt);

char* SkrivEttMeddelande(const char* prompt);

void removeElementAtPosition(node** head, int position);

void addElementAtPosition(node** head, int element, int position);

void removeElement(node** head, int target);
