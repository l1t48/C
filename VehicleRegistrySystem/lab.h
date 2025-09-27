#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
#define MAX_SIZE 30
#define RANGE 11
#define MINI_AGE 18
#define MAX_AGE 120

typedef struct{
    char namn[MAX_SIZE];
    int alder;
} person_s1;


typedef struct{
    char fordonstyp[MAX_SIZE];
    char marke[MAX_SIZE];
    char registernummer[MAX_SIZE];
    person_s1 individ;
}fordon_s2;

void add_vehicle(fordon_s2 vec[], int range);

void remove_vehicle(fordon_s2 vec[], int *range);

void sort(fordon_s2 vec[], int range);

void pint_specifie_car(fordon_s2 vec[], int range);

void pint_all_cars(fordon_s2 vec[], int range);

void save_in_file(fordon_s2 vec[], int range);

int print_out_file(fordon_s2 vec[], int range);

void shut_down(fordon_s2 vec[], int range);