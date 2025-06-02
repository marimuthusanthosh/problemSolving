class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        if (n == 0) return 0;
        int i = 0, j = n - 1;
        int left_max = 0, right_max = 0;
        int sum = 0;
        while (i <= j) 
        {
            if (a[i] <= a[j]) 
            {
                if (a[i] >= left_max) 
                {
                    left_max = a[i];
                }
                else 
                {
                    sum += left_max - a[i];
                }
                i++;
            } 
            else 
            {
                if (a[j] >= right_max) 
                {
                    right_max = a[j];
                } else 
                {
                    sum += right_max - a[j];
                }
                j--;
            }
        }

        return sum;
    }
};
