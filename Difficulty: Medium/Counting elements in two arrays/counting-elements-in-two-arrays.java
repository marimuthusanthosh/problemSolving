class Solution {
    

    private static int checkLength(int[] arr, int key) {
        int low = 0, high = arr.length;

        while (low < high) {
            int mid =  (high + low) / 2;
            if (arr[mid] <= key) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low; 
    }
    
    
    public static ArrayList<Integer> countLessEq(int[] a, int[] b) {
        Arrays.sort(b);  
        ArrayList<Integer> result = new ArrayList<>();

        for (int i = 0; i < a.length; i++) {
            int count = checkLength(b, a[i]);
            result.add(count);
        }

        return result;
    }

}