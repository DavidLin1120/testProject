void reverse(int *nums, int start, int end){
    
    int tmp,i;
    
    for(i = start; i <=((start+end)/2) ; i ++){
        tmp = nums[i];
        nums[i] = nums[end-i+start];
        nums[end-i+start] = tmp;
    }
    return ;
}

void rotate(int* nums, int numsSize, int k){
    int i, curIdx = 0;
    int offset = k%numsSize;
    int tmp, to_fill;
    if (offset == 0)
        return;
    reverse(nums, 0, numsSize-1-offset);
    reverse(nums, numsSize-offset, numsSize-1);
    reverse(nums, 0, numsSize-1);
    return;
}
// [1,2,3,4,5,6,7]
// [5,6,7,1,2,3,4]