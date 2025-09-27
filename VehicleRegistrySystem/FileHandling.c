#include "lab.h"

void save_in_file(fordon_s2 vec[], int range){
    FILE *saving_file;
    saving_file  = fopen("saving_file.txt", "w");
    for(int i = 1; i < range; i++){
        fprintf(saving_file,"vehicle type : %s                   vehicle brand: %s                  registartion number: %s                  Owner name : %s                 Owner age: %d\n" ,vec[i].fordonstyp ,vec[i].marke,vec[i].registernummer, vec[i].individ.namn, vec[i].individ.alder);
    }
        
    fclose(saving_file);

}


int print_out_file(fordon_s2 vec[], int range){
    FILE *saving_file;
    int scan;
    saving_file = fopen("saving_file.txt", "a+");
    for (int i = 1; i<RANGE; i++){
        fordon_s2 extra_car;
        scan =fscanf(saving_file,"vehicle type : %s                   vehicle brand: %s                  registartion number: %s                  Owner name : %s                 Owner age: %d\n" ,extra_car.fordonstyp ,extra_car.marke,extra_car.registernummer, extra_car.individ.namn, &extra_car.individ.alder);
 
      if(scan != EOF){
        range++;
        vec[range]= extra_car;
        }
    }
    fclose(saving_file);
    return range;
}
