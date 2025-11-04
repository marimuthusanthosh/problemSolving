class Solution {
    public int totalMoney(int n) {
        int sum = 0;

        if (n <= 7) {
            return n * (n + 1) / 2;
        } else {
            int c = 0, y = 1;
            for (int i = 1; i <= n; i++) {
                sum += (y + c);
                y++;
                if (i % 7 == 0) {
                    c++;
                    y = 1;
                }
            }
        }

        return sum;
    }
}
