#include "dorm.h"
#include <stdio.h>
#include <string.h>

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender) {
    struct dorm_t dorm;

    strcpy(dorm.name, _name);
    dorm.capacity = _capacity;
    dorm.gender = _gender;
    dorm.residents_num = 0;

    return dorm;
}

void print_dorm(struct dorm_t *_dorm, int _size) {
    char *gender;
    for (int i = 0; i < _size; i++) {
        if (_dorm[i].gender == GENDER_MALE) {
            gender = "male";
        } else {
            gender = "female";
        }
        printf("%s|%d|%s\n", _dorm[i].name, _dorm[i].capacity, gender);
    }
}

void print_dorm_detail(struct dorm_t *_dorm, int _size) {
    char *gender;
    for (int i = 0; i < _size; i++) {
        if (_dorm[i].gender == GENDER_MALE) {
            gender = "male";
        } else {
            gender = "female";
        }
        printf("%s|%d|%s|%d\n", _dorm[i].name, _dorm[i].capacity, gender, _dorm[i].residents_num);
    }
}

