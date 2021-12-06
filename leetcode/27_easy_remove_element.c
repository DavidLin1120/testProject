

int removeElement(int* nums, int numsSize, int val){
    int result_idx= 0, i = 0;
    
    if(numsSize == 0)
        return 0;
    for(i = 0 ; i < numsSize ; i++){
        if(nums[i] != val){
            nums[result_idx++] = nums[i];
        }
    }
    
    return result_idx;
    
    
}