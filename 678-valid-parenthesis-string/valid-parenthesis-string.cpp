class Solution {
public:
    bool checkValidString(string s) {
        int leftMin=0,leftMax=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                leftMin++;
                leftMax++;
            }
            else if(s[i]==')'){
                leftMin--;
                leftMax--;
            }
            else{
                //now here either we can take * as open or close if thats why we are taking 2 variable one to increase and one to decrease
                leftMin--;// * as )
                leftMax++;// * as (
            }
            // now if leftMax is -ve at any point it means there are more closing brackets than open and we cannot recover from that
            if(leftMax<0) return false;
            // if we have leftMin < 0 it means just jha par * ko as ) liye the wha blank krr denge 
            if(leftMin<0) leftMin=0;
            
        }
        if(leftMin==0) return true;//minimum open bracket should be 0 
        return false;
        
        
    }
};