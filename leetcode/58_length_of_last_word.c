

int lengthOfLastWord(char * s){
    
    // int word_nums = 0, last_word_nums= 0;
    if (!*s)
        return 0;
  
//     while(*s){
//         if(*s != ' '){
//             word_nums++;
//         }else{
//             if(word_nums)
//                 last_word_nums = word_nums;
//             word_nums = 0;
//         }
            
//         s++;
//     }
//    if(word_nums)
//        last_word_nums = word_nums;
    
//     return last_word_nums;
    int slen = strlen(s);
    int i,j;
    
    for(i = slen-1; s[i] == ' ' && i > -1 ; i--);
    for(j = i-1 ; j > -1 && s[j] != ' ' ; j--);
    
    return i-j;
    return 0;
    
}