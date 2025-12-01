#include "main.h"

void clear_buffer(){    // очистка буфера
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int print_commands(char *database_file){
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
        clear_buffer();
    }
    return command;
}

void cmd_exit(Vector *db, char *database_file){
    char *autosave = "autosave.bin";    // файл для автосохранения
    int is_correct = 1;     // флаг для предупреждений изза некорректного ввода

    printf("Сохранить изменения перед выходом?\n");
    printf("0 - Выйти БЕЗ сохранения.\n");
    printf("1 - Сохранить изменения и выйти.\n");

    int answer;
    if (scanf("%d", &answer) == 0){     // если не удалось считать число с пользовательского ввода
        is_correct = 0;
    }

    switch (answer){
        case 0:     // выйти без сохранения
            break;
        case 1:     // выйти с сохранением
            db_write(db, database_file);
            printf("База данных сохранена!\n");
            break;
        default:    // другие числа
            is_correct = 0;
            break;
    }

    if (is_correct == 0){
        printf("\n====[ ПРЕДУПРЕЖДЕНИЕ ]====\n");
        printf("Введен некорректный ввод. Изменения будут сохранены в файл %s\n", autosave);
        db_write(db, autosave);
    }

    printf("\n====[ Выход из программы ]====\n");
    return;
}

void cmd_import(Vector *db, char *database_file, char *default_db){
    // очистка памяти структуры для новой БД
    db_free(db);
    db_init(db);
    printf("Введите название файла, который необходимо импортировать:\n");
    if (scanf("%s", database_file) == 0){
        printf("Введено некорректное название. Будет импортирована база данных по умолчанию.\n");
    }
    if (db_read(db, database_file) == 1){  // если не получилось открыть файл
        printf("====[ Ошибка ]====\n");
        printf("Файл с названием '%s' не найден.\n", database_file);
        strcpy(database_file, default_db);  // возвращаемся к файлу по умолчанию
        db_read(db, database_file);
    } else{
        printf("База данных успешно импортирована!\n");
    }
}

void cmd_export(Vector *db, char *database_file){
    char database_write[STR_LEN];
    printf("Введите название файла, в который хотите экспортировать базу данных.\n");
    printf("(Введите 0 для экспорта в текущий файл)\n");
    if (scanf("%s", database_write) == 0){
        printf("Введено некорректное название. Экспорт отменен.\n");
        return;
    }
    if (strcmp(database_write, "0") != 0){      // если не введен 0, переключаемся на базу данных, которую ввел пользователь
        strcpy(database_file, database_write);
    }

    db_write(db, database_file);
    printf("База данных успешно сохранена в файл %s!\n", database_file);
}

void cmd_add(Vector *db){
    printf("====[ Создание новой записи ]====\n");
    printf("Заполните поля новой записи:\n\n");
    
    Fields record;

    printf("[ID] = %d\n", db->data[db->size-1].id + 1);
    record.id = db->data[db->size-1].id + 1;
    
    printf("[TITLE] = ");
    while (scanf("%s", &record.title) == 0){
        printf("\n====[ Неверный ввод ]====\n");
        printf("Введите наименование фильма: ");
        clear_buffer();
    }
    clear_buffer();

    printf("[DIRECTOR] = ");
    while (scanf("%s", &record.director) == 0){
        printf("\n====[ Неверный ввод ]====\n");
        printf("Введите имя режиссера: ");
        clear_buffer();
    }
    clear_buffer();

    printf("[YEAR OF RELEASE] = ");
    while (scanf("%d", &record.release_year) == 0){
        printf("\n====[ Неверный ввод ]====\n");
        printf("Введите год выпуска фильма: ");
        clear_buffer();
    }
    clear_buffer();

    printf("[RATING] = ");
    while (scanf("%f", &record.rating) == 0){
        printf("\n====[ Неверный ввод ]====\n");
        printf("Введите рейтинг фильма: ");
        clear_buffer();
    }

    db_add(db, record);
}