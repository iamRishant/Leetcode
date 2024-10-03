class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0;
        int count2=0;
        int p1=-1;
        int p2=-2;
        for(int i=0;i<nums.size();i++){
            if(count1==0 && nums[i]!=p2){
                p1=nums[i];
                count1=1;
            }
            else if(count2==0 && nums[i]!=p1){
                p2=nums[i];
                count2=1;
            }
            else if(nums[i]==p1) count1++;
            else if(nums[i]==p2) count2++;
            else {
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==p1) count1++;
            else if(nums[i]==p2) count2++;
        }
        int n=nums.size();
        vector<int> ans;
        if(count1>(n/3)) ans.push_back(p1);
        if(count2>(n/3)) ans.push_back(p2);

        return ans;
        
    }
};