#include<stdio.h>
#include<stdbool.h>

typedef struct MyList{
    int value;
    struct MyList *next;
}
MyList;

typedef struct{
    MyList *head;
}
MyStack;

MyStack *myStackCreate(){
    MyStack *obj = (MyStack*)malloc(sizeof(MyStack));
    obj -> head = NULL;
    return obj;
}

void myStackPush(MyStack *obj, int x){
    MyList *new = (MyList*)malloc(sizeof(MyList));
    new -> value = x;
    new -> next = obj -> head;
    obj -> head = new;
}

int myStackPop(MyStack *obj){
    int ans = obj -> head -> value;
    MyList *old = obj -> head;
    obj -> head = obj -> head -> next;
    free(old);
    return ans;
}

int myStackTop(MyStack *obj){
    return obj -> head -> value;
}

bool myStackEmpty(MyStack *obj){
    return obj -> head == NULL;
}

void myStackFree(MyStack *obj){
    while (!myStackEmpty(obj)){
        myStackPop(obj);
    }
    free(obj);
}

typedef struct{
    MyStack *body;
    MyStack *assistant;
}
MyQueue;


MyQueue *myQueueCreate(){
    MyQueue *obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj -> body = myStackCreate();
    obj -> assistant = myStackCreate();
    return obj;
}

void myQueuePush(MyQueue *obj, int x){
    while (!myStackEmpty(obj -> body)){
        myStackPush(obj -> assistant, myStackPop(obj -> body));
    }
    myStackPush(obj -> body, x);
    while (!myStackEmpty(obj -> assistant)){
        myStackPush(obj -> body, myStackPop(obj -> assistant));
    }
}

int myQueuePop(MyQueue *obj){
    return myStackPop(obj -> body);
}

int myQueuePeek(MyQueue *obj){
    return myStackTop(obj -> body);
}

bool myQueueEmpty(MyQueue* obj){
    return myStackEmpty(obj -> body);
}

void myQueueFree(MyQueue* obj){
    myStackFree(obj -> body);
    myStackFree(obj -> assistant);
    free(obj);
}

/*
MyQueue* obj = myQueueCreate();
myQueuePush(obj, x);
int ans = myQueuePop(obj);
int ans = myQueuePeek(obj);
bool ans = myQueueEmpty(obj);
myQueueFree(obj);
*/