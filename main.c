#include "stdio.h"
#include "ncurses.h"
#include <stdlib.h>

//Буква
typedef struct list_letter{
    struct letter *prev;
    struct letter *next;
    chtype lett;
} letter;

//Слово
typedef struct list_word{
    chtype *letters;
    struct word *prev;
    struct word *next;
} word;

//Строка
typedef struct list_line{
    struct word *words;
    struct line *prev;
    struct word *next;
} line;

//Текст
typedef struct list_text{
    struct line *lines;
} text;

/*
    Иерархия:
    Буква -> Слово -> Строка -> Текст
    Слово = б + ... + б + '\s';
    Строка = сл + ... + сл + '\n';
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

int main(int argc, char *argv[]){

    if (!initscr())
    {
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(1);
    }

    initscr();

        int ch;
     nodelay(stdscr, TRUE);
     for (;;) {
          if ((ch = getch()) == ERR) {
              // пользователь не отвечает
               
          }
          else {
              // пользователь нажал клавишу

          }
     }
       

    endwin();

    return 0;
}