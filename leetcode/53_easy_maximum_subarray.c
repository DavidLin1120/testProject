

int maxSubArray(int* nums, int numsSize){

    int max = 0x80000000, tmp_sum;
    int i = 0 , j = 0;
    
    if(numsSize == 0)
        return 0;
    
    if(numsSize ==1)
        return nums[0];
    
//     for(i = 0 ; i < numsSize; i++){
        
        
//         tmp_sum = nums[i];
//         max = tmp_sum > max ? tmp_sum : max;
//         for(j = i + 1 ; j<numsSize; j++){
//             tmp_sum += nums[j];
//             max = tmp_sum > max ? tmp_sum : max;
//         }
        
//     }
    max = nums[0];
    tmp_sum = nums[0];
    for (i = 1 ; i < numsSize ; i++){
        if (tmp_sum > 0){
            tmp_sum += nums[i];
        }else{
            tmp_sum = nums[i];
        }
        
        max = tmp_sum > max ? tmp_sum : max;
        
    }
    return max;
}