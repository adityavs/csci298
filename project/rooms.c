#include <stdlib.h>
#include <string.h>

#include "crr.h"
#include "rooms.h"

int readrooms(FILE* fp, char*** rooms) {
    (*rooms) = malloc(sizeof(char*)*BUFSIZE);
    if (!(*rooms)) {
        fputs("Error allocating memory\n", stderr);
        return 0;
    }
    int n;
    for (n=0; n<BUFSIZE; n++) {
        (*rooms)[n] = malloc(sizeof(char)*MAXROOMLEN);
        if (!(*rooms)[n]) {
            fputs("Error allocating memory\n", stderr);
            return 0;
        }
    }
    int r = 1, i = 0;
    while (fgets((*rooms)[i], MAXROOMLEN, fp)) {
        if (i>=BUFSIZE-1) {
            r++;
            (*rooms) = realloc((*rooms), sizeof(char*)*BUFSIZE*r);
            if (!(*rooms)) {
                fputs("Error allocating memory\n", stderr);
                return 0;
            }
            for (n=BUFSIZE*(r-1); n<BUFSIZE*r; n++) {
                (*rooms)[n] = malloc(sizeof(char)*MAXROOMLEN);
                if (!(*rooms)[n]) {
                    fputs("Error allocating memory\n", stderr);
                    return 0;
                }
            }
        }
        if (strcmp((*rooms)[i], "\n")) {
            //printf("%s", (*rooms)[i]);
            ++i;
        }
    }

    /* Return array length. */
    return i;
}

/*
room_available(room, time) {
    qsort
    if (time < room->start || time >= room->end) {
        return ;
    } else {
        return ;
    }
}


rooms_available(rooms, roomslen, time) {
    int i;
    for (i=0; i<roomslen; i++) {
        if (rooms[i]->start) {

        }
    }
}
*/
