bool isLeapYear(int year){
    
    return ((year%4) == 0 && year % 100) || year % 400 == 0;
    
}

int dayOfYear(char * date){
    int year;
    int month;
    int day;
    int tmp= 0;
    int day_cnt = 0;
    int i;
    int month_day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    year = 1000*(date[0] - '0') +
        100*(date[1] - '0') +
        10*(date[2] - '0') +
        date[3] - '0';
    
    tmp = date[5] - '0';
    
    month = date[6] - '0' + tmp *10;
    
    tmp = date[8] - '0';
    day = tmp*10 + date[9] - '0';
    
    
    
    for ( i = 0 ; i < month-1 ; i++){
        day_cnt += month_day[i];
    }
    day_cnt += day;
    if(month > 2 && isLeapYear(year)){
        day_cnt++;
    }
    
    // printf("month:%d, day:%d, day_cnt:%d", month, day, day_cnt);
    return day_cnt;
}