// class Solution {
// public:
//     int lengthOfLongestSubstring(string s)
//      {  
//          int max=0,i,j;
//         for(int i=0;i<s.length();i++)
//         {    
//             int c=0;
//             map<char,int>map; 
//             for(j=i;j<s.length();j++)
//             {
//                map[s[j]]++;
//                  if(map[s[j]]==2)
//                  {  
//                      break;
//                  }
//                  c++;
//             }  
//             if(c>max)
//             {
//                 max=c;  
//             }
//         }  
//         return max;  
//      }
// };
// optimized code
// #include <unordered_map>
// #include <string>
// #include <algorithm>
// using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map; // Tracks the latest position of each character
        int maxLength = 0;
        int left = 0; // Sliding window start

        for (int right = 0; right < s.length(); right++) {
            char currentChar = s[right];

            // If the character is already in the map and within the current window
            if (map.find(currentChar) != map.end() && map[currentChar] >= left) {
                // Move the left pointer to one position after the last occurrence
                left = map[currentChar] + 1;
            }

            // Update the latest index of the current character
            map[currentChar] = right;

            // Calculate the length of the current substring
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
