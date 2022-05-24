

bool canJump(int* nums, int numsSize){

    
    int i,max;
    max = 0;
    
    // printf("%d",numsSize);
    for(i = 0 ; i < numsSize-1 ; i++){
        if(i > max){
            return false;
        }
        max = (i + nums[i]) > max ? (i+nums[i]) : max;
        
        
        
        if(max > numsSize-1){
            return true;
        }
    }
    return max >= (numsSize-1);
}