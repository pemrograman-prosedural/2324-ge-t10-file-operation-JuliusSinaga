// 12S23035 - Julius Kaisar Bona Theo Sinaga
// 12S23044 - Gracia Pardede

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/repository.h"

int main(int _argc, char **_argv)
{
    struct dorm_t *dorm = malloc(6 * sizeof(struct dorm_t));
    struct student_t *student = malloc(12 * sizeof(struct student_t));

    FILE *dormFile = fopen("./storage/dorm-repository.txt", "r");
    FILE *studentFile = fopen("./storage/student-repository.txt", "r");
    char *masukan, *temp;
    char ins[100];
    int indexStudent = 0, indexDorm = 0;

    if (dormFile == NULL || studentFile == NULL)
    {
        printf("File not found\n");
        return 1;
    }

    while(1) {
        fgets(ins, 100, dormFile);
        masukan = ins;
        if (masukan == NULL) {
            break;
        }
        // Memecah
        temp = strtok(masukan, "|");
        strcpy(dorm->name, temp);
        temp = strtok(NULL, "|");
        dorm->capacity = atoi(temp);
        temp = strtok(NULL, "|");
        if (strcmp(temp, "male") == 0) {
            dorm->gender = GENDER_MALE;
        } else {
            dorm->gender = GENDER_FEMALE;
        }
        dorm[indexDorm] = create_dorm(dorm->name, dorm->capacity, dorm->gender);
        indexDorm++;
    }

    while (1) {
        fgets(ins, 100, studentFile);
        masukan = ins;
        if (masukan == NULL) {
            break;
        }
        // Memecah
        temp = strtok(masukan, "|");
        strcpy(student->id, temp);
        temp = strtok(NULL, "|");
        strcpy(student->name, temp);
        temp = strtok(NULL, "|");
        strcpy(student->year, temp);
        temp = strtok(NULL, "|");
        if(strcmp(temp, "male") == 0) {
            student->gender = GENDER_MALE;
        } else {
            student->gender = GENDER_FEMALE;
        }
        student[indexStudent] = create_student(student->id, student->name, student->year, student->gender);
        indexStudent++;
    }

    while (1) {
        fgets(ins, 100, stdin);
        ins[strcspn(ins, "\n")] = 0;  // remove newline

        if (strcmp(ins, "---") == 0) {
            break;
        } else if (strcmp(ins, "dorm-print-all-detail") == 0) {
            print_dorm_detail(dorm, indexDorm);
            continue;
        } else if (strcmp(ins, "dorm-print-all") == 0) {
            print_dorm(dorm, indexDorm);
            continue;
        } else if (strcmp(ins, "student-print-all-detail") == 0) {
            print_student_detail(student, indexStudent);
            continue;
        } else if (strcmp(ins, "student-print-all") == 0) {
            print_student(student, indexStudent);
            continue;
        }

        masukan = strtok(ins, "#");
        if (strcmp(masukan, "dorm-add") == 0) {
            temp = strtok(NULL, "#");
            strcpy(dorm->name, temp);
            temp = strtok(NULL, "#");
            dorm->capacity = atoi(temp);
            temp = strtok(NULL, "#");
            if (strcmp(temp, "male") == 0) {
                dorm->gender = GENDER_MALE;
            } else {
                dorm->gender = GENDER_FEMALE;
            }

            dorm[indexDorm] = create_dorm(dorm->name, dorm->capacity, dorm->gender);

            indexDorm++;
        } else if (strcmp(masukan, "student-add") == 0) {
            temp = strtok(NULL, "#");
            strcpy(student->id, temp);
            temp = strtok(NULL, "#");
            strcpy(student->name, temp);
            temp = strtok(NULL, "#");
            strcpy(student->year, temp);
            temp = strtok(NULL, "#");
            if (strcmp(temp, "male") == 0) {
                student->gender = GENDER_MALE;
            } else {
                student->gender = GENDER_FEMALE;
            }
            
            student[indexStudent] = create_student(student->id, student->name, student->year, student->gender);

            indexStudent++;

    }


    return 0;
}
