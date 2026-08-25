class Solution {
  public:
    bool isPossible(vector<int>& arr, int s, int x) {

        vector<long long> seq;
        seq.push_back(s);

        long long sum = s;

        for (int num : arr) {
            long long next = sum + num;
            seq.push_back(next);
            sum += next;
        }

        long long target = x;

        for (int i = seq.size() - 1; i >= 0; i--) {
            if (seq[i] <= target) {
                target -= seq[i];
            }
        }

        return target == 0;
    }
};