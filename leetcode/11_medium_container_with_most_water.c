

int maxArea(int* height, int heightSize){
    int i = 0 , left = 0 , right=0;;
    int max = 0;
    int len = 0;
    int found_len=-1;
    if(heightSize <2)
        return 0;
    
    for ( i = 0 ; i < heightSize ; i ++){
        found_len=-1;
        for (left = 0 ; left < i ; left++){
            if(!(height[left] < height[i])){
                if(max < height[i] * (i-left)){
                    max = height[i]*(i-left);
                }
                found_len = (i-left);
                break;
            }
        }
        if (found_len > -1){
            if (heightSize -1 - i < found_len)
                continue;
        }
        for (right = heightSize-1 ; right> i ; right--){
             if(!(height[right] < height[i])){
                if(max < height[i] * (right-i)){
                    max = height[i]*(right-i);
                }
                 break;
            }
            
        }

    }
    return max;
}