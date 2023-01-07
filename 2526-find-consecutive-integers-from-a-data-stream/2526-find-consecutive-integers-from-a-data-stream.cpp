class DataStream {
    int val, size, l = 0, check;
public:
    DataStream(int value, int k) {
        val = value, size = check = k;
    }
    
    bool consec(int num) {
        if(num == val)      check--;          // if same value occurs     
        else                check = size;     // if stream breaks intialize it back to original Value
        
        // If there are less than k integers, the condition does not hold true 
        // For the 1st K calls return False (as specified in the Question)
        if(++l < size)      return 0;         
        return check<=0;               // if same value occurs k time then check==0 and if it occurs more then k then check<0
    }
};