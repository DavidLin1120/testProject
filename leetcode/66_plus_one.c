/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    
    int i;
    int add_one = 1;
    int *ret_digits;
    for(i = digitsSize-1 ; i > -1 ; i--){
        digits[i] = (digits[i] + add_one);
        add_one = digits[i]/10;
        digits[i] %=10;
    }
    
    
    *returnSize = digitsSize + add_one;
    
    
    ret_digits = malloc(sizeof(int) * (*returnSize));
    ret_digits[0] = 1;
    for( i = 0+add_one ; i < *returnSize ; i++){
        ret_digits[i] = digits[i-add_one];
    }
    // printf("%d", *returnSize);
    return ret_digits;
    
}