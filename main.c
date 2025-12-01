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
        printf("\n");
        printf("===[ Текущая база данных: %s ]===\n", database_file);
        printf("\nСписок команд для управления базой данных:\n");
        printf("--------\n");
        printf("0 - Завершить работу программы.\n");            // run = 0
        printf("1 - Импортировать базу данных.\n");             // db_read
        printf("2 - Сохранить базу данных.\n");                 // db_write
        printf("--------\n");
        printf("3 - Вывести базу данных на экран.\n");          // db_print
        printf("4 - Добавить запись в базу данных.\n");         // db_add
        printf("5 - Удалить запись из базы данных.\n");         // db_delete
        printf("6 - Найти запись в базе данных.\n");            // db_search
        printf("7 - Редактировать запись в базе данных.\n");    // db_edit
        printf("--------\n");
        printf("Введите номер команды: ");
        int command;
        while (scanf("%d", &command) == 0){
            printf("\n====[ Неверный ввод ]====\n");
            printf("Пожалуйста, введите номер команды: ");
            
            // очистка буфера
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        printf("\n");
        switch (command){
            case 0:     // закрытие программы
                run = 0;
                break;

            case 1:     // импорт базы данных
                // очистка памяти структуры для новой БД
                db_free(&db);
                db_init(&db);
                printf("Введите название файла, который необходимо импортировать:\n");
                if (scanf("%s", &database_file) == 0){
                    printf("Введено некорректное название. Будет импортирована база данных по умолчанию.\n");
                }
                if (db_read(&db, database_file) == 1){  // если не получилось открыть файл
                    printf("====[ Ошибка ]====\n");
                    printf("Файл с названием '%s' не найден.\n", database_file);
                    strcpy(database_file, default_db);  // возвращаемся к файлу по умолчанию
                    db_read(&db, database_file);
                } else{
                    printf("База данных успешно импортирована!\n");
                }
                break;

            case 2:     // экспорт базы данных
                char database_write[STR_LEN];
                printf("Введите название файла, в который хотите экспортировать базу данных.\n");
                printf("(Введите 0 для экспорта в текущую базу данных)\n");
                if (scanf("%s", &database_write) == 0){
                    printf("Введено некорректное название. Экспорт отменен.\n");
                    break;
                }
                if (strcmp(database_write, "0") != 0){
                    strcpy(database_file, database_write);
                }

                db_write(&db, database_file);
                printf("База данных успешно сохранена в файл %s!\n", database_file);
                break;

            case 3:
                db_print(&db);
                break;

            case 4:
                // пользователь заполняет запись по полям
                // Fields record;
                // db_add(&db, record);
                break;

            case 5:
                // пользователь вводит id записи, которую необходимо удалить
                // db_delete(%db, id);
                break;

            case 6:
                db_search(&db);
                break;

            case 7:
                // пользователь вводит id записи, которую необходимо редактировать
                // db_edit(%db, id);
                break;

            default:
                printf("====[ Неверный ввод ]====\n");
                printf("Команды с номером %d не существует!\n", command);
        }

        // подтверждение для возвращения в основное меню с командами
        if (run == 1){
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Нажмите Enter, чтобы вернуться в меню...\n");
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }

    db_free(&db);

    return 0;
}
