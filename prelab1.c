#include <stdio.h>
#include <string.h>

int coinTossGame(char player1[4], char player2[4], int *winner, int *numTosses);


int main() {
    int a, b = 0;
    
    char bob[4] = "THH";
    char alice[4] = "HHT";
    
    coinTossGame(bob, alice, &a, &b);
    
    printf("Number of tosses: %d\n", b);
    if (a == 1){
        printf("Alice Wins");
    }
    else if (a == 0){
        printf("Bob Wins"); 
    }
    
    
}

int coinTossGame(char player1[4], char player2[4], int *winner, int  *numTosses){

    char window[1000] = ""; 
    
    int toss;
    for(int i = 0; i < 2; i++) {
        toss = rand() % 2;
        (*numTosses)++;
        
        if (toss == 1){
            printf("T\n");
            char aliceletter = 'T';
            strncat(window, &aliceletter, 1);
        }
        else if(toss == 0){
            printf("H\n");
            char bobletter = 'H'; 
            strncat(window, &bobletter, 1);
        }
    }
    
    int bobcount, alicecount = 0; 
    
    while(alicecount < 3 || bobcount < 3){
        for(int f = 0; f < 100 && bobcount != 3 && alicecount != 3; f++){
            toss = rand() % 2;
            (*numTosses)++;
            if (toss == 1){
                printf("T\n");
                char aliceletter = 'T';
                strncat(window, &aliceletter, 1);
            }
            else if(toss == 0){
                printf("H\n");
                char bobletter = 'H'; 
                strncat(window, &bobletter, 1);
            }
            printf("%s\n", window);
            for(int i = 0; i < 3; i++){
                printf("Comparing %c with p1: %c, p2: %c\n", window[i], player1[i], player2[i]);
                if(window[i] == player1[i]){
                    printf("Bob matched position %d\n", i);
                    bobcount++;
                }
                if(window[i] == player2[i]){
                    printf("Alice matched position %d\n", i);
                    alicecount++; 
                }
            }
            if(bobcount == 3 ){
              
                *winner = 0; 
            } else if(alicecount == 3){
                
                *winner = 1; 
            } else {
                window[0] = window[1]; 
                window[1] = window[2];
                window[2] = window[3];
            bobcount = 0;
            alicecount = 0;   
            }
        }
            
            
            
            return 0; 
    
    
    }
    
}
