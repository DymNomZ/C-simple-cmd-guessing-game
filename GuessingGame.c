#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int guess(int* a);
struct Player player1Name();
struct Player player2Name();

struct Player{
    char name [50];
};

int main(){

    const int min = 1;
    const int max = 100;
    int temp, answer, p1, p2;
    struct Player player1, player2;
    player1 = player1Name();
    player2 = player2Name();

    srand(time(0));

    answer = (rand()%max)+min;
    temp = answer;

    printf("%s is up!\n", player1.name);
    p1 = guess(&temp);
    system("cls");
    printf("%s is up!\n", player2.name);
    p2 = guess(&temp);

    printf("Answer: %d\n%s Guesses: %d\n%s Guesses: %d\n", answer, player1.name, p1, player2.name, p2);
    (p1<p2) ? printf("%s WINS!\n", player1.name) : printf("%s WINS!\n", player2.name);
    
    system("PAUSE");
    return 0;
}

struct Player player1Name(){
    struct Player p1;
    printf("Enter Player 1: ");
    scanf("%s", p1.name);
    return p1;
}

struct Player player2Name(){
    struct Player p2;
    printf("Enter Player 2: ");
    scanf(" %s", p2.name);
    return p2;
}

int guess(int* a){
    int guess, guesses = 0;
    do{
        printf("Guess: ");
        scanf("%d", &guess);
        if(guess>*a){
            printf("TOO HIGH!\n");
        }
        else if(guess<*a){
            printf("TOO LOW\n");
        }
        else{
            printf("YOU GUESSED IT!\n");
        } 
        guesses++;
    }while(guess != *a);
    return guesses;
}