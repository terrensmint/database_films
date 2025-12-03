#include "main.h"

int main(){

    // стартовые настройки
    char *default_db = "example.bin"; // название базы данных по умолчанию
    char database_file[STR_LEN]; // название файла с базой данных
    strcpy(database_file, default_db);
    Vector db;  // база данных - умный массив
    db_init(&db);   // инициализация
    db_read(&db, database_file);    // выписываем бд из файла в вектор

    int run = 1;    // флаг для бесконечного цикла текстового меню

    printf("=================================\n");
    printf("*    Управление базой данных    *\n");
    printf("*            Netflix            *\n");
    printf("=================================\n");
    
    // бесконечный цикл для текстового меню
    while (run){
        int command = print_commands(database_file);    // вывод списка команд

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
                break;

            case 5:     // удаление записи из базы данных
                cmd_delete(&db);
                break;

            case 6:     // поиск записи в базе данных
                cmd_search(&db);
                break;

            case 7:     // редактирование записи в базе данных
                cmd_edit(&db);
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
