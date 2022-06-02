#include "func.h"

int not(stack* st){
    char c;

    printf("Input reverse notation: ");
    do {
        scanf("%c", &c);
        if (c != '+' && c != '-' && c != '*' && c != '/' && c != '=' && c != '\n'){
            int s = c - '0';
            push(st, s);
        }
        if (c == '+') {
            if (len(st) < 2){
                printf("Invalid input\n");
                clear(st);
                return 1;
            }
            int n = pop(st);
            int m = pop(st);

            int s = (n + m) ;
            push(st, s);
        }
        if (c == '-') {
            if (len(st) < 2){
                printf("Invalid input\n");
                clear(st);
                return 1;
            }
            int n = pop(st);
            int m = pop(st);

            int s = (m - n);
            push(st, s);
        }
        if (c == '*') {
            if (len(st) < 2){
                printf("Invalid input\n");
                clear(st);
                return 1;
            }
            int n = pop(st);
            int m = pop(st);

            int s = (n * m) ;
            push(st, s);
        }
        if (c == '/') {
            if (len(st) < 2){
                printf("Invalid input\n");
                clear(st);
                return 1;
            }
            int n = pop(st);
            int m = pop(st);

            int s = (m / n) ;
            push(st, s);
        }
    } while (c != '=');
    printf("Answer: %d\n", pop(st));
    return 1;
}

int getInt(int* x){
    int y;
    do{
        y = scanf("%d", x);
        if (y < 0){
            return 0;
        }
        if (y == 0){
            printf("%s\n", "Error! Repeat input");
            scanf("%*c");
        }
    } while (y == 0);
    return 1;
}

stack* add(){
    stack *st = (stack*)malloc(sizeof(stack));
    st->items = (int*)malloc(sizeof(int)*10);
    st->top = -1;
    return st;
}

int len(stack* st){
    return st->top + 1;
}

void push(stack* st, int x){
    st->items[++st->top] = x;
}

char pop(stack* st){
    return st->items[st->top--];
}

void clear(stack* st){
    free(st->items);
    free(st);
}

int dialog(const char* msgs[], int N){
    char* errmsg = "";
    int ch;
    int i, j;

    for(i = 0; i < N; ++i)
    puts(msgs[i]);

    do{
        puts(errmsg);
        errmsg = "You are wrong. Repeate, please!";
        printf("Make your choice:--> ");
        j = getInt(&ch);
        if(j == 0)
        ch = 0;
    } while(ch < 0 || ch >= N);

    return ch;
}

