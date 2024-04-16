class Solution {
public:
    bool check(int number){
        if(number==1) return true;
        if(number==2) return false;
        for(int i=2;i*i<=number;i++){
            if(number%i==0) return true;
        }
        return false;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int ans=-1;
        while(j>=i){
            if(check(nums[i])){
                i++;
            }
            else if(check(nums[j])) j--;
            else {ans=max(ans,(j-i)); break;}
        }
        return ans;
    }
};