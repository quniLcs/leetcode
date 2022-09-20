#include<stdbool.h>

int currentParent(int heapIndex){
    return (heapIndex - 1) / 2;
}

int leftChild(int heapIndex){
    return 2 * heapIndex + 1;
}

int rightChild(int heapIndex){
    return 2 * heapIndex + 2;
}

void heapifyFromTop(int *heap, int heapSize, int heapIndex, int *nums){
    while (true){
        int maxIndex = heapIndex;
        if (leftChild(heapIndex) < heapSize && nums[heap[leftChild(heapIndex)]] > nums[heap[maxIndex]]){
            maxIndex = leftChild(heapIndex);
        }
        if (rightChild(heapIndex) < heapSize && nums[heap[rightChild(heapIndex)]] > nums[heap[maxIndex]]){
            maxIndex = rightChild(heapIndex);
        }

        if (maxIndex == heapIndex){
            break;
        }
        else{
            int temp = heap[heapIndex];
            heap[heapIndex] = heap[maxIndex];
            heap[maxIndex] = temp;
            heapIndex = maxIndex;
        }
    }
}

void heapifyFromBottom(int *heap, int heapIndex, int *nums){
    while (heapIndex){
        int minIndex = heapIndex;
        if (nums[heap[currentParent(heapIndex)]] < nums[heap[minIndex]]){
            minIndex = currentParent(heapIndex);
        }

        if (minIndex == heapIndex){
            break;
        }
        else{
            int temp = heap[heapIndex];
            heap[heapIndex] = heap[minIndex];
            heap[minIndex] = temp;
            heapIndex = minIndex;            
        }
    }
}

int *maxSlidingWindow(int *nums, int numsSize, int k, int *returnSize){
    int *heap = (int*)malloc(sizeof(int) * numsSize);
    int heapSize = 0;

    for (int numIndex = 0; numIndex <= k - 2; numIndex += 1){
        heap[heapSize] = numIndex;
        heapSize += 1;
    }
    for (int heapIndex = heapSize / 2 - 1; heapIndex >= 0; heapIndex -= 1){
        heapifyFromTop(heap, heapSize, heapIndex, nums);
    }

    *returnSize = numsSize - k + 1;
    int *result = (int*)malloc(sizeof(int) * (*returnSize));

    for (int numIndex = k - 1; numIndex < numsSize; numIndex += 1){
        heap[heapSize] = numIndex;
        heapifyFromBottom(heap, heapSize, nums);
        heapSize += 1;

        while (heap[0] <= numIndex - k){
            heapSize -= 1;
            heap[0] = heap[heapSize];
            heapifyFromTop(heap, heapSize, 0, nums);
        }

        result[numIndex - k + 1] = nums[heap[0]];
    }

    return result;
}