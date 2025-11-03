class Solution {
    public int minCost(String colors, int[] neededTime) {

        int l = 0, r = 0, ans = 0, sum = 0, maxi = 0;
        int n = colors.length();

        while (l < n) {
            sum = 0;
            maxi = 0;
            while (r < n && colors.charAt(l) == colors.charAt(r)) {
                sum += neededTime[r];
                maxi = Math.max(maxi, neededTime[r]);
                r++;
            }
            ans += (sum - maxi);
            l = r;
        }

        return ans;
    }
}
