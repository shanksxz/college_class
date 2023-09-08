## Pointer using const keyword
- A constant pointer in C cannot change the
address of the variable to which it is
pointing, i.e., the address will remain
constant.
- Therefore, we can say that if a constant
pointer is pointing to some variable, then it
cannot point to any other variable.

### Constant Pointer to Non-Constant Data
```c
int x = 10;
int y = 20;
int *const ptr = &x;
ptr = &y; //err
```
### Non-Constant Pointer to Constant Data
```c
const int y = 20;
const int *ptr = &y;
```

### Constant Pointer to Constant Data
```c
const int z = 30;
const int *const ptr = &z;
```

## Inline Function
- In an inline function, a function call is
replaced by the actual program code.
```c
inline int add(int a, int b) {
    return a + b;
}

int main() {
    int x = 5;
    int y = 10;

    int result = add(x, y);

    printf("Result: %d\n", result);

    return 0;
}
```

## Function Pointer

### Declaration
```c
int (*functionPtr)(int, int);
```
### Initialization
```c
int add(int a, int b) {
    return a + b;
} 
functionPtr = add;
```
### Using
```c
int result = functionPtr(5, 10);
```

### Function Pointers as Callback
```c
void process(int (*operation)(int, int), int a, int b) {
    int result = operation(a, b);
    printf("Result: %d\n", result);
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int main() {
    process(add, 5, 10);
    process(subtract, 20, 8);
    return 0;
}
```

## Sort array using pointers
```c
//bubble sort
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int array[] = {7, 2, 5, 1, 9, 3};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    bubbleSort(array, n);

    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}

```
```c
//using pointers
#include <stdio.h>

int main() {
    int array[] = {7, 2, 5, 1, 9, 3};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    int *ptr = array;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*(ptr + j) < *(ptr + i)) {
                int t = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = t;
            }
        }
    }

    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}

```


## qsort()
- Here's how qsort works:
- The ```compareFunction``` is called by qsort to compare two elements of the array at a time.
- Based on the comparison results, qsort rearranges the elements of the array to sort them in ascending order according to the comparison function.
- The sorting process continues recursively until the entire array is sorted.
```c
#include <stdio.h>
#include <stdlib.h>

// Comparison function for sorting integers in ascending order
int compareIntegers(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int arr[] = {5, 2, 9, 3, 6, 1, 8, 4, 7};
    int numElements = sizeof(arr) / sizeof(arr[0]);

    // Using qsort to sort the array
    qsort(arr, numElements, sizeof(int), compareIntegers);

    // Printing the sorted array
    for (int i = 0; i < numElements; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
```


## Variable number of parameters in functions
```c
#include <stdio.h>
#include <stdarg.h>

// function to calculate the sum of a variable number of integers
int sum(int num, ...) {
    va_list args;       // Ddeclare a va_list to hold the variable arguments
    va_start(args, num); // initialize the va_list with the variable arguments
    int result = 0;

    for (int i = 0; i < num; i++) {
        int value = va_arg(args, int); // get the next argument from the va_list
        result += value;
    }

    va_end(args); // clean up the va_list

    return result;
}

int main() {
    int total = sum(5, 10, 20, 30, 40, 50);
    printf("sum: %d\n", total);
    return 0;
}

```

## postfix valualation
```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define maxsize 100

struct stacks{
    int top;
    char arr[maxsize];
};
int init(struct stacks*s){
    s->top=-1;
    }
int isempty(struct stacks*s){
    return s->top==-1;
}
int isfull(struct stacks*s){
    return s->top==maxsize-1;
}
void push(struct stacks*s,char value){
    if(!isfull(s)){
        s->arr[++s->top]=value;
    }
    else{
        printf("stack is full");
    }
}
char pop(struct stacks*s){
    char value;
    if(!isempty(s)){
        // s->top--;
        value=s->arr[s->top--];
        return value;
    }
    else{
        printf("stack is empty");
        return '\0';
    }

}
int display(struct stacks *s){
    for(int i=0;i<=s->top;i++)
    {
        printf("%d ",s->arr[i]);
    }
}
int postfixeval(char postfix[]){
    struct stacks s1;
    init(&s1);
    for (int i = 0; i < strlen(postfix); i++)
    {
        char ch=postfix[i];

        if(isdigit(ch)){
            int result=ch-'0';
            push(&s1,result);
        } 
        else if(ch=='+'){
            int a=pop(&s1);
            int b=pop(&s1);
            int c=a+b;
            push(&s1,c);
        }
        else if(ch=='-'){
            int a=pop(&s1);
            // pop(&s1);
            int b=pop(&s1);
            int c=a-b;
            push(&s1,c);
        }
        else if(ch=='*'){
            int a=pop(&s1);
            // pop(&s1);
            int b=pop(&s1);
            int c=a*b;
            push(&s1,c);
        }
        else if(ch=='/'){
            int a=pop(&s1);
            // pop(&s1);
            int b=pop(&s1);
            int c=a/b;
            push(&s1,c);
        }
    }
    if(!isempty(&s1)){
        return pop(&s1);
    }
    else{
        printf("error");
        exit(1);
    }
    
}

int main(){
    char expression[maxsize];
    printf("Enter a postfix expression: ");
    gets(expression);

    int result = postfixeval(expression);
    printf("Result: %d\n", result);

    return 0;
}
```

## infix to postfix
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define Maxsize 100
// char ch;
struct stacks
{
    int top;
    char arr[Maxsize];
};

void init(struct stacks *s)
{
    s->top = -1;
}

// s->top = -1;
int isfull(struct stacks *s)
{
    return s->top == Maxsize - 1;
}
int isempty(struct stacks *s)
{
    return s->top == -1;
}

void push(struct stacks *s, char value)
{
    if (!isfull(s))
    {
        s->top++;
        s->arr[s->top] = value;
    }
    else
    {
        printf("Stack is full");
    }
}
char pop(struct stacks *s)
{
    if (!isempty(s))
    {
        return s->arr[s->top--];
    }
    else
    {
        printf("stack is empty");
        return '\0';
    }
}
int precedence(char operator)
{
    if (operator== '*' || operator== '/')
    {
        return 2;
    }
    else if (operator== '+' || operator== '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void infixtopostfix(char infix[], char postfix[])
{
    struct stacks s1;
    init(&s1);

    int postfixindex = 0;
    for (int i = 0; i < strlen(infix); i++)
    {
        char ch = infix[i];
        if (isdigit(ch))
        {
            postfix[postfixindex++] = ch;
        }
        else if (ch == '(')
        {
            push(&s1, ch);
        }
        else if (ch == ')')
        {
            while (!isempty(&s1) && s1.arr[s1.top] != '(')
            {
                postfix[postfixindex++] = pop(&s1);
                // postfixindex++;
            }
            pop(&s1);
        }
        else
        {
            while (!isempty(&s1) && precedence(ch) <= precedence(s1.arr[s1.top]))
            {
                postfix[postfixindex++] = pop(&s1);
            }
            push(&s1, ch);
        }
    }
        while (!isempty(&s1))
        {
            postfix[postfixindex++] = pop(&s1);
        }
        postfix[postfixindex] = '\0';
}
int main()
{
    char infix[Maxsize];
    char postfix[Maxsize];

    printf("Enter an infix expression: ");
    gets(infix);

    infixtopostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
```