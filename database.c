#include "main.h"

// инициализация БД
void db_init(Vector *db){
    db->size = 0;
    db->capacity = 5;
    
    db->data = malloc(db->capacity *sizeof(Fields));
}

// вывод БД на экран
void db_print(Vector *db){
    // читает файл
    // выводит записи в консоль
}

// добавление новой записи в БД
void db_add(Vector *db, Fields record){
    if (db->size < db->capacity){
        
        // добавляет запись в БД
        
        db->size++;
    } else{
        db->capacity = db->capacity * 2;
        db->data = realloc(db->data, db->capacity * sizeof(Fields));
        
        // добавляет запись в БД
        
        db->size++;
    }
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