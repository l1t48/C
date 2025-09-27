//Abas och Adnan
//Gödkänt av Freysteinn Alfredsson
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

#define size 100
#define max_range 900
#define min_range 1
#define choice1 1
#define choice2 2
#define choice3 3
#define choice4 4
#define choice0 0
#define per_rad 10
#define rest 0
#define noll 0
#define position0 0
#define position1 1
#define position2 2
#define position3 3
#define position4 4
#define even 2
#define dubbel_even 2.0
#define element 1

void slumpgenrator (int *random_number){
        srand(time(NULL));
        for(int i = noll; i <size; i++){
            random_number[i] = rand()%max_range + min_range;
        }
        
}

void sortera(int *random_number){
    int i;
    int k;
    int x;
    for (i = noll; i < size; i++){
        for(k = i +1; k < size; k++){
            if ( random_number[i] > random_number[k]){
                x = random_number[i];
                random_number[i] = random_number[k];
                random_number[k] = x;
            
            }
        }
    }
}

void statistik(int *random_number){
    int storsta_nummer = random_number[noll];
    int minsta_nummer = random_number[noll];
    double summa = noll;
    double medelvardet = noll;
    double median = noll;

    for (int i = noll; i < size; i++){
        if( minsta_nummer > random_number[i]){
             minsta_nummer = random_number[i];
        }
        if( storsta_nummer < random_number[i]){
             storsta_nummer = random_number[i];
        }
    }
    
    
    for (int i = noll; i < size; i++){
        summa = summa + random_number[i];
    }
    
    medelvardet = summa / size;
    
    
    for (int i = noll; i < size; i++){
        if(size % even == noll){
            median = (random_number[size/even] + random_number[size/even-element])/dubbel_even;
        }
    }
    
        printf("Min = %d, Max = %d\nMedel = %.2lf, Median = %.2lf",minsta_nummer,storsta_nummer,medelvardet, median);
        printf("\n");
    
}


void sok(int *random_number){
        int sokning;

        printf("Number: "); 
        scanf("%d", &sokning);
        int forsta_element = noll;
        int sista_element = size -element;
        int middle = (sista_element + forsta_element) /even;

        while(forsta_element <= sista_element){
            if(random_number[middle] < sokning){
                forsta_element = middle + element;
            }
            else if(random_number[middle] == sokning){
                printf("Hittad %d", middle+element);
                break;
            }
            else{
                sista_element = middle - element;
            }
        
            
            middle = (forsta_element + sista_element)/even;
        
        }
    
        if( random_number[middle] !=  sokning){
            printf("Talet hittades inte");
        }
    
        int row = middle /per_rad;
        int col = middle %per_rad;
    
        if (sokning == random_number[middle])
            printf("\n%d, %d", row+element,col+element);
    
    
}

void avsluta(){
    printf("Program avslutat");
    exit(noll);
}


int main(){
        int input; 
        int position = noll;
        int alla_tal[size];
        printf("1. Generera talföljd\n");
        printf("2. Sortera talföljd\n");
        printf("3. Berakna medel, median, max och minvärde\n");
        printf("4. Sök i talföljd\n");
        printf("0. Avsluta\n");  
    
        while(1){

            scanf("%d", &input);
        

            if(input == choice0 || input == choice1 || input == choice2 || input == choice3 || input == choice4){
                if (input == choice1){
                    if (position == position0 || position == position1){
                        position = position1;
                        slumpgenrator(alla_tal);
                        for(int i = noll;i <size; i++){
                            if (i % per_rad == rest){
                                printf("\n");
                            }
                            printf("%4d", alla_tal[i]);
                    }
                    printf("\n");
                }
            }

            if (input == choice2){
                if (position == position1 || position == position2 ){
                position = position2;  
                printf("Vektor sorterad");
                sortera(alla_tal);
                for (int i = noll; i < size; i++){
                    if (i % per_rad == rest){
                        printf("\n");
                    }
                    printf("%4d", alla_tal[i]);
                }
                printf("\n");
            }    
            else{
                    printf("Du måste generera en talföljd inan du kan sortera den.\n");
                }

            }  
        
        if (input == choice3){
            if (position == position2|| position == position3 ){
                position = position3;
                statistik(alla_tal);
            }
            
             else{
                printf("Du måste sortera en talföljd innan du kan beräkna medel, median, max och min.\n");
            }
        
        }  
        


        if (input == choice4){
            
            if (position == position3 || position == position4){
                position = position4;
                sok(alla_tal);
                printf("\n");
            }

            else{
                printf("Du måste sortera en talföljd innan du kan hitta önskade row och col\n");
            }
        }  
            
                
        if (input == choice0){
            avsluta();
        }    
                
            
                
    }
        else{
            printf("Felaktig inmatning\n");
            printf("1. Generera talföljd\n");
            printf("2. Sortera talföljd\n");
            printf("3. Berakna medel, median, max och minvärde\n");
            printf("4. Sök i talföljd\n");
            printf("0. Avsluta\n");          
        }
                                                                              
            

    }
    

}
    