class Solution {
    public int totalElements(int[] arr) {
        // code here
          Map<Integer, Integer> map = new HashMap<>();
    int l = 0, r = 0, n = arr.length, maxLen = 0;

    while (r < n) {
        map.put(arr[r], map.getOrDefault(arr[r], 0) + 1);

        while (map.size() > 2) {
            int leftNum = arr[l];
            map.put(leftNum, map.get(leftNum) - 1);
            if (map.get(leftNum) == 0) {
                map.remove(leftNum);
            }
            l++;
        }

        maxLen = Math.max(maxLen, r - l + 1);
        r++;
    }

    return maxLen;
    }
}