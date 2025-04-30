#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void task3(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    if (!in) {
        perror("Ошибка открытия входного файла");
        return;
    }

    FILE *out = fopen(outputFile, "w");
    if (!out) {
        perror("Ошибка создания выходного файла");
        fclose(in);
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), in)) {
        char newBuffer[2048] = "";
        char *word = strtok(buffer, " \n");
        while (word) {
            strcat(newBuffer, word);
            strcat(newBuffer, ". ");
            word = strtok(NULL, " \n");
        }
        fprintf(out, "%s\n", newBuffer);
    }

    fclose(in);
    fclose(out);
}

void task4(const char *inputFile, const char *outputFile, const char *targetWord, const char *name) {
    FILE *in = fopen(inputFile, "r");
    if (!in) {
        perror("Ошибка открытия входного файла");
        return;
    }

    FILE *out = fopen(outputFile, "w");
    if (!out) {
        perror("Ошибка создания выходного файла");
        fclose(in);
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), in)) {
        char newBuffer[2048] = "";
        char *word = strtok(buffer, " \n");
        while (word) {
            if (strcmp(word, targetWord) == 0) {
                strcat(newBuffer, name);
            } else {
                strcat(newBuffer, word);
            }
            strcat(newBuffer, " ");
            word = strtok(NULL, " \n");
        }
        fprintf(out, "%s\n", newBuffer);
    }

    fclose(in);
    fclose(out);
}

void task5(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    if (!in) {
        perror("Ошибка открытия входного файла");
        return;
    }

    FILE *out = fopen(outputFile, "w");
    if (!out) {
        perror("Ошибка создания выходного файла");
        fclose(in);
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), in)) {
        char newBuffer[2048] = "";
        char *word = strtok(buffer, " \n");
        while (word) {
            int len = strlen(word);
            for (int i = len - 1; i >= 0; i--) {
                strncat(newBuffer, &word[i], 1);
            }
            strcat(newBuffer, " ");
            word = strtok(NULL, " \n");
        }
        fprintf(out, "%s\n", newBuffer);
    }

    fclose(in);
    fclose(out);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Использование: %s <имя_входного_файла>\n", argv[0]);
        return 1;
    }

    const char *inputFile = argv[1];
    const char *outputFile3 = "build/task3.txt";
    const char *outputFile4 = "build/task4.txt";
    const char *outputFile5 = "build/task5.txt";

    task3(inputFile, outputFile3);
    task4(inputFile, outputFile4, "Duis", "Андрей");
    task5(inputFile, outputFile5);

    printf("- task3.txt\n- task4.txt\n- task5.txt\n");
    return 0;
}