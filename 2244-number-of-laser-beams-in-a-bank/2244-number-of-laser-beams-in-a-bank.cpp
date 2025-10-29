class Solution {
public:
    int numberOfBeams(vector<string>& bank) 
    {  
        int sum=0,i,j;  
        vector<int>a;

             for(i=0;i<bank.size();i++)
             {  
               int  c=0;
                for(j=0;j<bank[i].size();j++)
                {
                    if(bank[i][j]=='1')
                    {
                        c++;
                    }
                } 
                  if(c!=0)
                  {
                     a.push_back(c);
                  }
             }      
             if(a.size()==1)
             {
                 return 0;
             } 
             else if(a.size()>1)
             {

             for(i=0;i<a.size()-1;i++)
             {
                 sum=sum+a[i]*a[i+1];
             } 
             return sum; 
             }
             return{};
    }
};