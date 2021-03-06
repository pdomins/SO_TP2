#ifndef SYSCALLS_H
#define SYSCALLS_H

#include <types.h>
#include <stdint.h>
#include <lib64.h>

int read(unsigned int fd, char *buffer, int length);

int write(unsigned int fd, char *buffer, int row, int col, int color);

void draw(int *matrix, int row, int col, int rows, int columns);

void clearScreen();

void getTime(date myDate);

void getRegisters(uint64_t *registers);

void memoryDump(char *dir, char *dump);

void setAlarm(void (*func)(void), int flag);

int getHeight();

int getWidth();

void getProcessesList();

unsigned int
createProcess(uint64_t *entryPoint, int foreground, uint64_t fdIn, uint64_t fdOut, uint64_t first, uint64_t second,
              uint64_t third, char *name);

void killProcess(unsigned int pid);

void changeProcessPriority(unsigned int pid, int priority);

void changeProcessState(unsigned int pid);

unsigned int getPid();

unsigned int getElapsedTicks();

void _exit(uint64_t value);

void *getMem(uint64_t size);

void freeMem(void *ptr);

void getMemInfo(char *info);

int semOpen(char *semId, uint64_t initialValue);

int semClose(char *semId);

int semPost(char *semId);

int semWait(char *semId);

int semInfo(char *buffer);

int pipeOpen(int fd[2]);

int pipeClose(int fd);

int pipeInfo(char *buffer);

int waitPid(int pid);

int yield();

#endif