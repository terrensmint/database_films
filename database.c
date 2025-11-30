#include "main.h"

db_init(Vector *db);  // инициализация БД
db_print(Vector *db);   // вывод БД на экран
db_add(Vector *db, Fields record);  // добавление новой записи в БД
db_search(Vector *db);   // поиск
db_delete(Vector *db, int id);   // удаление записи в БД
db_edit(Vector *db, int id);
db_free(Vector *db);  // освобождение памяти