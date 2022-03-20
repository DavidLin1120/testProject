

int maxProfit(int* prices, int pricesSize){
    int buy_price = prices[0];
    int total = 0;
    int cur = 0;
    int i;
    for(i = 1 ; i < pricesSize ; i++){
        if(prices[i-1] > prices[i]){
            total += cur;
            buy_price = prices[i];
            cur = 0;
            continue;
        }
        if(prices[i] < buy_price){
            buy_price = prices[i];
        }else{
            cur = prices[i] - buy_price;
        }
    }
    total += cur;
    return total;
}