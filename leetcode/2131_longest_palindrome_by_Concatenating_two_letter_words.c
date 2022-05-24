int longestPalindrome(char ** words, int wordsSize){
    int **table;
    int i,cnt = 0;
    
    table = malloc(26*sizeof(int*));
    for(i = 0 ; i <26 ; i++){
        table[i] = calloc(26,sizeof(int*));
    }
    
    for(i = 0; i < wordsSize; i++){
        const int a = words[i][0]-'a';
        const int b = words[i][1]-'a';
        
        if(table[b][a]){
            table[b][a]--;
            cnt+=4;
        }else{
            table[a][b] ++;
        }
    }
    for(i = 0 ; i <26; i++){
        if(table[i][i]){
            cnt+=2;
            break;
        }
    }
    

    return cnt;
}

// int longestPalindrome(char ** words, int wordsSize){

//     int *table;
//     int i,j,cnt = 0;
//     int isDup=0;
    
//     table = calloc(wordsSize, sizeof(int));
    
//     for(i = 0 ; i < wordsSize ;i++){
//         if(table[i])
//             continue;
//         for(j = i+1 ; j < wordsSize; j++){
//             if(table[j])
//                 continue;
            
//             if(words[i][0] == words[j][1] && words[i][1] == words[j][0]){
//                 cnt+=4;
//                 table[j]=1;
//                 table[i]=1;
//                 break;
//             }
//         }
//         if(!isDup && !table[i] && words[i][0] == words[i][1]){
//             table[i]=1;
//             isDup=2;
//         }
//     }
    
//     return cnt+isDup;
    
//     // return cnt;
// }