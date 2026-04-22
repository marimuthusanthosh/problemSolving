class Solution {
  public:
  
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    
    int countSteps(int fromCap, int toCap, int d){
        
        int from = fromCap;
        int to = 0;
        int steps = 1;  // first fill
        
        while(from != d && to != d){
            
            int pour = min(from, toCap - to);
            to += pour;
            from -= pour;
            steps++;
            
            if(from == d || to == d)
                break;
            
            if(from == 0){
                from = fromCap;
                steps++;
            }
            
            if(to == toCap){
                to = 0;
                steps++;
            }
        }
        
        return steps;
    }
    
    int minSteps(int m, int n, int d) {
        
        // impossible cases
        if(d > max(m, n)) return -1;
        if(d % gcd(m, n) != 0) return -1;
        
        // already present
        if(d == m || d == n) return 1;
        
        // compute both directions
        return min(countSteps(m, n, d), countSteps(n, m, d));
    }
};