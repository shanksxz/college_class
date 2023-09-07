## Queue - First in First Out
- ```simple queue```, when the rear pointer reaches the end of the queue (i.e., when rear equals the maximum capacity of the queue minus one), it means that the queue is full. This situation is a common condition to check to determine if you can enqueue more elements into the queue without causing an overflow.
    ```c
    if (rear == MAX_SIZE - 1) {
        // queue is full, you cannot enqueue more elements.
        printf("queue is full\n");
    } else {
    }
    ```
- ```circular queue```, when rear is equal to front, and both are non-negative values, it means the circular queue is full. In this case, you have reached the maximum capacity of the circular queue, and you cannot enqueue more elements without dequeuing some elements first.
    ```c
    // Assuming front and rear are integers initialized appropriately.
   if (front == (rear + 1) % MAX_SIZE) {
        // The circular queue is full.
        printf("Queue is full\n");
    } else {
    }
    ```

```c

//for both simple and circular queue
#include<stdio.h>
#include<stdbool.h>

#define MAX_SIZE 100

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
    int size;
};


void initialize(struct Queue *queue, int size){
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid queue size\n");
        return;
    }
    queue->front = -1; //empty
    queue->rear = -1;//empty
    queue->size = size;
}

bool isEmpty(struct Queue *queue){
    return (queue->front == -1); // return 0 or 1
}

bool isFull(struct Queue *queue){
    return ((queue->rear + 1) % queue->size == queue->front);  // return 0 or 1
}

void enqueue(struct Queue *queue,int value){
    if(isFull(queue)){
        printf("queue is full\n");
        return;
    }

    if(isEmpty(queue)){
        // if empty set both front and rear to 0
        queue->front = 0;
        queue->rear = 0;
    }else {
        queue->rear = (queue->rear + 1) % queue->size;
    }

    queue->items[queue->rear] = value;
}

void dequeue(struct Queue *queue){
    if (isEmpty(queue)) {
        printf("queue is empty\n");
        return;
    }
    if(queue->front==queue->rear){
        //if only 1 element is present
        queue->front = -1;
        queue->rear = -1;
    }else{
        //for more than 1
        queue->front = (queue->front+1) % queue->size;
    }
}

int front(struct Queue *queue){
    if (isEmpty(queue)) {
        printf("queue is empty\n");
        return -1;
    }
    return queue->items[queue->front];
}


int main() {

    struct Queue queue;
    initialize(&queue,3);

    printf("is queue empty: %i\n",isEmpty(&queue));
    printf("is queue full: %i\n",isFull(&queue));

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("is queue empty: %i\n",isEmpty(&queue));
    printf("is queue full: %i\n",isFull(&queue));


    printf("front ele of queue: %i\n",front(&queue));
    dequeue(&queue);
    printf("front ele of queue: %i\n",front(&queue));


    return 0;
}
```