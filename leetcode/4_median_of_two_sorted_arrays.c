#include <stdio.h>
#include <stdlib.h>

void chk_set_val(int cur, int val , int idx1, int idx2, double* val1, double* val2){
    if(cur == idx1)
        *val1 = val;
    if(cur == idx2)
        *val2 = val;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int cur_idx = 0;
    int m1_idx = 0, m2_idx = 0;
    double m1_val =0.0, m2_val = 0.0;
    
    if (nums1Size == 0 && nums2Size == 0)
        return 0;

    if((nums1Size+nums2Size)%2){
        //mid 1
        m1_idx = m2_idx = (nums1Size + nums2Size) / 2;
    }else{
        //numes is odd :get mid 2
        m2_idx = (nums1Size + nums2Size) / 2;
        m1_idx = m2_idx - 1;
    }

    for (; nums1Size > 0 || nums2Size > 0 ; cur_idx++){
        if (nums1Size < 1){
            // get nums2
            chk_set_val(cur_idx,*nums2 , m1_idx, m2_idx, &m1_val, &m2_val);
            //TO avoid ERROR: AddressSanitizer: heap-buffer-overflow on address
            if (nums2Size>1)
                nums2++;
            nums2Size--;
            continue;
        }

        if (nums2Size < 1){
            // get nums1
            chk_set_val(cur_idx,*nums1 , m1_idx, m2_idx, &m1_val, &m2_val);
            if (nums1Size >1)
                nums1++;
            nums1Size--;
            continue;
        }

        if (*nums1 < *nums2){
             chk_set_val(cur_idx,*nums1 , m1_idx, m2_idx, &m1_val, &m2_val);
             if (nums1Size>1)
                nums1++;
             nums1Size--;
        }else{
             chk_set_val(cur_idx,*nums2 , m1_idx, m2_idx, &m1_val, &m2_val);
             if (nums2Size>  1)
                nums2++;
             nums2Size--;
        }
        
        
    }
    
    return (m1_val+m2_val)/2;
}

int main(){
    int nums1[4] = {1,3};
    int nums2[2] = {2};
    int num_size1 = 2;
    int num_size2 = 1;
    printf("\n%f",findMedianSortedArrays(nums1, num_size1, nums2, num_size2));
    return 0;

}