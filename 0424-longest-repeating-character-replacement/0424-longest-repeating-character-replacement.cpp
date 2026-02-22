class Solution {
public:
    int characterReplacement(string s, int k) {  

        int l=0,r=0; 
        int n=s.length();  
        map<int,int>freq;
        int maxf=0;
        int maxWindowLength=0;

        while(r<n){   
        
            freq[s[r]-'A']++;

            maxf=max(maxf,freq[s[r]-'A']); 
           
                while(r-l+1-maxf>k){ 
                    freq[s[l]-'A']--; 
                    // maxWindowLength--;  
                    l++;
                }
            maxWindowLength=max(maxWindowLength,r-l+1);
            r++;
        }
        return maxWindowLength;        
    }
};