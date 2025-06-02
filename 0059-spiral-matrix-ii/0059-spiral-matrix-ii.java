class Solution {
    public int[][] generateMatrix(int n)
     {
        int a[][]=new int[n][n];     
        int k=1,l=0; 
        int left=0; 
        int right=n-1;
        int top=0; 
        int bottom=n-1;  
        int i=0;
        while(k<=n*n)
        {
            while(i<=right)
            {
                a[top][i]=k;
                k++;
                i++;
            }   
            top++;  
            i=top;
            while(i<=bottom)
            {
                a[i][right]=k; 
                k++;   
                i++;
            }  
            right--;     
            i=right;
            while(i>=left)
            {
                a[bottom][i]=k; 
                k++;   
                i--;
            }  
            bottom--;   
            i=bottom;   
            while(i>=top)
            {
                a[i][left]=k;  
                k++; 
                i--;
            }  
            left++; 
            i=left;
        }     
         return a;
    }

}