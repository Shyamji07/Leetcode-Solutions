var makeKey = function(m, n){
    return String(m) + "," + String(n);
}

var uniquePaths = function(m, n) {
    
    // key: tuple of (matrix height, matrix width)
    // value: path count of matrix from start to destination
    pathCount = { };
    
    var dp = function(m, n){
        
        let matrixSize = makeKey(m, n);
        
        if( matrixSize in pathCount ){
            return pathCount[matrixSize];
        }
        
        if( m == 0 && n == 0 ){
            // base case
            pathCount[matrixSize] = 0;
            return 0;
        }
        else if( m == 1 || n == 1){
            // base case
            pathCount[matrixSize] = 1;
            return 1;
            
        }else{
            // general case
            pathCount[matrixSize] = dp(m-1, n) + dp(m, n-1);
            return pathCount[matrixSize];
        }
        
    }
    
    
    return dp(m, n);

};
