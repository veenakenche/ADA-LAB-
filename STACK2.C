typedef struct {
    int top;
    int size;
    int* stack;

} CustomStack;

CustomStack* customStackCreate(int maxSize) {
    CustomStack* stk = (CustomStack*)malloc(sizeof(CustomStack));
    stk->top = -1;
    stk->size = maxSize;
    stk->stack = (int*)calloc(sizeof(int), maxSize);
    return stk;
}

void customStackPush(CustomStack* obj, int x) {
    if (obj->top == obj->size - 1)
        return;
    obj->stack[++(obj->top)] = x;
}

int customStackPop(CustomStack* obj) {
    if (obj->top == -1)
        return -1;
    return obj->stack[obj->top--];
}

void customStackIncrement(CustomStack* obj, int k, int val) {
    if ((k - 1) > obj->top)
        k = (obj->top + 1);

    for (int i = 0; i < k; ++i)
        obj->stack[i] += val;
}

void customStackFree(CustomStack* obj) {
    free(obj->stack);
    free(obj);
}

/**
 * Your CustomStack struct will be instantiated and called as such:
 * CustomStack* obj = customStackCreate(maxSize);
 * customStackPush(obj, x);

 * int param_2 = customStackPop(obj);

 * customStackIncrement(obj, k, val);

 * customStackFree(obj);
*/
