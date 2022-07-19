#include<stdio.h>


struct ListNode{
    int val;
    struct ListNode *next;
};

int leftIndex(int index){
    return 2 * index + 1;
}

int rightIndex(int index){
    return 2 * index + 2;
}

void heapify(struct ListNode **minHeap, int index, int length){
    while (index < length){
        int min = index;
        if (leftIndex(index) < length && minHeap[leftIndex(index)] -> val < minHeap[min] -> val){
            min = leftIndex(index);
        }
        if (rightIndex(index) < length && minHeap[rightIndex(index)] -> val < minHeap[min] -> val){
            min = rightIndex(index);
        }

        if (min == index){
            break;
        }
        else if (min == leftIndex(index)){
            struct ListNode *temp = minHeap[index];
            minHeap[index] = minHeap[leftIndex(index)];
            minHeap[leftIndex(index)] = temp;
            index = min;
        }
        else{  // min == rightIndex(index)
            struct ListNode *temp = minHeap[index];
            minHeap[index] = minHeap[rightIndex(index)];
            minHeap[rightIndex(index)] = temp;
            index = min;            
        }
    }
}


struct ListNode *mergeKLists(struct ListNode **lists, int listsSize){
    // build the heap
    struct ListNode **minHeap = (struct ListNode **)malloc(sizeof(struct ListNode*) * listsSize);
    int length = 0;
    for (int index = 0; index < listsSize; index++){
        if (lists[index]){
            minHeap[length] = lists[index];
            length++;
        }
    }
    for (int index = length / 2 - 1; index >= 0; index--){
        heapify(minHeap, index, length);
    }

    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy -> val = 0;
    dummy -> next = 0;
    struct ListNode *current = dummy;

    while (length){
        current -> next = (struct ListNode *)malloc(sizeof(struct ListNode));
        current = current -> next;
        current -> val = minHeap[0] -> val;
        current -> next = 0;

        minHeap[0] = minHeap[0] -> next;
        if (minHeap[0]){
            heapify(minHeap, 0, length);
        }
        else{
            if (length > 1){
                minHeap[0] = minHeap[length - 1];
                length--;
                heapify(minHeap, 0, length);
            }
            else{
                break;
            }
        }
    }

    struct ListNode *result = dummy -> next;
    free(dummy);
    return result;
}


void main(){
    mergeKLists(NULL, 0);
}