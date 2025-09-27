#include "lab.h"

void add_vehicle(fordon_s2 vec[], int range){
    char age[RANGE];
    printf("Write your vehicle type \n");
    fgets(vec[range].fordonstyp, MAX_SIZE, stdin);
    strtok(vec[range].fordonstyp, "\n");
    printf("Write your vehicle brand \n");
    fgets(vec[range].marke, MAX_SIZE, stdin);
    strtok(vec[range].marke, "\n");
    printf("Write your registartion number\n");
    fgets(vec[range].registernummer, MAX_SIZE, stdin);
    strtok(vec[range].registernummer, "\n");
    printf("Write your name\n");
    fgets(vec[range].individ.namn, MAX_SIZE, stdin);
    strtok(vec[range].individ.namn, "\n");
    while(isdigit(*vec[range].individ.namn)){
        printf("Please enter a real name\n");   
        printf("Write your name\n");
        fgets(vec[range].individ.namn, MAX_SIZE, stdin);
        strtok(vec[range].individ.namn, "\n");
    }
    printf("Write your age\n");
    fgets(age, MAX_SIZE, stdin);
    while(!isdigit(*age)){
        printf("Please enter a number, not letters.\n");   
        printf("Write your age\n");
        fgets(age, MAX_SIZE, stdin);
        vec[range].individ.alder = atoi(age);   
    }
    vec[range].individ.alder = atoi(age);    
    vec[range].marke[strcspn(vec[range].marke, "\n")] = 0;
    vec[range].registernummer[strcspn(vec[range].registernummer, "\n")] = 0;
    vec[range].individ.namn[strcspn(vec[range].individ.namn, "\n")] = 0;
}


void remove_vehicle(fordon_s2 vec[], int *range){
    int line;
    char input[MAX_SIZE];
    fgets(input, MAX_SIZE, stdin);
    line = atoi(input);
    if(line >= *range || line < 0 || line == 0){
        printf("The car doesn't really exist.\n");
    }
    
    else{
        if(line >= 1 && line <= *range){
            for(int i = line; i <= *range; i++){
                vec[i] = vec[i+1];
            }
            *range = *range -1;
        }
            
    }

}



void sort(fordon_s2 vec[], int range){
    fordon_s2 vec_sort;
    for(int i = 0; i <range - 1; i++){
        for(int k = 0; k < range -1 - i; k++){
            if(strcmp(vec[k].marke, vec[k+1].marke) > 0){
                vec_sort = vec[k];
                vec[k] = vec[k+1];
                vec[k+1] = vec_sort;
            }
        }
    }
}


void pint_specifie_car(fordon_s2 vec[], int range){
    char chosen_car[MAX_SIZE];
    int line_number;
    printf("Select the line that contains the car to be displayed\n");
    fgets(chosen_car,MAX_SIZE, stdin);
    line_number = atoi(chosen_car);
    if(line_number >= range || line_number < 0 || line_number == 0){
        printf("The car doesn't really exist.");
    }
    
    else{
        while(!isdigit(*chosen_car)){
            printf("Please enter a number, not letters.\n");   
            printf("Select the line that contains the car to be displayed\n");
            fgets(chosen_car, MAX_SIZE, stdin);
            line_number = atoi(chosen_car);
        }
    
        printf("vehicle type : %s                   vehicle brand: %s                  registartion number: %s                  Owner name : %s                 Owner age: %d\n" ,vec[line_number].fordonstyp ,vec[line_number].marke,vec[line_number].registernummer, vec[line_number].individ.namn, vec[line_number].individ.alder);
}


            
    }

void pint_all_cars(fordon_s2 vec[], int range){
       for(int i =1; i<range;i++){
            printf("vehicle type : %s                   vehicle brand: %s                   registartion number: %s\n" ,vec[i].fordonstyp ,vec[i].marke,vec[i].registernummer);
       }
}


void shut_down(fordon_s2 vec[], int range){
    save_in_file(vec, range);
    exit(0);
}
