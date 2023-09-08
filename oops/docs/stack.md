## Stack - Last In First Out(LIFO)
```c
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_SIZE 100


struct Stack{
    int items[MAX_SIZE];
    int top;
    int size;
};


void initialize(struct Stack *stack,int size){
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid stack size\n");
        return;
    }
    stack->top = -1; //top set to -1 indicates that it is empty currently
    stack->size = size;
}

bool isEmpty(struct Stack *stack){
    return (stack->top == -1); //return 0 or 1
}

bool isFull(struct Stack *stack){
        return (stack->top == stack->size-1); //return 0 or 1
}

void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        // check if stack is full?
        printf("stack is full\n");
        return;
    }

    // stack->top++;
    //stack->items[top] = value;
    stack->items[++(stack->top)] = value;
}

int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        //check if stacak is empty?
        printf("stack is empty\n");
        return -1; 
    }
    return stack->items[stack->top];
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("stack is empty\n");
        return -1; 
    }
    // stack->top--
    return stack->items[(stack->top)--];
}

int main()
{

    struct Stack stack;
    initialize(&stack,4);

    push(&stack,10);
    push(&stack,20);
    push(&stack,30);
    push(&stack,40);

    printf("top of element of stack is: %i\n",peek(&stack));
    pop(&stack);
    printf("top of element of stack is: %i\n",peek(&stack));

    printf("is stack empty: %d\n",isEmpty(&stack));
    printf("is stack full: %i\n",isFull(&stack));
    push(&stack,50);
    printf("is stack full: %i\n",isFull(&stack));


    return 0;
}
```

### Reverse an string using stacks
```c
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define MAX_SIZE 100

struct Stack{
    int items[MAX_SIZE];
    int top;
    int size;
};

void intitializationn(struct Stack *stack,int size){
    if(size <= 0 || size > MAX_SIZE){
        printf("invalid stack size\n");
        return;
    }
    stack->size = size;
    stack->top = -1;
}

bool isEmpty(struct Stack *stack){
    return (stack->top == -1);
}

bool isFull(struct Stack *stack){
    return (stack->top == stack->size-1);
}

void push(struct Stack *stack, int value){
    if(isFull(stack)){
        printf("stack is full\n");
        return;
    }
    stack->items[++(stack->top)] = value;
}

int peek(struct Stack *stack){
    if(isEmpty(stack)){
        printf("stack is empty\n");
        return -1;
    }
    return stack->items[stack->top];
}

int pop(struct Stack *stack){
    if(isEmpty(stack)){
        return -1;
    }
    return stack->items[stack->top--];
}

int size(struct Stack *stack){
    return (stack->top + 1);
}

void reversestring(char *str,int len){
    struct Stack stack;
    intitializationn(&stack,len);
    
    for(int i = 0; i<len; i++){
        push(&stack,str[i]);
    }

    for (int i = 0; i < len; i++) {
        str[i] = pop(&stack);
    }
}


int main() {


    char str[] = "Hello World!";
    int len = strlen(str);

    printf("before : %s\n",str);
    reversestring(str,len);
    printf("after : %s\n",str);

    return 0;
}


```

### Valid Parenthesis/Balanced Bracket
```c
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    char items[MAX_SIZE];
    int top;
};

void init(struct Stack *stack) {
    stack->top = -1;
}

bool isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

bool isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack *stack, char item) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}

char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return '\0'; 
    }
    return stack->items[stack->top--];
}

bool isBalanced(char *s) {
    struct Stack stack;
    init(&stack);

    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        char current = s[i];
        if (current == '(' || current == '{' || current == '[') {
            push(&stack, current);
        } else if (current == ')' || current == '}' || current == ']') {
            if (isEmpty(&stack)) {
                return false;
            }
            char top = pop(&stack);
            if ((current == ')' && top != '(') ||
                (current == '}' && top != '{') ||
                (current == ']' && top != '[')) {
                return false;
            }
        }
    }

    return isEmpty(&stack);
}

int main() {
    char str[] = "{[()]}";
    if (isBalanced(str)) {
        printf("The string contains balanced brackets.\n");
    } else {
        printf("The string does not contain balanced brackets.\n");
    }

    return 0;
}

```