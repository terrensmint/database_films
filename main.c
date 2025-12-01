#include "main.h"

int main(){

    // стартовые настройки
    char *default_db = "example.bin"; // база данных по умолчанию
    char database_file[STR_LEN]; // бинарный файл с базой данных
    strcpy(database_file, default_db);
    Vector db;
    db_init(&db);
    db_read(&db, database_file);

    int run = 1;

    printf("=================================\n");
    printf("*    Управление базой данных    *\n");
    printf("*            Netflix            *\n");
    printf("=================================\n");
    
    // бесконечный цикл для текстового меню
    while (run){
        int command = print_commands(database_file);

        printf("\n");
        switch (command){
            case 0:     // закрытие программы
                cmd_exit(&db, database_file);
                run = 0;
                break;

            case 1:     // импорт базы данных
                cmd_import(&db, database_file, default_db);
                break;

            case 2:     // экспорт базы данных
                cmd_export(&db, database_file);
                break;

            case 3:     // вывод базы данных
                db_print(&db);
                break;

            case 4:     // добавление записи в базу данных
                cmd_add(&db);
                // пользователь заполняет запись по полям
                // Fields record;
                // db_add(&db, record);
                break;

            case 5:     // удаление записи из базы данных
                // пользователь вводит id записи, которую необходимо удалить
                // db_delete(%db, id);
                break;

            case 6:     // поиск записи в базе данных
                db_search(&db);
                break;

            case 7:     // редактирование записи в базе данных
                // пользователь вводит id записи, которую необходимо редактировать
                // db_edit(%db, id);
                break;

            default:
                printf("====[ Неверный ввод ]====\n");
                printf("Команды с номером %d не существует!\n", command);
        }

        // подтверждение для возвращения в основное меню с командами
        if (run == 1){
            clear_buffer();
            printf("Нажмите Enter, чтобы вернуться в меню...\n");
            clear_buffer();
        }
    }

    db_free(&db);

    return 0;
}
