

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    
    int i;
    int j ;
    int **ret = malloc(sizeof(int *) * numRows);
    *returnSize = numRows;
    *returnColumnSizes = malloc(sizeof(int) * numRows);
    
    for(i = 0 ; i < numRows ; i ++){
        ret[i] = malloc(sizeof(int)*(i+1));
        (*returnColumnSizes)[i] = i+1;
        ret[i][0] = 1;
        ret[i][i] = 1;
        for(j = 1 ; j<i ; j++){
            ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
        }
    }
    return ret;
}