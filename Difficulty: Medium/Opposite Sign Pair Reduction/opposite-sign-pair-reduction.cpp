class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        stack<int> st;
        
        for(int i = 0; i < arr.size(); i++){
            int cur = arr[i];
            
            while(!st.empty()){
                int top = st.top();
                
                if((top > 0 && cur < 0) || (top < 0 && cur > 0)){
                    
                    if(abs(top) == abs(cur)){
                        st.pop();
                        cur = INT_MIN;
                        break;
                    }
                    else if(abs(top) > abs(cur)){
                        cur = INT_MIN;
                        break;
                    }
                    else{
                        st.pop();
                    }
                }
                else{
                    break;
                }
            }
            
            if(cur != INT_MIN){
                st.push(cur);
            }
        }
        
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};