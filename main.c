#include "stdio.h"
#include "ncurses.h"

int main(int argc, char *argv[]){

    initscr();

    move(10,30);
    printw("Hello World!");
    refresh();
    getch();

    endwin();

    return 0;
}