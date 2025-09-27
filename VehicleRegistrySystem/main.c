#include "lab.h"
int main(){
    fordon_s2 vec[RANGE];
    int range = 1 + print_out_file(vec, range);
    char input_in_char[MAX_SIZE];
    printf("1. Add Vehicle\n");
    printf("2. Remove Vehicle\n");
    printf("3. Sort\n");
    printf("4. Show Vehicle\n");
    printf("5. Show Registry\n");
    printf("0. Quit\n");
    while(1){
        fgets(input_in_char, MAX_SIZE, stdin);
        strtok(input_in_char, "\n");
        switch(input_in_char[0]){
            case '0':
                shut_down(vec, range);
            break;
                
            case '1':
                    if(range < RANGE){
                        add_vehicle(vec, range);      
                        range++;
                        printf("\n1. Add Vehicle\n");
                        printf("2. Remove Vehicle\n");
                        printf("3. Sort\n");
                        printf("4. Show Vehicle\n");
                        printf("5. Show Registry\n");
                        printf("0. Quit\n");                        
                    }
            
                   else{
                        printf("The maximum number of cars allowed to be entered has been reached.\n");
                        printf("\n\n1. Add Vehicle\n");
                        printf("2. Remove Vehicle\n");
                        printf("3. Sort\n");
                        printf("4. Show Vehicle\n");
                        printf("5. Show Registry\n");
                        printf("0. Quit\n");
                   }

            break;
                
            case '2':
                                
                                
                if( range == 1){
                    printf("This option cannot be used as there are no registered cars.\n");
                }
                
                else if( range >= 1){
                    printf("Choose one of the %d cars you want to remove from the list.\n",range-1);
                    remove_vehicle(vec, &range);
                    printf("The car %d has been removed from the list.\n", range);
                    printf("\n1. Add Vehicle\n");
                    printf("2. Remove Vehicle\n");
                    printf("3. Sort\n");
                    printf("4. Show Vehicle\n");
                    printf("5. Show Registry\n");
                    printf("0. Quit\n");
                }
            break;
                
            case '3':
                 if( range == 1){
                    printf("This option cannot be used as there are no registered cars.\n");
                }
                
                else if( range >= 1){
                    sort(vec, range);
                    printf("Vehicles are now sorted by brand.\n");
                    printf("\n1. Add Vehicle\n");
                    printf("2. Remove Vehicle\n");
                    printf("3. Sort\n");
                    printf("4. Show Vehicle\n");
                    printf("5. Show Registry\n");
                    printf("0. Quit\n");
                    printf("\n");
                }


                
            break;
                
            case '4':
                
                if( range == 1){
                    printf("This option cannot be used as there are no registered cars.\n");
                }
                
                else if( range >= 1){
                    pint_specifie_car(vec, range);
                    printf("\n1. Add Vehicle\n");
                    printf("2. Remove Vehicle\n");
                    printf("3. Sort\n");
                    printf("4. Show Vehicle\n");
                    printf("5. Show Registry\n");
                    printf("0. Quit\n");
                    printf("\n");
                }

            break;
                
            case '5':
                                
                if( range == 1){
                    printf("This option cannot be used as there are no registered cars.\n");
                }
                
                else if( range >= 1){
                    pint_all_cars(vec, range);
                    printf("\n1. Add Vehicle\n");
                    printf("2. Remove Vehicle\n");
                    printf("3. Sort\n");
                    printf("4. Show Vehicle\n");
                    printf("5. Show Registry\n");
                    printf("0. Quit\n");
                    printf("\n");
                }

            break;
                
            default:
                printf("Siffror som inte finns i listan kan inte användas och bokstäver är förbjudna.\n");        
                printf("\n1. Add Vehicle\n");
                printf("2. Remove Vechicle\n");
                printf("3. Sort\n");
                printf("4. Show Vechicle\n");
                printf("5. Show Registry\n");
                printf("0. Quit\n");
        }

    }
    return 0;
}