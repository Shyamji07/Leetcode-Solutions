/**
 * @param {string} s
 * @return {boolean}
 */
var halvesAreAlike = function(s) {
      let l = 0;
        let r = s.length-1;
        let cnt_A = 0;
        let cnt_B = 0;
        
        while(l<r){
            if(s[l]=='a' || s[l]=='e' || s[l]=='i' || s[l]=='o' || s[l]=='u' || s[l]=='A' || s[l]=='E' || s[l]=='I' || s[l]=='O' || s[l]=='U'){
                cnt_A++;
            }
            
            if(s[r]=='a' || s[r]=='e' || s[r]=='i' || s[r]=='o' || s[r]=='u' || s[r]=='A' || s[r]=='E' || s[r]=='I' || s[r]=='O' || s[r]=='U'){
                cnt_B++;
            }
            
            l++;
            r--;
        }
        
        return cnt_A == cnt_B;
};