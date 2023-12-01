#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void v1(FILE *);
void v2(FILE *);


void replaceNumbers(char *text, const char *find, const char *replace) {
    char *pos = text;

    while ((pos = strstr(pos, find)) != NULL) {
        memmove(pos + strlen(replace), pos + strlen(find), strlen(pos + strlen(find)) + 1);
        memcpy(pos, replace, strlen(replace));
        pos += strlen(replace);
    }
}

int main()
{
    
    FILE *fp = fopen("in.txt", "r");
    FILE *fp2 = fopen("out.txt", "w");

    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *text = (char *)malloc(fileSize + 1);
    fread(text, 1, fileSize, fp);
    text[fileSize] = '\0';

    replaceNumbers(text, "one", "one1one");
    replaceNumbers(text, "two", "two2two");
    replaceNumbers(text, "three", "three3three");
    replaceNumbers(text, "four", "four4four");
    replaceNumbers(text, "five", "five5five");
    replaceNumbers(text, "six", "six6six");
    replaceNumbers(text, "seven", "seven7seven");
    replaceNumbers(text, "eight", "eight8eight");
    replaceNumbers(text, "nine", "nine9nine");
    
    fputs(text, fp2);

    fclose(fp);
    fclose(fp2);
    

   fp = fopen("in.txt", "r");
   fp2 = fopen("out.txt", "r");
   v1(fp);
   v1(fp2);
}


void v1(FILE *f)
{
    int first_int = 0;
    int second_int = 0;
    int sum = 0;
    char tmp;

    int findfirst = 1;
    while (fscanf(f, "%c", &tmp) > 0)
    { 

        if (findfirst) {
            if (tmp >= '1' && tmp <= '9'){
                first_int = tmp - '0';
                findfirst = 0;
            }
        }
        if (tmp >= '1' && tmp <= '9'){
                second_int = tmp - '0';
        }
        if (tmp == '\n') {
            sum += 10 * first_int + second_int;     
            findfirst = 1;
        }
            

    }
    sum += 10 * first_int + second_int;     

    printf("The sum is: %d \n", sum);
}

void v2(FILE *f)
{
}