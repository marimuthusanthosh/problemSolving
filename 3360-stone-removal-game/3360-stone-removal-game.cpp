class Solution {
public:
    bool canAliceWin(int n) {

        
        bool a=false, b=false;
        int c=10;

        for(int i=0;n>=c;i++){

               n=n-c; 

 
                    if(i%2==0){
                        
                            a=true;
                            b=false;
                        
                    }
                    else{
                            b=true;
                            a=false;
                    }
            c--;
        }
       
      return a;
        
    }
};