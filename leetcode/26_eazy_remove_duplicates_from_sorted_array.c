

int removeDuplicates(int* nums, int numsSize){
    int 
        
        = 0, search_idx = 1;
    
    if(numsSize < 2)
        return numsSize;
    
    
    for (search_idx = 1 ; search_idx < numsSize ; search_idx++){
        
        if (nums[search_idx] != nums[result_idx]){
            nums[++result_idx] = nums[search_idx]; 
        }
        
    }
    return result_idx+1;
    
}