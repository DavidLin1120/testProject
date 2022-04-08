int compare(char *a, char *b){
    
    return *a-*b;
}

bool isAnagram(char * s, char * t){

    int len_s,len_t;
    
    len_s = strlen(s);
    len_t = strlen(t);
    
    if(len_s!=len_t)
        return false;
    
    qsort(s, len_s, sizeof(char), compare);
    qsort(t, len_t, sizeof(char), compare);
    
    return !strcmp(s,t);
    
    
}