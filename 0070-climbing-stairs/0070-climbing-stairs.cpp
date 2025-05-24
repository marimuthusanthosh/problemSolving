class Solution {
public:
    int climbStairs(int n) 
    {
      int a=1,b=2,c=3,sum=0,sum1=0,i;   
      
      if(n==1||n==2)
      {
          return n;
      } 
      else
      {
        for(i=2;i<n;i++)
        {
            c=a+b;  
            a=b;
            b=c;   
        
        } 
      } 
      return c;
    }   
};