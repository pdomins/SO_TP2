// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include <stdio.h>
#include <syscalls.h>
#include <standardIO.h>

#define CHAR_COLOR 0xFFFFFF

void println(char *toPrint) {
    printcFrom(toPrint, -1, -1, CHAR_COLOR);
    print("\n");
}

void print(char *toPrint) {
    printcFrom(toPrint, -1, -1, CHAR_COLOR);
}

void printc(char *toPrint, int color) {
    printcFrom(toPrint, -1, -1, color);
}

void printcln(char *toPrint, int color) {
    printc(toPrint, color);
    print("\n");
}

void printcFrom(char *toPrint, int row, int col, int color) {
    write(1, toPrint, row, col, color);
}

void printFrom(char *toPrint, int row, int col) {
    printcFrom(toPrint, row, col, CHAR_COLOR);
}

char getChar() {
    char c[2] = {0};
    if(read(0, c, 1) != -1) {
        return c[0];
    }
    return -1;
}

void removeChar() {
    print("\b");
}

void putChar(char c) {
    char buffer[2] = {0};
    *buffer = c;
    print(buffer);
}

void putCharFrom(char c, int row, int col) {
    char buffer[2] = {0};
    *buffer = c;
    printFrom(buffer, row, col);
}

void printInt(int64_t num) {
    char buff[64];
    if(num < 0) {
        num *= -1;
        print("-");
    }
    itoaTruncate(num, buff, 64);
    print(buff);
}