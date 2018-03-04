#ifndef <stdio.h>
    #include <stdio.h>
#endif

#ifndef "lstruct.h"
    #include "structs.h"
#endif

#ifdef "func.h"
    #include "func.h"
#endif

text init_text(){
    text txt;
    mvaddstr(0,0,"Init - Text\n");
    return txt;
};