class Solution {
public:
    int findComplement(int num) 
    {   
        int sum=0,c=0;
        while(num!=0)
        {  
            if(num%2==0)
            {
              sum=sum+1*pow(2,c);
            }  
            c++;  
            num=num/2;
        }
    return sum;
    }   
};