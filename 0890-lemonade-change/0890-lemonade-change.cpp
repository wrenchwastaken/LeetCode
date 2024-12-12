class Solution{    
  public:    
    bool lemonadeChange(vector<int>& bills){
      //your code goes here
      int f = 0;
      int t = 0;
      for(int i=0;i<bills.size();i++){
        if(bills[i] == 5){
          f++;
        }
        else if(bills[i] == 10){
          if(f){
            f--;
            t++;
          }
          else{
            return false;
          }
        }
        else{
          if(f && t){
            f--;
            t--;
          }
          else if(f>=3){
            f-=3;
          }
          else{
            return false;
          }
        }
      }
      return true;
    }
};