class Solution {
public:
    vector<int> lexicalOrder(int n) {  
        vector<int> a;
        int i = 1;
        while (a.size() < n)
         {
            a.push_back(i);
            if (i * 10 <= n) 
            {
                i *= 10;
            } 
            else 
            {
                if (i % 10 == 9 || i + 1 > n) {
                    i /= 10;
                    while (i % 10 == 9) {
                        i /= 10;
                    }
                }
                i++;
            }
        }
        return a;
    }
};