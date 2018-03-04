#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include "ncurses.h"
#include "func.h"

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

int main(int argc, char *argv[])
{
    printf("Begin - Main\n");
    int counter;
    char input[127];
    gets(input);
    enum State typing = 2; // Variable for tracking state of user's typing
    printf("Строка: %s\nДлина строки: %d",input,strlen(input));
    for(counter = 0; counter < strlen(input); counter++){
        if(input[counter] != ' ' && input[counter] != '\n'){
            if(typing == 2){
                //If starting new word and new line
                typing = 0;
            } else if (typing == 1){
                //If Starting new word, but not new line
                typing = 0;
            } else if (typing == 0){
                //If adding new letter to word
            }
        } else if (input[counter] == ' ' && input[counter] != '\n'){
            //If previous word ended, but not line
            typing = 1;
        } else if (input[counter] == '\n'){
            //If ending of line and word
            typing = 2;
        } else {
            //Non-correct input
            printf("[ERR] = Non-correct input string.");
            break;
        }
    }
/*
    if (!initscr())
    {
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(1);
    }
    initscr();
    curs_set(0);
    refresh();
    WINDOW *win = newwin(30, 30, 10, 10);
    text txt = init_text();
    box(win, 0, 0);
    wrefresh(win);
    getch();

    delwin(win);
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
*/  

    printf("End - Main\n");
    return 0;
}