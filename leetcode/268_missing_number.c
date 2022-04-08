int compare(const int *a, const int *b){
    int n1 = *a;
    int n2 = *b;
    return n1-n2;
}

int missingNumber(int* nums, int numsSize){
    int i;
    
    qsort(nums, numsSize, sizeof(int), compare);
    
    for(i = 0; i < numsSize; i++){
        if(nums[i] != i )
            break;
    }
    
    return i;
    
}