void shiftArr(int *arr, int start, int cnt){
    int i;
    for(i = start+cnt; cnt > 0 ; cnt--,i--){
        arr[i] = arr[i-1];
        
    }
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    
    int i,j;
    int cur_idx = 0;
    for( i = 0 , j = 0; i < m && j<n ;){
        if(nums1[cur_idx] < nums2[j]){
            i++;
        }else{
            shiftArr(nums1, cur_idx, m-i);
            nums1[cur_idx] = nums2[j];
            j++;
        }
        cur_idx++;
        
    }
    for(; j<n ;j++, cur_idx++){
        nums1[cur_idx] = nums2[j];
    }
    
}