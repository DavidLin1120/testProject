/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,j = 0;
    int *ret_dice = malloc(sizeof(int)*2);
    *returnSize = 0;
    for (i=0; i < numsSize -1 ; i++){
        for (j=i+1 ;j < numsSize; j++){
            if (nums[i] + nums[j] == target){
                ret_dice[0] = i;
                ret_dice[1] = j;
                *returnSize = 2;
                return ret_dice;
            }
        }
    }
    return ret_dice;
}