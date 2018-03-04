#include <stdlib.h>
#include <string.h>
#include "ncurses.h"
#include "lstruct.h"

text init_text(){
    text txt;
    mvaddstr(0,0,"Init - Text\n");
    return txt;
};