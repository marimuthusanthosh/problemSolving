class Solution {
public:
    int hammingWeight(int n) 
    { 
        int c=0;
        while(n!=0)
        {
            if(n%2==1)
            {
                c++;
            }
            n=n/2;
        }
    return c;
    }
};



// optimized code
// class Solution {
// public:
//     int hammingWeight(int n) {
//         int count=0;
//         while(n){
//             count+=n&1;
//             n>>=1;
//         }
//         return count;
//     }
// };