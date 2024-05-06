#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student_t create_student(char *_id, char *_name, char *_year, enum gender_t _gender) {
    struct student_t student;

    strcpy(student.id, _id);
    strcpy(student.name, _name);
    strcpy(student.year, _year);
    student.gender = _gender;
    student.dorm = NULL;

    return student;
}

void print_student(struct student_t *_student, int _size) {
    char *gender;
    for (int i = 0; i < _size; i++) {
        if (_student[i].gender == GENDER_MALE) {
            gender = "male";
        } else {
            gender = "female";
        }
        printf("%s|%s|%s|%s\n", _student[i].id, _student[i].name, _student[i].year, gender);
    }

}

void print_student_detail(struct student_t *_student, int _size) {
    for (int i = 0; i < _size; i++)
    {
        char *_gender;
        if (_student[i].gender == GENDER_MALE) {
            _gender = "male";
        } else {
            _gender = "female";
        }

        if (_student[i].dorm == NULL) {
            printf("%s|%s|%s|%s|unassigned\n", _student[i].id, _student[i].name, _student[i].year, _gender);
        } else {
            printf("%s|%s|%s|%s|%s\n", _student[i].id, _student[i].name, _student[i].year, _gender, _student[i].dorm->name);
        }
    }
}
