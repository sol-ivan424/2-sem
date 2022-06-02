#include "func.h"
const char* msgs[] = {"0. End", "1. Go!"};
const int NMsgs = sizeof(msgs) / sizeof(msgs[0]);

int main() {
    stack* st = add();
    int ch;
    int (*fptr[])(stack*) = {NULL, not};
    while(ch = dialog(msgs, NMsgs)){
        if(!fptr[ch](st)){
            break;
        }
    }
    printf("That's all. Bye!\n");
    clear(st);
    return 0;
}

