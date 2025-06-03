class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        vector<int> ans;
        int n = nums.size();
        int count1 = 0, el1 = INT_MIN;
        int count2 = 0, el2 = INT_MIN;

        for (int num : nums) {
            if (count1 == 0 && num != el2) {
                el1 = num;
                count1 = 1;
            }
            else if (count2 == 0 && num != el1) {
                el2 = num;
                count2 = 1;
            }
            else if (num == el1) {
                count1++;
            }
            else if (num == el2) {
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        for (int num : nums) {
            if (num == el1) count1++;
            else if (num == el2) count2++;
        }

        if (count1 > n / 3) ans.push_back(el1);
        if (count2 > n / 3) ans.push_back(el2);

        return ans;
    }
};