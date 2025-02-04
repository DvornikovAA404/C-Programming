// Selection
// Counting sort (b[a[i]]++) | Radix sort
// Quick sort | Merge sort

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#define N 10000

typedef struct Student
{
    char name[64];
    int math;
    int phy;
    int inf;
    int total;
} Stud;

struct Student addStudent(char name[64], int math, int phy, int inf)
{
    int total = math + phy + inf;
    struct Student newStudent;
    strcpy(newStudent.name, name);
    newStudent.math = math;
    newStudent.phy = phy;
    newStudent.inf = inf;
    newStudent.total = total;
    return newStudent;    
}

Stud Selection(Stud Arr[N]){
    for(int i = 0; i < N; i++){
        int min = 0;
        int mind = 0;
        for(int j = i; j < N; j++){
            if(Arr[j].total > min){
                min = Arr[j].total;
                mind = j;
                Stud buffer = Arr[i];
                Arr[i] = Arr[j];
                Arr[j] = buffer;
            }
        }
    }
}

Stud Counting(Stud Arr[N]){
    int max = 0;
    Stud buffer[N];
    for(int i = 0; i < N; i++){
        buffer[i] = Arr[i];
        if(Arr[i].total > max){
            max = Arr[i].total;
        }
    }
    int B[max+1];
    for(int i = 0; i<max; i++){
        B[i] = 0;
    }
    for(int i = 0; i < N; i++){
        B[Arr[i].total]++;
    }
    int a = 0;
    for(int i = 0; i < max + 1; i++){
        for(int x = 0; x < B[i]; x++){
            for(int j = 0; j < N; j++){
                if(buffer[j].total == i){
                    Arr[a] = buffer[j];
                    buffer[j].total = -1;
                    a++;
                }
            }
        }
    }
}

void swap(Stud* a, Stud* b) {
    Stud temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Stud arr[], int low, int high) {
    int pivot = arr[high].total; // Последний элемент - опорный
    int i = (low - 1); // Индекс меньшего элемента

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].total <= pivot) {
            i++; // Увеличиваем индекс меньшего элемента
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(Stud arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Рекурсия
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void viewStud(Stud Arr[N]){
    for(int i = 0; i<N; i++){
        printf("%s : %d %d %d %d\n", Arr[i].name, Arr[i].math, Arr[i].phy, Arr[i].inf, Arr[i].total);
    }
}

int main(){
    const char *words[] = {"Ava", "Emma", "Olivia", "Sophia", "Isabella", "Mia", "Charlotte", "Amelia", "Harper", "Evelyn", "Abigail", "Emily", "Elizabeth", "Sofia", "Madison", "Avery", "Ella", "Scarlett", "Grace", "Chloe", "Victoria", "Riley", "Aria", "Lily", "Aubrey", "Zoey", "Penelope", "Luna", "Layla", "Hannah", "Katherine", "Nora", "Leah", "Allison", "Samantha", "Stella", "Zoe", "Savannah", "Audrey", "Brooklyn", "Bella", "Claire", "Skylar", "Lucy", "Paisley", "Everly", "Anna", "Caroline", "Nova", "Genesis", "Emilia", "Kennedy", "Maya", "Willow", "Kinsley", "Naomi", "Aaliyah", "Eleanor", "Lydia", "Aurora", "Ariana", "Alice", "Hailey", "Gabriella", "Sadie", "Ruby", "Eva", "Serenity", "Autumn", "Quinn", "Natalie", "Faith", "Josephine", "Julia", "Arianna", "Christina", "Eliana", "Peyton", "Melanie", "Gianna", "Isabelle", "Jasmine", "Elena", "Reagan", "Mackenzie", "Aubree", "Brianna", "Marie", "Isla", "Elise", "Violet", "Mary", "Kaylee", "Rose", "Alexa"};
    Stud List[N];
    srand(time(NULL));
    for(int i = 0; i<N; i++){
        int numWords = sizeof(words) / sizeof(words[0]);
        int randomIndex = rand() % numWords;
        int math = rand() % 101;
        int phy = rand() % 101;
        int inf = rand() % 101;
        List[i] = addStudent(words[randomIndex], math, phy, inf);
    }

    printf("--- ПРОЦЕССОР ---\n");
    system("grep 'model name' /proc/cpuinfo | head -n 1 | awk -F': ' '{print $2}'");
    system("grep 'cpu MHz' /proc/cpuinfo | head -n 1 | awk -F': ' '{print $2}'");

    printf("1 - Selection Sort; 2 - Counting Sort; 3 - Quick Sort\n");
    int menu = 0;
    while(menu != 1 && menu != 2 && menu != 3){ 
        if (scanf("%d", &menu) != 1){
            printf("Invalid value!\n");
            exit(-1);
        }
    }
    printf("--- ДО СОРТИРОВКИ ---\n");
    viewStud(List);
    clock_t start = clock();
    switch (menu)
    {
    case 1:
        Selection(List);
        break;
    case 2:
        Counting(List);
        break;
    case 3:
        quickSort(List, 0, N - 1);
        break;
    
    default:
        Selection(List);
        break;
    }
    clock_t end = clock();
    double time = ((double) end - start)/CLOCKS_PER_SEC;
    int size = sizeof(Stud) * N;
    printf("--- ПОСЛЕ СОРТИРОВКИ ---\n");
    viewStud(List);

    printf(" ``` Время выполнения скрипта: %.2f с ```\n", time);
    printf(" ``` Размер данных: %d байт ```\n", size);
}