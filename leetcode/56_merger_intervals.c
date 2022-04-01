int compare(const int *a, const int *b){
    
    int *n1 = *(int**)a;
    int *n2 = *(int**)b;
    
    return n1[0] > n2[0];
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    
    if(intervalsSize == 0)
        return NULL;
    
    int* tmpEnt = malloc(sizeof(int)*2);
    int i;
    int **retIntervals = (int**)malloc(sizeof(int*)*intervalsSize);
    int entCnt = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int)*intervalsSize);
    
    qsort(intervals, intervalsSize, sizeof(int *), compare);
    
    tmpEnt[0] = intervals[0][0];
    tmpEnt[1] = intervals[0][1];
    
    for(i = 1 ; i < intervalsSize; i++)
    {
        if(intervals[i][0] <= tmpEnt[1]){
            if(tmpEnt[1] <= intervals[i][1]){
                tmpEnt[1] = intervals[i][1];
                
            }
        }else{
            //append entry;
            retIntervals[entCnt] = tmpEnt;
            (*returnColumnSizes)[entCnt] = 2;
            entCnt++;
            tmpEnt = (int*) malloc(sizeof(int)*2);
            tmpEnt[0] = intervals[i][0];
            tmpEnt[1] = intervals[i][1];
            
        }
    }
    //append the last;
    retIntervals[entCnt] = tmpEnt;
    (*returnColumnSizes)[entCnt] = 2;
    entCnt++;
    *returnSize = entCnt;
    return retIntervals;
}