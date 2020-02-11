struct SignalStateCounter {
    int state1, state2;
};

/* If initialise is 1, the initial state will be restored */
int outputSignalStateCounter(struct SignalStateCounter *ssc, int initialise);

int initSignalStateCounter(struct SignalStateCounter **ssc);
int freeSignalStateCounter(struct SignalStateCounter *ssc);