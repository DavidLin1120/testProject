

int majorityElement(int* nums, int numsSize){
    int cur;
    int count = 0;
    
    for(int i =  0 ; i < numsSize; i++){
        if(count == 0){
            cur = nums[i];
        }
        
        if(cur == nums[i]){
            count++;
        }else{
            count--;
        }
    }
    return cur;
}