/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

//check 0 hp cards
int isFull(int[]);
//reset cards health to full
void reset(int[]);

int main()
{
    time_t t;
    srand((unsigned) time(&t));
    
    //3 cards
    int num[3];
    //5 damage
    int dmg = 5;
    //index for cards array
    int index;
    //counter of success
    int count = 0;
    //sample size
    int re = 10000;
    
    for(int j = 0; j < re; j++){
        //reset the senario
        reset(num);
        //launch the spell 'Jianwu'
        for(int i = 0; i < dmg; i++){
            //break and increase counter if success
            if(isFull(num) == 0){
                count++;
                break;
            }
            //choose 1 random card from 3 cards to deal 1 damage
            else if(isFull(num) == -1){
                index = rand() % 3;
                num[index]--;
            //choose 1 random card from 2 cards to deal 1 damage    
            }else if(isFull(num) == 2){
                index = rand() % 2;
                num[index]--;
            }
        }
    }
    
    printf("\n\nFinal result: %d/%d", count, re);

    return 0;
}

int isFull(int num[3]){
    //return 0 for 1st card drops to 0 hp
    if(num[0] == 0){
        return 0;
    } 
    //return 1 for 2nd card drops to 0 hp (NEVER HAPPENS)
    else if(num[1] == 0){
        return 1;
    } 
    //return 2 for 3rd card drops to 0 hp
    else if(num[2] == 0){
        return 2;
    } 
    //return -1 if all cards are above 0 hp
    else{
        return -1;
    }
}

void reset(int num[3]){
    num[0] = 2;
    num[1] = 6;
    num[2] = 1;
}