class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        int curr=0;
        
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(curr==total) ans+=2;
                else if(abs(total-curr)<=1) ans++;
            }
            else{
                curr+=nums[i];
                total-=nums[i];
            }
        }
        return ans;
        
    }
};