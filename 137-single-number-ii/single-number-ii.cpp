class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;

        for(int k=0;k<32;k++){
            int temp=(1<<k);
            int countOfZ=0;
            int countOfO=0;
            for(int i=0;i<nums.size();i++){
                // we will check kth bit of each number using & operator
                if((nums[i]&temp)!=0) countOfO++;
                else countOfZ++;
            }
            if((countOfO%3)==1){
                result=(result|temp);
            }
        }
        return result;
    }
};