#include "main.h"

// перезапись базы данных в файле
void db_write(Vector *db, char *filename){
    FILE *file = fopen(filename, "wb");
    if (file == NULL){
        return;
    }

    fwrite(db->data, sizeof(Fields), db->size, file);

    fclose(file);
}

// чтение базы данных
int db_read(Vector *db, char *filename){
    FILE *file = fopen(filename, "rb");
    if (file == NULL){
        return 1;
    }

    Fields record;

    while (fread(&record, sizeof(Fields), 1, file) == 1){
        db_add(db, record);
    }
    fclose(file);
    return 0;
}