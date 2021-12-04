void FillChar(int tmp, char *roma, int *roma_idx, char* roma_char){
    int i = 0;
    switch(tmp){
        case 1:
        case 2:
        case 3:
            for (i = 0 ; i < tmp ; i++){
                
                roma[(*roma_idx)++] = roma_char[0];
                // printf(" %d\n",*roma_idx);
            }
            break;
        case 4:
            roma[(*roma_idx)++] = roma_char[0];
            roma[(*roma_idx)++] = roma_char[1];
            break;
        case 5:
        case 6:
        case 7:
        case 8:
            roma[(*roma_idx)++] = roma_char[1];
            for (i = 0 ; i < tmp%5 ; i++){
                roma[(*roma_idx)++] = roma_char[0];
            }
            break;
        case 9:
            roma[(*roma_idx)++] = roma_char[0];
            roma[(*roma_idx)++] = roma_char[2];
            break;
        case 10:
            roma[(*roma_idx)++] = roma_char[1];
            
            break;
        deafult:
            break;
            
    }
}

//I II III IV V VI VII VIII IX X    =>IVX 1->10
//X XX XXX XL L LX LXX LXXX LC C    =>  XLC 10->100
//C CC CCC CD D DC DCC DCCC DM M    =>    CDM 100->1000
//M MM MMM


char * intToRoman(int num){

    int M_num=0, tmp = 0;
    int i = 0 , roma_idx = 0;
    char *roma_char = malloc(3*sizeof(char));
    char *roma = malloc(20 * sizeof(char));
    M_num = num/1000;
    
    //1000->3000
    num %= 1000;
    for (i = 0 ; i < M_num ; i++){
        roma[roma_idx++] = 'M';
    }
    
    //100->900
    tmp = num/100;
    roma_char[0] = 'C';
    roma_char[1] = 'D';
    roma_char[2] = 'M';
    FillChar(tmp, roma, &roma_idx, roma_char);
    
    num%=100;
    //100->900
    tmp = num/10;
    roma_char[0] = 'X';
    roma_char[1] = 'L';
    roma_char[2] = 'C';
    FillChar(tmp, roma, &roma_idx, roma_char);
    
    printf("num:%d",num);
    num%=10;
    tmp = num;
    roma_char[0] = 'I';
    roma_char[1] = 'V';
    roma_char[2] = 'X';
    FillChar(tmp, roma, &roma_idx, roma_char);
    roma[roma_idx] = '\0';
    
    return roma;
    
}