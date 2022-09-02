int *twoSum(int *numbers, int numbersSize, int target, int *returnSize){
    int left = 0;
    int right = numbersSize - 1;

    while (left < right){
        int sum = numbers[left] + numbers[right];
        if (sum == target) break;
        else if (sum > target) right--;
        else left++;
    }

    *returnSize = 2;
    int *result = (int*)malloc(sizeof(int) * 2);
    result[0] = left + 1;
    result[1] = right + 1;
    return result;
}