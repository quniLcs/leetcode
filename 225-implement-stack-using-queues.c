#include<stdio.h>
#include<stdbool.h>

typedef struct MyList{
    int value;
    struct MyList *next;
}
MyList;


typedef struct{
    MyList *head;
    MyList *tail;
    int size;
}
MyQueue;

MyQueue *myQueueCreate(){
    MyQueue *obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj -> head = (MyList*)malloc(sizeof(MyList));
    obj -> head -> value = 0;
    obj -> head -> next = NULL;
    obj -> tail = obj -> head;
    obj -> size = 0;
    return obj;
}

void myQueuePush(MyQueue *obj, int x){
    obj -> tail = obj -> tail -> next = (MyList*)malloc(sizeof(MyList));
    obj -> tail -> value = x;
    obj -> tail -> next = NULL;
    obj -> size += 1;
}

int myQueuePop(MyQueue *obj){
    int ans = obj -> head -> next -> value;
    MyList *old = obj -> head;
    obj -> head = obj -> head -> next;
    free(old);
    obj -> size -= 1;
    return ans;
}

int myQueueTop(MyQueue *obj){
    return obj -> head -> next -> value;
}

bool myQueueEmpty(MyQueue *obj){
    return obj -> size == 0;
}

void myQueueFree(MyQueue *obj){
    while (!myQueueEmpty(obj)){
        myQueuePop(obj);
    }
    free(obj -> head);
    free(obj);
}


typedef struct{
    MyQueue *body;
    MyQueue *assistant;
}
MyStack;

MyStack *myStackCreate(){
    MyStack *obj = (MyStack*)malloc(sizeof(MyStack));
    obj -> body = myQueueCreate();
    obj -> assistant = myQueueCreate();
    return obj;
}

void myStackPush(MyStack *obj, int x){
    myQueuePush(obj -> assistant, x);
    while (!myQueueEmpty(obj -> body)){
        myQueuePush(obj -> assistant, myQueuePop(obj -> body));
    }
    while (!myQueueEmpty(obj -> assistant)){
        myQueuePush(obj -> body, myQueuePop(obj -> assistant));
    }
}

int myStackPop(MyStack *obj){
    return myQueuePop(obj -> body);
}

int myStackTop(MyStack *obj){
    return myQueueTop(obj -> body);
}

bool myStackEmpty(MyStack *obj){
    return myQueueEmpty(obj -> body);
}

void myStackFree(MyStack *obj){
    myQueueFree(obj -> body);
    myQueueFree(obj -> assistant);
    free(obj);
}

void main(){
    MyStack *obj = myStackCreate();
    myStackPush(obj, 1);
    myStackPush(obj, 2);
    printf("%d\n", myStackTop(obj));
    printf("%d\n", myStackPop(obj));
    printf("%d\n", myStackEmpty(obj));
    myStackFree(obj);
}