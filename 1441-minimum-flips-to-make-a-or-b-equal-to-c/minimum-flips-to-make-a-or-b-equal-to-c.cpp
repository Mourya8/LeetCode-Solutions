class Solution {
public:
   vector<int> decToBinary(int n ){
    
   vector<int>binaryNum(32,0);
 
   
    int i = 0;
    while (n > 0) {
 
       
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    return binaryNum;
     }
    int minFlips(int a, int b, int c) {
        
        
    vector<int>binarya=decToBinary(a );
    vector<int> binaryb=decToBinary( b );
    vector<int> binaryc=decToBinary( c );
     int ans=0;
    
     
     for(int i=0;i<32;i++){
         if((binarya[i] | binaryb[i])==binaryc[i]){
             
             continue;
         }
         else if(binaryc[i]==0){
             if(binarya[i]==1 && binaryb[i]==1){
                 
                 ans=ans+2;
                //  continue;
             }
             else{
                 
                 ans++;
                 continue;
             }
         }
         else if(binaryc[i]==1) {
             
              if(binarya[i]==0 && binaryb[i]==0){
                  ans++;
              }
             
            //  continue;
         }
     }
     return ans;
       
    }
};