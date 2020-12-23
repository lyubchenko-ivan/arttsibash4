#include <stdio.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "ru");
    int n;
    FILE *file = fopen("IN.txt", "w");

    puts("Привет, введи количество вещественных чисел, по-братски");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        float temp;
        printf("Введите число:");
        scanf("%f", &temp);

        fprintf(file, "%f ", temp);
    }
    
    fclose(file);
    
}


