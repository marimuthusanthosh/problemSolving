class Solution {
public:
    bool isPowerOfThree(int n)
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
          if(n%3!=0) 
          {
              break;
          }   
          else
          {
            n=n/3;
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
