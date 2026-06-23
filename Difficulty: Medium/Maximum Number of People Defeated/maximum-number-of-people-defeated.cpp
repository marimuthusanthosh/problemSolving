class Solution {
public:
    int maxPeopleDefeated(int p) {
        
        
        int n = 1;
        while (p >= n * n) {
            p -= n * n;
            n++;
        }

        return n-1;
    }
};