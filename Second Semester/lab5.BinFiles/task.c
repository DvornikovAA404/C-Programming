#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Worker {
    char fio[100];
    char number[20];
    int day;
    int month;
    int year;
};

typedef struct Worker Worker;

void enter(int N, Worker A[N]) {
    FILE *out = fopen("Worker.dat", "wb");  

    if (out == NULL) {
        perror("Error opening file");
        return;
    }


    for (int i = 0; i < N; i++) {
        fwrite(A[i].fio, sizeof(char), 100, out);
        fwrite(A[i].number, sizeof(char), 20, out);
        fwrite(&A[i].day, sizeof(int), 1, out);
        fwrite(&A[i].month, sizeof(int), 1, out);
        fwrite(&A[i].year, sizeof(int), 1, out);
    }

    fclose(out);
}

void display() {
    FILE *in = fopen("Worker.dat", "rb"); 

    if (in == NULL) {
        perror("Error opening file");
        return;
    }

    Worker workers[100];
    int count = 0;

    while (1) {
        if (fread(workers[count].fio, sizeof(char), 100, in) != 100) break;
        if (fread(workers[count].number, sizeof(char), 20, in) != 20) break;
        if (fread(&workers[count].day, sizeof(int), 1, in) != 1) break;
        if (fread(&workers[count].month, sizeof(int), 1, in) != 1) break;
        if (fread(&workers[count].year, sizeof(int), 1, in) != 1) break;
        count++;
    }
    fclose(in);

    printf("По какому полю производить поиск? 1-ФИО, 2-номер, 3-день рождения, 4-месяц рождения, 5-год рождения\n");
    char choice;
    scanf(" %c", &choice);

    printf("Введите значение для поиска: ");
    char searchValue[100];
    int intValue;
    char Find = 0;
    switch (choice) {
        case '1':
            scanf(" %[^\n]", searchValue);
            for (int i = 0; i < count; i++) {
                if (strcmp(workers[i].fio, searchValue) == 0) {
                    printf("Найден работник: %s, %s, %d.%d.%d\n",
                           workers[i].fio, workers[i].number,
                           workers[i].day, workers[i].month, workers[i].year);
                    Find = 1;
                }
            }
            break;

        case '2': 
            scanf(" %[^\n]", searchValue);
            for (int i = 0; i < count; i++) {
                if (strcmp(workers[i].number, searchValue) == 0) {
                    printf("Найден работник: %s, %s, %d.%d.%d\n",
                           workers[i].fio, workers[i].number,
                           workers[i].day, workers[i].month, workers[i].year);
                    Find = 1;
                }
            }
            break;

        case '3':
            scanf("%d", &intValue);
            for (int i = 0; i < count; i++) {
                if (workers[i].day == intValue) {
                    printf("Найден работник: %s, %s, %d.%d.%d\n",
                           workers[i].fio, workers[i].number,
                           workers[i].day, workers[i].month, workers[i].year);
                    Find = 1;
                }
            }
            break;

        case '4':
            scanf("%d", &intValue);
            for (int i = 0; i < count; i++) {
                if (workers[i].month == intValue) {
                    printf("Найден работник: %s, %s, %d.%d.%d\n",
                           workers[i].fio, workers[i].number,
                           workers[i].day, workers[i].month, workers[i].year);
                    Find = 1;
                }
            }
            break;

        case '5':
            scanf("%d", &intValue);
            for (int i = 0; i < count; i++) {
                if (workers[i].year == intValue) {
                    printf("Найден работник: %s, %s, %d.%d.%d\n",
                           workers[i].fio, workers[i].number,
                           workers[i].day, workers[i].month, workers[i].year);
                    Find = 1;
                }
            }
            break;

        default:
            printf("Неверный выбор.\n");
            break;
        
        
    }
    if (Find == 0){
        printf("Такой работник не найден!\n");
    }
}

int main() {
    int N = 20;
    Worker Team[] = {
        {"Ivanov Ivan Ivanovich", "+79123456789", 15, 8, 1990},
        {"Petrov Petr Petrovich ", "+79234567890", 25, 3, 1985},
        {"Sidorov Alexey Sergeevich", "+79031234567", 10, 5, 1988},
        {"Kuznetsov Nikolay Vladimirovich", "+79159876543", 3, 12, 1975},
        {"Smirnov Dmitriy Anatolievich", "+79265432109", 22, 7, 1992},
        {"Popov Sergey Mikhailovich", "+79638527410", 18, 11, 1980},
        {"Volkov Andrey Viktorovich", "+79853579510", 5, 4, 1995},
        {"Lebedev Maxim Olegovich", "+79168524710", 12, 9, 1979},
        {"Novikov Denis Valerevich", "+79107418520", 28, 2, 1983},
        {"Morozov Kirill Igorevich", "+79185296374", 7, 6, 1998},
        {"Tikhonov Roman Vladislavovich", "+79216549870", 20, 1, 1987},
        {"Fedorov Anton Pavlovich", "+79604567890", 14, 10, 1972},
        {"Kovalenko Evgeniy Dmitrievich", "+79147854123", 30, 3, 1981},
        {"Gorbachev Mikhail Sergeevich", "+79098765432", 9, 8, 1993},
        {"Zaitsev Pavel Alexandrovich", "+79503216547", 23, 12, 1977},
        {"Belyaev Igor Nikolaevich", "+79298523690", 17, 4, 1984},
        {"Kondratiev Vitaliy Yurevich", "+79654789012", 11, 7, 1991},
        {"Makarov Denis Vladimirovich", "+79198765432", 27, 5, 1986},
        {"Egorov Artem Mihailovich", "+79301234567", 19, 9, 1994},
        {"Nikolaev Alexander Sergeevich", "+79523698520", 8, 11, 1986}
    };
    enter(N, Team);
    display();
}