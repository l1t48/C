#include "driv.h"
#include "node.h"

int main() {
    int choice;
    SkrivUtMeneyn();
    node* head = NULL;
    
    while (1) {
        char *input = TaAnvändarensInput("\nGör ditt val: \n");
        // Use sscanf to parse input as an integer
        choice = atoi(input);
            switch (choice) {
                case 0:
                    freeList(head);
                    return 0;
                case 1:
                    SkrivUtListan(head);
                    break;
                case 2:
                    SkrivListSize(head);
                    break;
                case 3:;
                    LäggTillEnHeltalIslutetAvListan(&head);
                    break;
                case 4:
                    //LäggTillEttHeltalValfriPlats();
                    char *elementinChar = TaAnvändarensInput("Skriv in talet du vill lägga till listan: \n");
                    int position, element;
                    element = atoi(elementinChar);
                    char *positioninChar = TaAnvändarensInput("Skriv in önskade positionen: \n");
                    position = atoi(positioninChar);
                    addElementAtPosition(&head, element, position);
                    break;
                case 5:
                    //TaBortEttGivetHeltal();
                    char *elementInChar2 = TaAnvändarensInput("Skriv in önskade talet du vill tar bort: \n");
                    int element2;
                    element2= atoi(elementInChar2);
                    removeElement(&head, element2);
                    break;
                case 6:
                    //TaBortEttHeltalValfriPlats();
                    char *positioninCha2 = TaAnvändarensInput("Skriv in önskade positionen för talet du vill tar bort: \n");
                    int position2;
                    position2 = atoi(positioninCha2);
                    removeElementAtPosition(&head, position2);
                    break;
                case 7:
                    if(!isListEmpty(head)){
                       freeList(head);
                       head =NULL;
                    }
                    
                    else{
                         ItIsEmpty();
                    }

                    break;
                case 8:
                    VändPåListan(&head);
                    break;
                case 9:
                    SkiftaListanEttStegÅtVänster(&head);
                    break;
                case 10:
                    SkiftaListanEttStegÅtHöger(&head);
                    break;
                case 11:
                    BubbleSort(&head);
                    break;
                case 12:
                    SkrivBaseAddress(head);
                    break;
                default:    
                    SkrivUtMeneynMedError();
                    
            }
        
        fflush(stdin); //clear the input buffer
        
    }
}
