// 1 2   7 4 3 1 
// 1 [2] 7 4 3 1
// 1 [2] 7 4 [3] 1  =>3 greater than 2
// 1 3 7 4 2 1 
// 1 3 1 2 4 7
void swap(int *a, int *b){
    int tmp;
    
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverse(int *nums, int start, int end){
    int mid = (start+end)/2;
    int i,tmp;
    
    for(i = start; i <= mid ; i++){
        tmp = nums[i];
        nums[i] = nums[end+start-i];
        nums[end+start-i] = tmp;
    }
    
    
}

void nextPermutation(int* nums, int numsSize){
    int numIdx_1, numIdx_2,i;
    
    numIdx_1=numsSize;
    for(i = numsSize-2 ; i >= 0 ; i--){
        if(nums[i] < nums[i+1]){
            numIdx_1 = i;
            break;
        }
    }
    
    //if the last
    //reverse all
    if(numIdx_1 == numsSize){
        reverse(nums, 0, numsSize-1);
        return;
    }
    
    for(i = numsSize-1 ; i >= 0 ; i--){
        if(nums[i] > nums[numIdx_1]){
            numIdx_2 = i;
            break;        
        }
    }
    swap((nums+numIdx_1), (nums+numIdx_2));
    reverse(nums, numIdx_1+1, numsSize-1);
    
}



