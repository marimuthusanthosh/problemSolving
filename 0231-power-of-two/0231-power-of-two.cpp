class Solution {
public:
    bool isPowerOfTwo(int n)
    {  
       int c=0; 
       if(n==0)
       {
           return 0;
       } 
       else
       {
      while(n!=1)
      {
          if(n%2!=0) 
          {
              break;
          }   
          else
          {
            n=n/2;
          }
        
        
      }     
     if(n==1)
     {
         return 1;
     }

     else
     {
         return 0;
     } 
       }
    
    }
};