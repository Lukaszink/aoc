#include <stdio.h>
#include <stdlib.h>
void v1(FILE *);
void v2(FILE *);


int main()
{
    FILE *fp = fopen("in.txt", "r");
    // FILE *fp2 = fopen("input2.txt", "r");

    v2(fp);
    // v2(fp);
}

void v1(FILE *f)
{
    char tmp = '\n';
    int nr = 10;
    int winning_nr = 25;


    int nrs[nr];
    int winning[winning_nr];


    int score = 0;
    int total_score =0;

    while (fscanf(f, "%c", &tmp) > 0)
    {
        score = 0;
        tmp = '0';
        while (tmp != ':') fscanf(f, "%c", &tmp);
       
        for(int i = 0; i < nr ; i++){
            fscanf(f, " %d",&nrs[i]);
        }
        fscanf(f, " |");
        

        for(int i =0 ; i < winning_nr ; i++){
            fscanf(f, " %d", &winning[i]);
            printf("Winning %d %d \n", i , winning[i]);
        }
        fscanf(f, "\n");

        for(int guess = 0; guess < nr ; guess++){
            for(int correct = 0; correct < winning_nr ; correct++){
                if (nrs[guess] == winning[correct]){
                    if(score == 0){
                        score = 1;
                    } 
                    else{
                        score *= 2;
                    }
                }
            }
        }
        total_score += score;

    }
    printf("SCORE: %d: \n" , total_score);
}

void v2(FILE *f)
{
    char tmp = '\n';
    int nr = 10;
    int winning_nr = 25;
    int nr_cards = 193;

    int nrs[nr];
    int winning[winning_nr];

    int score = 0;

    int *  multi = calloc(nr_cards, sizeof(int)); 



    int card_index ;

    while (fscanf(f, "%c", &tmp) > 0)
    {
        multi[card_index] ++;
        score = 0;
        tmp = '0';
        while (tmp != ':') fscanf(f, "%c", &tmp);
       
        for(int i = 0; i < nr ; i++){
            fscanf(f, " %d",&nrs[i]);
        }
        fscanf(f, " |");
        

        for(int i =0 ; i < winning_nr ; i++){
            fscanf(f, " %d", &winning[i]);
            //printf("Winning %d %d \n", i , winning[i]);
        }
        fscanf(f, "\n");

        for(int guess = 0; guess < nr ; guess++){
            for(int correct = 0; correct < winning_nr ; correct++){
                if (nrs[guess] == winning[correct]){
                    score++;
                }
            }
        }
        printf("Score %d\n", score);

        for(int i = 0; i < score ; i++){
            if ((card_index + i + 1) < nr_cards)
                multi[card_index + i +1] += multi[card_index];
        }
        card_index++;


    }
    int total_score = 0;
    for(int i = 0; i < nr_cards ; i++){
        total_score += multi[i];
        //printf("multi %d : %d \n", i , multi[i]);
    }
    printf("SCORE: %d: \n" , total_score);
}