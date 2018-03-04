#pragma once
#include "ncurses.h"
#include <stdio.h>

/*
    Иерархия:
    Буква -> Слово -> Строка -> Текст
    Слово = б + ... + б;
    ' ' - разделяющий слова символ;
    Строка = сл + ... + сл;
    '\n' - разделяющий строки символ
    Текст = стр + ... + стр + ...;

    1-ая буква:
    chtype ..
    *prev = void*;
    *next = 2 буква; (появляется только после второй буквы)
    n-ая буква:
    chtype ..
    *prev = *((n-1)-ая буква)
    *next = void*; (появляется после встречи '\s')
    Аналогично для строк и текста.
*/

//Состояние ввода
enum State{
    LW,//In-Line and In-Word input
    LNW,//In-Line but not In-Word input
    NLNW,//Not Line and Word input
};

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