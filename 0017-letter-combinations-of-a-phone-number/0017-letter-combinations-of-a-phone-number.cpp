class Solution {
public:  
void f(int i,map<char, vector<string>>&mp,int n,vector<string>&ans,string digits,string s)
 {     
    if(i==n)
    {  
        ans.push_back(s);
        return ;
    }
      for(int j=0;j<mp[digits[i]].size();j++)
      {
         vector <string>str=mp[digits[i]];
         s=s+str[j];
         f(i+1,mp,n,ans,digits,s);  
         s.pop_back();
      }
 }
    vector<string> letterCombinations(string digits)
    {    
        vector<string>ans;
        if(digits=="")
        {
            return ans;
        }
        int n=digits.size();
        map<char, vector<string>> mp;
        mp.insert(make_pair('2', vector<string>{"a", "b", "c"})); 
        mp.insert(make_pair('3', vector<string>{"d", "e", "f"}));
        mp.insert(make_pair('4', vector<string>{"g", "h", "i"}));
        mp.insert(make_pair('5', vector<string>{"j", "k", "l"}));
        mp.insert(make_pair('6', vector<string>{"m", "n", "o"}));
        mp.insert(make_pair('7', vector<string>{"p", "q", "r", "s"}));
        mp.insert(make_pair('8', vector<string>{"t", "u", "v"}));
        mp.insert(make_pair('9', vector<string>{"w","x", "y", "z"}));
        f(0,mp,n,ans,digits,"");  
       return ans;
    }
};