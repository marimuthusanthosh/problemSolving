class Solution 
{
public:
    int maxArea(vector<int>& a) 
    {
           int n=a.size();    
           int i=0,j=n-1; 
           int max=0,area=0; 
            while(i<j)
            {
                if(a[i]<a[j])
                {
                     area=a[i]*(j-i); 
                    i++;
                }   
                else
                {
                     area=a[j]*(j-i); 
                    j--;

                }
                    if(area>max)
                    {
                        max=area;
                    }
            }     
            return max;
    }
};
