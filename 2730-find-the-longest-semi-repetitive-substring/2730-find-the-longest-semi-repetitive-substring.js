var longestSemiRepetitiveSubstring = function(s) {
  let length = 0;
  let repeatedDigits;

  for(let i = 0;i<s.length;i++){
    repeatedDigits = false;
      for(let j=i;j<s.length;j++){
        if(j>i && s[j]===s[j-1]){
          if(repeatedDigits){
            break;
          }
          repeatedDigits = true;
        }
        length = Math.max(length,j-i+1)
      }
  }

    return length
};