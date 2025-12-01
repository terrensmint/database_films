#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 50

// поля БД
typedef struct Fields {
    int id;             // первичный ключ
    char title[STR_LEN];     // название
    char director[STR_LEN];  // режиссер
    int release_year;   // год выпуска
    float rating;       // рейтинг
} Fields;

// умный массив
typedef struct Vector {
    Fields *data;
    unsigned int size;
    unsigned int capacity;
} Vector;

// функции для БД
void db_init(Vector *db);  // инициализация БД
void db_print(Vector *db);   // вывод БД на экран
void db_add(Vector *db, Fields record);  // добавление новой записи в БД
void db_search(Vector *db);   // поиск
void db_delete(Vector *db, int id);   // удаление записи в БД
void db_edit(Vector *db, int id);   // редактирование записи
void db_free(Vector *db);  // освобождение памяти


// функции для работы с бинарными файлами
int db_read(Vector *db, char *filename);    // чтение
void db_write(Vector *db, char *filename);   // запись


// функции для поиска в БД

// проверки, заполнено ли поле для поиска:
int is_str_filled(char *field);
int is_int_filled(int *field);
int is_float_filled(float *field);

// сравнение полей
int compare(Fields *record, Fields *search_rec);

// функции консольных команд для управления БД
int print_commands(char *database_file);    // вывод списка команд
void cmd_exit(Vector *db, char *database_file);    // завершение программы
void cmd_import(Vector *db, char *database_file, char *default_db); // импорт БД
void cmd_export(Vector *db, char *database_file);   // экспорт БД

#endif