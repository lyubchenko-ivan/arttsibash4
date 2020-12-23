#include <stdio.h>


#define MAXLEN 12

void displayFile(FILE *file, char *source);





int main(void){
    FILE *file;//переменная-указатель для хранения указателя на файл
    float num;//переменная для хранения принимаемых вещественных чисел

    file = fopen("IN.txt", "r");//открываем файл "IN.txt" для чтения

    //проверяем существет ли файл "IN.txt"
    if(file == NULL){
        fclose(file);
        printf("Sorry, we don`t find file\n");
        return 1;
    }

    //Если файл существует, то продолжаем выполнение
    //выводим значения файла
    displayFile(file, "IN.txt");
    int i = 0;
    float sum = 0;//переменная для хранения суммы вещественных чисел в файле

    char c;//переменная для получения посимвольного ввода из файла
    //проверка на валидность записи файла
    while((c = getc(file)) != EOF){
        //проверка на то совпадает ли полученный символ с соглашением по допустимым символам в файле
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
    //закрываем файл
    fclose(file);
    //еще раз открываем для чтения
    file = fopen("IN.txt", "r");
    //пока не достигли конца файла, считываем значения вещественных чисел и вычисляем сумму
    while (1) {
        if (fscanf(file, "%f", &num) == 1){
            
            sum += num;
            i++;
        
        }

        if (feof(file)) break;
    }
    //закрываем файл
    fclose(file);

    //открываем для добавления суммы
    file = fopen("IN.txt", "a");
    //записываем сумму
    fprintf(file, " %.2f", sum);

    //закрываем файл
    fclose(file);
    //выводим на экран содержимое файла
    displayFile(file, "IN.txt");

    puts("exercise 2");

    
    //открываем файл для чтения
    file = fopen("IN.txt", "r");

    int chars[MAXLEN];//данный массив будет содержать кол-во раз встреченных символов
                        //(0...10) - цифры от 0 до 9
                        //10 - пробел
                        //11 - точка



    //заполним массив нулями
    for (int i = 0; i < MAXLEN; i++)
    {
        chars[i] = 0;
    }
    

    //пока файл не пустой считываем символы, проверяя, что это за символ и увеличиваем счетчик для данного символа в массиве
    while( (c = getc(file)) != EOF){
        if (c == '.') chars[10]++;
        else if (c == ' ') chars[11]++;
        else if (c >= 48 && c <= 57) {
            chars[c - 48]++;
        }
    }

    char chr;//переменная для записи самого часто встречающегося символа
    int max = chars[0];//количество раз для максимально встречающегося символа
    //проверяем какой символ часто встречающийся 
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
    //закрываем файл
    fclose(file);
    //открываем файл для записи
    file = fopen("OUT.txt", "w");
    //записываем значение символа
    fprintf(file ,"The most common symbol is '%c'\n", chr);
    //закрываем файл
    fclose(file);
    //выводим содержимое файла на экран
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

