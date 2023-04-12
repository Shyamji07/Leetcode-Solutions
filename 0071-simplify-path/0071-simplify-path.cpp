class Solution {
public:
   string simplifyPath(string path) {
int index = path.size()-1; 
       string ans;
       int back=0;
   	while(index>=0){
           string temp="";
           while(index>=0 && path[index]!='/'){
               temp+=path[index];
               index--;
           }
           index--;
           if(temp =="" || temp==".")
               continue;
           if(temp=="..")
               back++;
          else if(back>0)
              back--;
           else{
               ans+=temp;
               ans+="/";
           }
       }
       reverse(ans.begin(),ans.end());
       if(ans=="")
           return "/";
       return ans;
       
   }
   };