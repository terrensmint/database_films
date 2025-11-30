#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

// поля БД
typedef struct Database {
    int id;             // первичный ключ
    char title[20];     // название
    char director[20];  // режиссер
    int release_year;   // год выпуска
    float rating;       // рейтинг
} Database;

// умный массив
typedef struct Vector {
    Database *data;
    unsigned int size;
    unsigned int capacity;
} Vector;

#endif