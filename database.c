#include "main.h"

// инициализация БД
void db_init(Vector *db){
    db->size = 0;
    db->capacity = 5;
    db->data = malloc(sizeof(Fields) * db->capacity);
    if (db->data == NULL){
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
}

// вывод БД на экран
void db_print(Vector *db){
    if (db->size == 0){
        printf("База данных пуста.\n");
        printf("Импортируйте базу данных или добавьте новые элементы.\n");
        return;
    }
    printf("=====================\n");
    for (int i = 0; i < db->size; i++){
        Fields record = db->data[i];
        printf("ID: %d\n", record.id);
        printf("Title: %s\n", record.title);
        printf("Director: %s\n", record.director);
        printf("Release: %d\n", record.release_year);
        printf("Rating: %.1f\n", record.rating);
        printf("--------\n");
    }
    printf("=====================\n");
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

int compare(Fields record, Fields search_rec){
    // Условность: -1 для числовых полей, "" для строковых значит незаполненное поле.
    if (search_rec.id != -1 && record.id != search_rec.id) return 0;
    if (strcmp(search_rec.title, "") != 0 && strcmp(record.title, search_rec.title) != 0) return 0;
    if (strcmp(search_rec.director, "") != 0 && strcmp(record.director, search_rec.director) != 0) return 0;
    if (search_rec.release_year != -1 && record.release_year != search_rec.release_year) return 0;
    if (search_rec.rating != -1.0 && record.rating != search_rec.rating) return 0;

    return 1;
}

// меню поиска
int db_search(Vector *db, Fields search_rec){
    int is_found = 0;   // флаг, найдена ли хотя бы одна запись

    printf("=====================\n");
    for (int i = 0; i < db->size; i++){
        if (compare(db->data[i], search_rec) == 1){
            Fields record = db->data[i];
            printf("ID: %d\n", record.id);
            printf("Title: %s\n", record.title);
            printf("Director: %s\n", record.director);
            printf("Release: %d\n", record.release_year);
            printf("Rating: %.1f\n", record.rating);
            printf("--------\n");
            is_found = 1;
        }
    }
    printf("Поиск завершен.\n");
    if (is_found == 0){
        printf("В результате поиска не найдена ни одна запись.\n");
    }
    printf("=====================\n");
    return is_found;
}

// удаление записи в БД
void db_delete(Vector *db, int id){
        if (db == NULL) {
        return;
    }
    
    // Ищем элемент по id
    for (int index = 0; index < db->size; index++) {
        if (db->data[index].id == id) {
            for (int j = index; j < db->size - 1; j++) {
                db->data[j] = db->data[j + 1];
            }
            db->size--;
            printf("Запись успешно удалена!\n");
            return;
        }
    }

    printf("Не удалось найти запись по ID = %d\n", id);
    return;
}

// редактирование записи
void db_edit(Vector *db, Fields record){
    for (int i = 0; i < db->size; i++){
        if (db->data[i].id == record.id){
            strcpy(db->data[i].title, record.title);
            strcpy(db->data[i].director, record.director);
            db->data[i].release_year = record.release_year;
            db->data[i].rating = record.rating;
            return;
        }
    }
}

// освобождение памяти
void db_free(Vector *db){
    if (db->data != NULL){
        free(db->data);
        db->data = NULL;
    }
    db->size = 0;
}