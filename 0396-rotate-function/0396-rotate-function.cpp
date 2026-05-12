class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        // Step 1: compute total sum and F(0)
        int totalSum = 0;
        int F = 0;
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];           // sum of all elements
            F += i * nums[i];              // F(0)
        }

        int maxi = F;

        // Step 2: use formula F(k) = F(k-1) + totalSum - n * nums[n-k]
        for (int k = 1; k < n; k++) {
            F = F + totalSum - n * nums[n - k];   // O(1) per rotation
            maxi = max(maxi, F);
        }

        return maxi;
    }
};

// This is completely mathemtical sum, this is what i tried to do 
// n = 4
// totalSum = 4+3+2+6 = 15

// F(0) = 0*4 + 1*3 + 2*2 + 3*6 = 0+3+4+18 = 25
// maxi = 25

// k=1: F(1) = F(0) + totalSum - n*nums[n-1]
//           = 25   + 15       - 4*nums[3]
//           = 25   + 15       - 4*6
//           = 25   + 15       - 24  = 16
//      maxi = max(25, 16) = 25

// k=2: F(2) = F(1) + totalSum - n*nums[n-2]
//           = 16   + 15       - 4*nums[2]
//           = 16   + 15       - 4*2
//           = 16   + 15       - 8   = 23
//      maxi = max(25, 23) = 25

// k=3: F(3) = F(2) + totalSum - n*nums[n-3]
//           = 23   + 15       - 4*nums[1]
//           = 23   + 15       - 4*3
//           = 23   + 15       - 12  = 26
//      maxi = max(25, 26) = 26 ✓