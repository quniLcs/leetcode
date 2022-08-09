void sortColors(int *nums, int numsSize){
    int colors[3] = {0, 0, 0};
    
    for (int i = 0; i < numsSize; i++){
        colors[nums[i]]++;
    }

    colors[1] += colors[0];
    colors[2] += colors[1];

    for (int j = 0; j < 3; j++){
        int start = j == 0 ? 0 : colors[j - 1];
        int end = colors[j];
        for (int i = start; i < end; i++){
            nums[i] = j;
        }
    }
}