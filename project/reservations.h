#ifndef CRR_RESERVATIONS
#define CRR_RESERVATIONS

#include <time.h>

/* Reservations */
struct Reservation {
    char room[50];
    char description[128];
    time_t start;
    time_t end;
};

struct Reservation* readreservation(FILE* fp);
int writereservation(FILE* fp, struct Reservation* r);

/* Schedules */
int readsched(FILE* fp, struct Reservation*** sched);

#endif
