// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs)
//      {     
//         sort(strs.begin(),strs.end()); 
//          vector<string>str=strs;
//          vector<vector<string>>a;  
//         for(int i=0;i<str.size();i++)
//         {
//            sort(str[i].begin(),str[i].end());
//         }   
//         for(int i=0;i<str.size();i++)
//         {  
//             vector<string>temp;
//             if(str[i]!="-1")
//             {
//             temp.push_back(strs[i]);
//             for(int j=i+1;j<str.size();j++)
//             {
//               if(str[i]==str[j]&&str[j]!="-1")
//               {
//                   temp.push_back(strs[j]);   
//                   str[j]="-1";
                
//               }
//             }  
//             a.push_back(temp);
//             }
//         }   
        
//          return a;
//      }
// };
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
         
        for(auto x: strs){
            string word = x;
            sort(word.begin(), word.end());
            mp[word].push_back(x);
        }
        
        vector<vector<string>> ans;
        for(auto x: mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};