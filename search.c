#include "main.h"

// проверки, заполнено ли поле для поиска:
int is_str_filled(char *field);
int is_int_filled(int *field);
int is_float_filled(float *field);

// сравнение полей
int compare(Fields *record, Fields *search_rec);