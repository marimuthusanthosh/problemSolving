class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int result = 0;
        long long divisor = 1;
    
        while (left != right) {
            left /= 2;
            right /= 2;
            divisor *= 2;
        }
        result = left * divisor;
        
        return result;
    }
};
