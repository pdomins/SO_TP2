#ifndef PCB_H
#define PCB_H

#include <stdint.h>

#define READY 0
#define BLOCKED 1
#define KILLED 2
#define RESIGN 3

typedef struct PCB {
    unsigned int pid;
    unsigned int state;
    uint64_t *rsp;
    uint64_t *rbp;
    unsigned int priority;
    unsigned int tickets;
    unsigned int foreground;
    unsigned int fdIn;
    unsigned int fdOut;
    unsigned int waitingPid;
    char name[20];
} PCB;

#endif