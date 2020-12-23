#include <stdio.h>


#define MAXLEN 12

void displayFile(FILE *file, char *source);





int main(void){
    FILE *file;
    float nums[MAXLEN];

    file = fopen("IN.txt", "r");

    if(file == NULL){
        fclose(file);
        printf("Sorry, we don`t find file\n");
        return 1;
    }

    displayFile(file, "IN.txt");
    int i = 0;
    float sum = 0;
    int count = 0;
    char c;
    while((c = getc(file)) != EOF){
        if (!((c >= 48 && c <= 57 ) || c == 32 || c == '.')){
            fclose(file);
            printf("%d\n", c);
            file = fopen("IN.txt", "w");
            fprintf(file, "Your file is incorrect");
            fclose(file);
            displayFile(file, "IN.txt");

            return 1;
        }
    }
    fclose(file);

    file = fopen("IN.txt", "r");
    while (1) {
        if (fscanf(file, "%f", &nums[i]) == 1){
            
            count++;
            sum += nums[i];
            i++;
        
        }

        if (feof(file)) break;
    }
    fclose(file);

    file = fopen("IN.txt", "a");

    fprintf(file, " %.2f", sum);


    fclose(file);

    displayFile(file, "IN.txt");

    puts("exercise 2");

    

    file = fopen("IN.txt", "r");

    int chars[MAXLEN];
    for (int i = 0; i < MAXLEN; i++)
    {
        chars[i] = 0;
    }
    
    while( (c = getc(file)) != EOF){
        if (c == '.') chars[10]++;
        else if (c == ' ') chars[11]++;
        else if (c >= 48 && c <= 57) {
            chars[c - 48]++;
        }
    }
    char chr;
    int max = chars[0];
    for (int i = 0; i < MAXLEN; i++)
    {
        // printf("%d\n", chars[i]);
        if (max < chars[i]){
            max = chars[i];
            if (i == 10){
                chr = '.';
            } else if (i == 11){
                chr = ' ';
            } else{
                chr = i + 48;
            }

        } 

    }
    
    printf("%c\n", chr);
    fclose(file);

    file = fopen("OUT.txt", "w");

    fprintf(file ,"The most common symbol is '%c'\n", chr);
    fclose(file);
    displayFile(file, "OUT.txt");
}


void displayFile(FILE *file, char *source){
    file = fopen(source, "r");

    char c;

    printf("It is a \"%s\"\n", source);

    while((c = getc(file)) != EOF){
        printf("%c", c);
    }

    printf("\nEnd of \"%s\"\n", source);

    fclose(file);
}

