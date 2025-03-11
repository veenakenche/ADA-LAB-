#define MAX_SIZE 100

typedef struct {
    int inputStack[MAX_SIZE];
    int outputStack[MAX_SIZE];
    int inputTop;
    int outputTop;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->inputTop = -1;
    queue->outputTop = -1;
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    while (obj->outputTop != -1) {
        obj->inputStack[++obj->inputTop] = obj->outputStack[obj->outputTop--];
    }
    obj->inputStack[++obj->inputTop] = x;
    while (obj->inputTop != -1) {
        obj->outputStack[++obj->outputTop] = obj->inputStack[obj->inputTop--];
    }
}

int myQueuePop(MyQueue* obj) {
    return obj->outputStack[obj->outputTop--];
}

int myQueuePeek(MyQueue* obj) {
    return obj->outputStack[obj->outputTop];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->outputTop == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}
