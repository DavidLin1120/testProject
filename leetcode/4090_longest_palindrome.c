#define range 'z'-'A'+1
int longestPalindrome(char * s){
    
    // const int ragne = 'z'-'A' +1;
    int table[range]={0};
    int i, len, cnt, pair, hasSingle;
    
    hasSingle=0;
    cnt = 0;
    len = strlen(s);
    
    // printf("%d,%d",'A','a');
    for(i = 0 ; i < len ; i++){
        // printf(" %c.%d",s[i],s[i]);
        table[s[i]-'A'] ++;
        
    }
    
    for(i = 0 ; i < range ; i++){
        if(!table[i]){
            continue;
        }
        
        if(!hasSingle && table[i]%2){
            // printf("i=%d, table[i]=%d",i,table[i]);
            hasSingle = 1;
        }
        
        pair = table[i]/2;
        cnt = cnt + pair*2;
    }
    
    cnt+=hasSingle;
    return cnt;
    
}