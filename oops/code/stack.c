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