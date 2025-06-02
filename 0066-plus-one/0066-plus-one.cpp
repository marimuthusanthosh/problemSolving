class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int n=digits.size(); 
        if(digits[n-1]!=9)
        {
        digits[n-1]=digits[n-1]+1; 
        return digits;
        }  
        int temp=n-1;
        while(temp>=0&&digits[temp]==9)
        {
            digits[temp]=0; 
            temp--; 
        }
        if (temp == -1) {
            digits.insert(digits.begin(), 1); 
        } else {
            digits[temp] += 1;
        }
        return digits;      
    }
};



// class Solution {
// public:
//     vector<int> plusOne(vector<int>& v) {
//         int n = v.size();
//         for(int i = n-1; i >= 0; i--){
//             if(i == n-1)
//             {
//                 v[i]++;
//             }
//             if(v[i] == 10)
//             {
//                 v[i] = 0;
//                 if(i != 0)
//                 {
//                     v[i-1]++;
//                 }
//                 else{
//                     v.push_back(0);
//                     v[i] = 1;
//                 }
//             }
//         }
//         return v;
//     }
// };