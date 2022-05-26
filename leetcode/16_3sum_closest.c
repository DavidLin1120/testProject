#include <stdlib.h>
#include <stdio.h>
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int threeSumClosest(int* nums, int numsSize, int target){
    int i;
    int cnt=0,tmp=0;
    int left, right;
    int found=0;
    if(numsSize<3)
        return 0;
    if(numsSize ==3){
        return nums[0]+nums[1]+nums[2];
    }
    

    qsort(nums, numsSize, sizeof(int), cmpfunc);
    
    cnt = nums[0] + nums[1] + nums[2];
    for(i = 0 ; i < numsSize ; i++){
        left = i+1;
        right = numsSize-1;
        while(left<right){
            tmp = nums[i]+nums[left]+nums[right];
            // if(i == 1)
            //     printf("tmp:%d",tmp);
            if(target == tmp){
                cnt = tmp;
                found = 1;
                
                break;
            }
            
            if(abs(target-tmp) < abs(target-cnt)){
                cnt = tmp;
            }
            
            if(tmp < target){
                left++;
            }else{
                right--;
            }
        }
        
        if(found)
            break;
        
    }
    
    return cnt;
}

//[-4,-3,1,100] 50 => -6, 98

//[-4,-3,100,101] 50 => -6, 98

//[0,2,1,-3]
//[-3, 0 , 1,2 ] 1
