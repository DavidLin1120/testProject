

char * addBinary(char * a, char * b){
    
    
    int lenA, lenB, lenRet, idxA, idxB , idxRet;
    int carry=0;
    int last_carry=0;
    char *ret;
    
    
    lenA = strlen(a);
    lenB = strlen(b);
    lenRet = lenA > lenB ? lenA+1 : lenB+1;
    
    idxA = lenA-1;
    idxB = lenB-1;
    idxRet = lenRet-1;
    
    ret = malloc(sizeof(char) * (lenRet+1));
    ret[lenRet] = '\0';
    int cnt;
    while(idxA>-1 || idxB>-1 || carry){
        cnt = 0;
         // printf("%s,%s,%d,%d\n",a,b,idxA,idxB);
        if(idxA > -1){
            if(a[idxA--] == '1'){
                cnt++;
            }
        }
        
        if(idxB > -1){
            if(b[idxB--] == '1'){
                cnt++;
                
            }
        }
        if(carry == 1){
            
            cnt++;
        }
        if(idxA<0 && idxB<0 && carry){
            last_carry=1;
        }
        carry = cnt > 1 ? 1 : 0;
        
        if(cnt == 0 || cnt ==2){
            ret[idxRet--] = '0';
        }else{
            ret[idxRet--] = '1';
        }
        // printf("%c [%d] carry:%d, cnt:%d\n",ret[idxRet+1],idxRet+1,carry,cnt);
    }
    if(last_carry == 0)
        ret++;
    return ret;
}