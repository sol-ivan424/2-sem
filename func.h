#include <stdio.h>
#include <stdlib.h>

const char* msgs[2];
const int NMsgs;

typedef struct stack{
    int top;
    int* items;
}stack;

int getInt(int* a);
int dialog(const char* msgs[], int N);
int not(stack* st);
void push(stack* st, int x);
char pop(stack* st);
stack* add();
int len(stack* st);
void clear(stack* st);
