#include <stdio.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "ru");
    int n;//переменная для целых чисел
    FILE *file = fopen("IN.txt", "w");//открываем файл

    puts("Привет, введи количество вещественных чисел, по-братски");
    scanf("%d", &n);//считываем кол-во вещественных чисел

    for (int i = 0; i < n; i++)//заполняем вещественными числами
    {
        float temp;
        printf("Введите число:");
        scanf("%f", &temp);

        fprintf(file, "%f ", temp);//печатаем число в файл
    }
    
    fclose(file);
    
}


