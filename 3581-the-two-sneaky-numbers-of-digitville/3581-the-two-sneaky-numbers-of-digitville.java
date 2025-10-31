import java.util.*;

class Solution {
    public int[] getSneakyNumbers(int[] nums) {
        Map<Integer, Integer> mp = new HashMap<>();
        int[] res = new int[2];
        int k = 0;

        for (int num : nums) {
            mp.put(num, mp.getOrDefault(num, 0) + 1);
            if (mp.get(num) == 2) {
                res[k++] = num;
            }
        }
        return res;
    }
}
