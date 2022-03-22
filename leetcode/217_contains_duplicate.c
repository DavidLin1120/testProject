void SWAP(int *a, int *b){
    int tmp;
    
    tmp = *a;
    *a = *b;
    *b = tmp;
    
}

void quickSort(int* number, int left, int right) { 
    if(left < right) { 
        int s = number[(left+right)/2]; 
        int i = left - 1; 
        int j = right + 1; 

        while(1) { 
            while(number[++i] < s) ;  // 向右找 
            while(number[--j] > s) ;  // 向左找 
            if(i >= j) 
                break; 
            SWAP(&number[i], &number[j]); 
        } 
        printf("i:%d j:%d\n", i, j);
        quickSort(number, left, i-1);   // 對左邊進行遞迴 
        quickSort(number, j+1, right);  // 對右邊進行遞迴 
    } 
} 

bool containsDuplicate(int* nums, int numsSize){
    int tmp;
    int i ;
    quickSort(nums, 0, numsSize-1);
    tmp = nums[0];
    for(i = 1 ; i < numsSize; i++){
        printf("%d %d\n",tmp, nums[i]);
        if(tmp == nums[i])
            return true;
        tmp = nums[i];
    }
    return false;
}
