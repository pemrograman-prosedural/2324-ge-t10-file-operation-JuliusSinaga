// 12S23035 - Julius Kaisar Bona Theo Sinaga
// 12S23044 - Gracia Pardede

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/repository.h"

int main(int _argc, char **_argv) {
    struct dorm_t *dorm = malloc(6 * sizeof(struct dorm_t));
    struct student_t *student = malloc(12 * sizeof(struct student_t));
    for (int i = 0; i < 12; i++) {
        student[i].dorm = NULL;
    }

    FILE *dormFile;
    FILE *studentFile;
    char masukan[100], *temp;
    int indexStudent = 0, indexDorm = 0;

    // Mengecek file
    if ((dormFile = fopen("./storage/dorm-repository.txt", "r")) == NULL || (studentFile = fopen("./storage/student-repository.txt", "r")) == NULL) {
        printf("File not found\n");
        return 1;
    }

    // Membaca file lalu memasukkan nya ke member struct
    while(fgets(masukan, 100, dormFile)) {
        // Memecah
        temp = strtok(masukan, "|");
        strcpy(dorm[indexDorm].name, temp);
        temp = strtok(NULL, "|");
        dorm[indexDorm].capacity = atoi(temp);
        temp = strtok(NULL, "|");
        if (strcmp(temp, "male\n") == 0) {
            dorm[indexDorm].gender = GENDER_MALE;
        } else {
            dorm[indexDorm].gender = GENDER_FEMALE;
        }
        dorm[indexDorm] = create_dorm(dorm[indexDorm].name, dorm[indexDorm].capacity, dorm[indexDorm].gender);
        indexDorm++;
    }
    fclose(dormFile);

    while (fgets(masukan, 100, studentFile)) {
        // Memecah
        temp = strtok(masukan, "|");
        strcpy(student[indexStudent].id, temp);
        temp = strtok(NULL, "|");
        strcpy(student[indexStudent].name, temp);
        temp = strtok(NULL, "|");
        strcpy(student[indexStudent].year, temp);
        temp = strtok(NULL, "|");
        if(strcmp(temp, "male\n") == 0) {
            student[indexStudent].gender = GENDER_MALE;
        } else {
            student[indexStudent].gender = GENDER_FEMALE;
        }
        student[indexStudent] = create_student(student[indexStudent].id, student[indexStudent].name, student[indexStudent].year, student[indexStudent].gender);
        indexStudent++;
    }
    fclose(studentFile);

    while (1) {
        fgets(masukan, 100, stdin);
        masukan[strcspn(masukan, "\n")] = 0;  // remove newline

        if (strcmp(masukan, "---") == 0) {
            break;
        } else if (strcmp(masukan, "dorm-print-all-detail") == 0) {
            print_dorm_detail(dorm, indexDorm);
        } else if (strcmp(masukan, "dorm-print-all") == 0) {
            print_dorm(dorm, indexDorm);
        } else if (strcmp(masukan, "student-print-all-detail") == 0) {
            print_student_detail(student, indexStudent);
        } else if (strcmp(masukan, "student-print-all") == 0) {
            print_student(student, indexStudent);
        }

        temp = strtok(masukan, "#");
        if (strcmp(temp, "dorm-add") == 0) {
            temp = strtok(NULL, "#");
            strcpy(dorm[indexDorm].name, temp);
            temp = strtok(NULL, "#");
            dorm[indexDorm].capacity = atoi(temp);
            temp = strtok(NULL, "#");
            if (strcmp(temp, "male") == 0) {
                dorm[indexDorm].gender = GENDER_MALE;
            } else {
                dorm[indexDorm].gender = GENDER_FEMALE;
            }

            dorm[indexDorm] = create_dorm(dorm[indexDorm].name, dorm[indexDorm].capacity, dorm[indexDorm].gender);

            indexDorm++;
        } else if (strcmp(temp, "student-add") == 0) {
            temp = strtok(NULL, "#");
            strcpy(student[indexStudent].id, temp);
            temp = strtok(NULL, "#");
            strcpy(student[indexStudent].name, temp);
            temp = strtok(NULL, "#");
            strcpy(student[indexStudent].year, temp);
            temp = strtok(NULL, "#");
            if (strcmp(temp, "male") == 0) {
                student[indexStudent].gender = GENDER_MALE;
            } else {
                student[indexStudent].gender = GENDER_FEMALE;
            }
            
            student[indexStudent] = create_student(student[indexStudent].id, student[indexStudent].name, student[indexStudent].year, student[indexStudent].gender);

            indexStudent++;
        } else {
        }

    }

    free(dorm);
    free(student);

    return 0;
}