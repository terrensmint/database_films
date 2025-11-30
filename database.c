#include "main.h"

// инициализация БД
void db_init(Vector *db){
    db->data = NULL;
    db->size = 0;
    db->capacity = 5;
}

// вывод БД на экран
void db_print(Vector *db){
    if (db->size == 0){
        printf("База данных пуста.\n");
        return;
    }
    
    for (int i = 0; i < db->size; i++){
        Fields record = db->data[i];
        printf("ID: %d\n", record.id);
        printf("Title: %s\n", record.title);
        printf("Director: %s\n", record.director);
        printf("Release: %d\n", record.release_year);
        printf("Rating: %f\n", record.rating);
    }
}

// добавление новой записи в БД
void db_add(Vector *db, Fields record){
    if (db->size >= db->capacity){
        db->capacity = db->capacity * 2;
        db->data = realloc(db->data, db->capacity * sizeof(Fields));
    }

    db->data[db->size] = record;    // добавляем запись в конец массива
    db->size++;
}

// меню поиска
void db_search(Vector *db){
    // запрашивает у пользователя, по каким полям сравниваем
    // пользователь заполняет Fields search_rec - запись для поиска, в ней м.б. пустые поля
    // через search.c программа сравнивает все записи БД с search_rec
    // если находятся совпадения, записи выводятся в консоль
}

// удаление записи в БД
void db_delete(Vector *db, int id){
    // находит запись по id
    // если запись найдена: сдвигает записи влево
    db->size--;
}

// редактирование записи
void db_edit(Vector *db, int id){
    // находит запись
    // запрашивает, какое поле изменить
    // запрашивает значение, на которое необходимо изменить поле
    // записывает данные в запись
}

// освобождение памяти
void db_free(Vector *db){
    if (db->data != NULL){
        free(db->data);
        db->data = NULL;
    }
    db->size = 0;
}