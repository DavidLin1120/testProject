

int reverse(int x){
    //out off range
    if (x == 0x80000000 || x == 0)
        return 0;
    
    int tmp_num = x;
    int rev_num = 0;
    
    bool is_neg = tmp_num < 0 ;
    
    if(is_neg)
        tmp_num*=-1;
    
    while(!(tmp_num % 10)){
        tmp_num /= 10;
    }
    
    while(tmp_num > 0){
        if (rev_num > (0x7fffffff/10))
            return 0;
        rev_num = (rev_num * 10) + (tmp_num % 10);
        
        tmp_num /= 10;
    }
    
    if (is_neg)
        rev_num*=-1;
    
    return rev_num;
    
    
    
}