class Solution {
public:
    int scoreOfParentheses(string s) {

        stack<char>st;

        int score=0; 
        int n=s.length();

        for(int i=0;i<n;i++){

            if(s[i]=='('){
                
                st.push(score);
                score=0;
            }
            else{

                score=st.top()+max(2*score,1);
                st.pop();

            }
         
        }
        return score;
        
    }
};