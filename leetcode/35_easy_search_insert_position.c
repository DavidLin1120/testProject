

int searchInsert(int* nums, int numsSize, int target){
    int ret_val = 0;
    int i = 0;
    if(numsSize==0)
        return ret_val;
    
    
    for (i = 0 ; i < numsSize; i++){
        if(nums[i] >= target)
            break;
        
        if(nums[i] < target){
            ret_val++;
        }
    }
    return ret_val;
}