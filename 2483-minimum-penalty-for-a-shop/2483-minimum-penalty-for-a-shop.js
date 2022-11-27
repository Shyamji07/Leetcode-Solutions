var bestClosingTime = function(customers) {
    let maxi = 0;
    let balance = 0;
    let answer = 0
    for(var i = 0;i < customers.length;i++){
        if(customers[i] === "Y"){
            balance++
        }
        else balance--
        if(balance > maxi){
            maxi = balance;
            answer = i + 1
        }
    }
    return answer;
};