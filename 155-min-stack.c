#include<stdio.h>

struct item{
    int value;
    struct item *next;
    struct item *smaller;
    struct item *larger;
};

typedef struct{
    struct item *head;
    struct item *smallest;
}
MinStack;


MinStack* minStackCreate(){
    MinStack *obj = (MinStack*)malloc(sizeof(MinStack));
    obj -> head = (struct item*)malloc(sizeof(struct item));
    obj -> smallest = (struct item*)malloc(sizeof(struct item));

    obj -> head -> value = 0;
    obj -> head -> next = NULL;
    obj -> head -> smaller = NULL;
    obj -> head -> larger = NULL;

    obj -> smallest -> value = 0;
    obj -> smallest -> next = NULL;
    obj -> smallest -> smaller = NULL;
    obj -> smallest -> larger = NULL;

    return obj;
}

void minStackPush(MinStack *obj, int val){
    struct item *new = (struct item*)malloc(sizeof(struct item));
    new -> value = val;

    new -> next = obj -> head -> next;
    obj -> head -> next = new;

    struct item *current = obj -> smallest;
    while (current -> larger && current -> larger -> value < val){
        current = current -> larger;
    }
    new -> smaller = current;
    new -> larger = current -> larger;
    new -> smaller -> larger = new;
    if (new -> larger) new -> larger -> smaller = new;
}

void minStackPop(MinStack *obj){
    struct item *target = obj -> head -> next;
    obj -> head -> next = target -> next;
    if (target -> smaller) target -> smaller -> larger = target -> larger;
    if (target -> larger) target -> larger -> smaller = target -> smaller;
    free(target);    
}

int minStackTop(MinStack *obj){
    return obj -> head -> next -> value;
}

int minStackGetMin(MinStack *obj){
    return obj -> smallest -> larger -> value;
}

void minStackFree(MinStack *obj){
    struct item *current = obj -> head -> next;
    while (current){
        struct item *succeed = current -> next;
        free(current);
        current = succeed;
    }
    free(obj -> head);
    free(obj -> smallest);
    free(obj);
}


void main(){
    MinStack *obj = minStackCreate();
    minStackPush(obj, -2);
    minStackPush(obj, 0);
    minStackPush(obj, -3);
    printf("%d\n", minStackGetMin(obj));
    minStackPop(obj);
    printf("%d\n", minStackTop(obj));
    printf("%d\n", minStackGetMin(obj));
    minStackFree(obj);
}