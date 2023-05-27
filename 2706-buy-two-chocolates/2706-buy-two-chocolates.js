var buyChoco = function(prices, money) {
    let mini = 101;
    let mini2 = Infinity;
    let index = 0;

    for (let i = 0; i < prices.length; i++) {
        if (mini > prices[i]) {
            index = i;
            mini = prices[i];
        }
    }
    
    for (let i = 0; i < prices.length; i++) {
        if (i !== index) {
            mini2 = Math.min(mini2, mini + prices[i]);
        }
    }
    
    return (mini2 <= money ? money - mini2 : money);
};
