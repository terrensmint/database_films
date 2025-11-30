#include "main.h"

int main(){

    char *database = "example.bin"; // бинарный файл с базой данных

    // бесконечный цикл для текстового меню
    int run = 1;
    while (run){
        run = 0;
    }

    Vector db;
    db_init(&db);

    // Тестовые данные Netflix

    Fields sample_data[] = {
        {1, "Stranger Things", "Duffer Brothers", 2016, 8.7},
        {2, "The Crown", "Peter Morgan", 2016, 8.6},
        {3, "The Witcher", "Lauren Schmidt", 2019, 8.2},
        {4, "Breaking Bad", "Vince Gilligan", 2008, 9.5},
        {5, "Matrix", "The Wachowskis", 1990, 8.7}
    };

        // Добавляем все записи в базу
    int sample_count = sizeof(sample_data) / sizeof(sample_data[0]);
    for (int i = 0; i < sample_count; i++) {
        db_add(&db, sample_data[i]);
    }

    db_write(&db, database);

    db_print(&db);

    db_delete(&db, 3);
    db_delete(&db, 7);

    db_print(&db);

    db_free(&db);

    return 0;
}
