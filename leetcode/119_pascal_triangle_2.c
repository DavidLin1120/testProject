
int* getRow(int rowIndex, int* returnSize){
    
    int *tmp = malloc(sizeof(int) * (rowIndex+1));
    int *ret = malloc(sizeof(int) * (rowIndex+1));
    int i,j;
    
    *returnSize = rowIndex+1;
    for(i = 0; i < rowIndex+1 ; i++){
        ret[0] = 1;
        ret[i] = 1;
        for(j = 1 ; j<= i/2 ;j++){
            ret[j] = ret[i-j]= tmp[j-1] +tmp[j];
        }
        memcpy(tmp, ret ,sizeof(int) * (i+1));
    }
    return ret;
}