int base;
char **retList;
int strListIdx;

void appendStr(char *tmpStr, int index, int leftCnt, int rightCnt, int n){
      // printf("%d ",index);
    if(index == (n*2)){
        if(strListIdx == base){
            base = base*2;
            retList = realloc(retList, sizeof(char*)*base);
        }
        tmpStr[index] = '\0';
        retList[strListIdx] = (char*)malloc(sizeof(char*)*n*2+1);
        strcpy(retList[strListIdx],tmpStr);
        printf("%s\n",tmpStr);
        strListIdx++;
        return;
        
    }
    
    //append Left
    if(leftCnt<n){
        printf("a");
        tmpStr[index] = '(';
        appendStr(tmpStr, index+1, leftCnt+1, rightCnt, n);
    }
    
    //append Right
    if(leftCnt>rightCnt){
        printf("b");
        tmpStr[index] = ')';
        appendStr(tmpStr, index+1, leftCnt, rightCnt+1, n);
    }
}

char ** generateParenthesis(int n, int* returnSize){
    strListIdx=0;
    
    char *tmpStr = (char*)malloc(sizeof(char*) * n*2+1);
    base = 8;
    
    retList = (char**)malloc(sizeof(char*)*base);
    appendStr(tmpStr, 0, 0, 0, n);
    *returnSize = strListIdx;
    
    return retList;
    
}
