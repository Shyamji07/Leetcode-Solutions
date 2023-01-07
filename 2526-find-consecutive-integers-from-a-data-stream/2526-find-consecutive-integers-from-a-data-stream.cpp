class DataStream {
    int cnt = 0; // numbers stream = ( _ _ _ _ x x x x),  cnt = (count of x where x = val)
    int val, K;
public:
    DataStream(int value, int k) {
        val = value;
        K = k;
    }

    bool consec(int num) {
        if (num == val) cnt++;
        else cnt = 0;
        return cnt >= K;
    }
};