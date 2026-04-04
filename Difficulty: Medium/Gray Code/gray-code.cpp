class Solution {
public:
    vector<string> graycode(int n) {
        vector<string> result;

        result.push_back("0");
        if (n == 1) {
            result.push_back("1");
            return result;
        }

        result.push_back("1");

        for (int i = 2; i <= n; i++) {
            int size = result.size();

            for (int j = size - 1; j >= 0; j--) {
                result.push_back("1" + result[j]);
            }

            for (int j = 0; j < size; j++) {
                result[j] = "0" + result[j];
            }
        }

        return result;
    }
};