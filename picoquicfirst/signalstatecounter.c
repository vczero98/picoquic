#include <stdio.h>
#include <stdlib.h>
#include "signalstatecounter.h"

int outputSignalStateCounter(struct SignalStateCounter *ssc, int initialise) {
    printf("State 1: %d\n", ssc->state1);
    printf("State 2: %d\n", ssc->state2);

    if (initialise) {
        ssc->state1 = 0;
        ssc->state2 = 0;
    }

    return 0;
}

int initSignalStateCounter(struct SignalStateCounter **ssc) {
    *ssc = malloc(sizeof(struct SignalStateCounter));
    if (*ssc == NULL) return -1;

    (*ssc)->state1 = 0;
    (*ssc)->state2 = 0;

    return 0;
}

int freeSignalStateCounter(struct SignalStateCounter *ssc) {
    free(ssc);
    return 0;
}