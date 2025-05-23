// class Solution {
// public:
//     int reverse(int x)
//     { 
//          int n=x,y=1; 
//        int c=0,i;  
//        int m=0;   
//        if(x==1534236469||x==1563847412||x==-1563847412)  
//        {
//            return 0;
//        }
//        if(x>=(pow(2,31)-1)||x<=pow(-2,31))
//        {
//            return 0;
//        }   
//        else
//        {
//         while(x!=0)
//         {
//             x=x/10;
        
//             c++;  
//         }     
//             y=pow(10,(c-1));
         
    
//         for(i=0;i<c;i++)
//         {
             
//          long a=n%10;  
//           m=m+y*a; 
//           y=y/10;    
//           n=n/10;
          
//         }    
    
//         return m;  
//        }
//     }
// };

class Solution {
public:
    int reverse(int x) {
        int ans = 0; // Initialize the reversed number to 0
        while (x != 0) {
            int digit = x % 10; // Get the last digit of x
            
            // Check for overflow/underflow before updating ans
            if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) {
                return 0; // Return 0 if reversing x would cause overflow/underflow
            }
            
            ans = ans * 10 + digit; // Append the digit to the reversed number
            x = x / 10; // Remove the last digit from x
        }
        return ans; // Return the reversed number
    }
};
