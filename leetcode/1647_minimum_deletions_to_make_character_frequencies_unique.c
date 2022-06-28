// Runtime: 20 ms, faster than 93.33% of C online submissions for Minimum Deletions to Make Character Frequencies Unique.
// Memory Usage: 11.8 MB, less than 6.67% of C online submissions for Minimum Deletions to Make Character Frequencies Unique.

int find_rm_cnt(int **frqUsed, int idx){
    int i;
    int rmCnt = 1;
    for(i = idx-1; i > -1; i--){
        
        if((*frqUsed)[i] == 0){
            (*frqUsed)[i] = 1;
            break;
        }
        rmCnt++;
    }
    return rmCnt;
    
}

int minDeletions(char * s){

    int *tbl, *frqUsed;
    int i,len, rmCnt;
    rmCnt = 0;
    len = strlen(s);
    tbl = (int *)malloc(sizeof(int)*26);

    memset(tbl, 0, 26*sizeof(int));
   
    frqUsed = (int *)malloc(sizeof(int)*len);
    memset(frqUsed, 0 , len*sizeof(int));
    
    while(*s){
        tbl[(*s)-'a'] +=1;
        s++;
    }
    
    for(i = 0; i<26; i++){
        if(tbl[i]){
            //printf("%c:%d\n",i+'a',tbl[i]);
            if (frqUsed[tbl[i]-1] == 0){
                frqUsed[tbl[i]-1] = 1;
            }else{
                //find next empty element
                rmCnt = rmCnt + find_rm_cnt(&frqUsed, tbl[i]-1);
                //printf("rmCnt:%d\n",rmCnt);
            }
        }
            
    }
    // for(i = 0 ; i< len; i++){
    //     printf("frq:%d:%d\n", i, frqUsed[i]);
    // }
    //printf("%d\n",rmCnt);
    
    
    return rmCnt;
}