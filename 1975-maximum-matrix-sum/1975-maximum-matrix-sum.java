class Solution {
    public long maxMatrixSum(int[][] a) {
        long sum = 0;
        int mini = Integer.MAX_VALUE;
        int negativeCount = 0;

        int n = a.length;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = Math.abs(a[i][j]);
                sum += val;
                mini = Math.min(mini, val);
                if (a[i][j] < 0) {
                    negativeCount++;
                }
            }
        }

        if (negativeCount % 2 != 0) {
            sum -= 2L * mini;
        }

        return sum;
    }
}
