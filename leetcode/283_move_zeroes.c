void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void moveZeroes(int* nums, int numsSize){
    
    int i = 0, j = 0;
    int new_idx=0;
    int cnt = 0;
    for(i = 0 ; i < numsSize ;i++){
        if(nums[i] != 0){
            nums[new_idx++] = nums[i];
            cnt++;
        }
    }
    
    for(i = numsSize -1  ; i >= cnt ; i--){
        nums[i] = 0;
    }
    
}