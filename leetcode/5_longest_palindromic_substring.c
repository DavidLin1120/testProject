
bool isPalindrome(char *s, int len){
    int i = 0;
    if (len == 1)
        return s;
    // if (!len%2)
    //     return false;
    // printf("c:%c  len:%d\n",*s,len);
    for ( i = 0 ; i < (len+1)/2 ; i++){
        if ( s[i] != s[len-1-i]){
            return false;
        }
    }
    
    return true;  
    
}


char * longestPalindrome(char * s){
    
    int i = 0 , j = 0, pal_len = 0 , temp_len = 0, s_len = 0;
    char *str_pal;
    char *str_temp;
    
    str_pal = malloc(1001*sizeof(char));
    *str_pal = '\0';
    str_temp = malloc(1001*sizeof(char));
    
    //get input s length
    while(s[s_len]){
        s_len++;
    }
    // if(s_len == 2){
    //     *str_pal = *s;
    //     *(str_pal+1) = '\0';
    // }
    
    temp_len = s_len;
    for (i = s_len ; i > 0 ; i--){
        for (j = 0 ; j + i < s_len +1  ; j++){
           if(isPalindrome(s+j, i)){
               memcpy(str_pal, s+j, i);
               *(str_pal+i) = '\0';
               // printf("match: %s,%d\n",str_pal, i );
               // return str_pal;
               break;
           } 
        }
        if (*str_pal)
            break;
        
    }
    return str_pal;
    
}