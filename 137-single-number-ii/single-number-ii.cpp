class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        // we will build answer bit by bit
        for(int k=0;k<32;k++){
            int temp=(1<<k);
            // int countOfZ=0;
            int countOfO=0;
            for(int i=0;i<nums.size();i++){
                // we will check kth bit of each number using & operator
                if((nums[i]&temp)!=0) countOfO++;
                // else countOfZ++; //no use counting number of 0
            }
            // if number of 0s are odd no need to do anything but if number of 1s are odd
            // then we have to update our answer bit
            if((countOfO%3)==1){
                result=(result|temp);
            }
        }
        return result;
    }
};