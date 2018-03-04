#include "ncurses.h"
#include <stdio.h>

//Буква
typedef struct list_letter{
    struct list_letter *prev;
    struct list_letter *next;
    chtype lett;
} letter;

//Слово
typedef struct list_word{
    chtype *letters;
    struct list_word *prev;
    struct list_word *next;
} word;

//Строка
typedef struct list_line{
    word *words;
    struct list_line *prev;
    struct list_word *next;
} line;

//Текст
typedef struct list_text{
    line *lines;
} text;