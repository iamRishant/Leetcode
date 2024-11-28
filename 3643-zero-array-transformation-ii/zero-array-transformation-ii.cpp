class Solution {
public:
    bool check(int mid,vector<int> nums,vector<vector<int>> &queries){
        vector<int> sweep(nums.size()+1,0);
        for(int i=0;i<mid;i++){
            sweep[queries[i][0]]+=queries[i][2];
            sweep[queries[i][1]+1]-=queries[i][2];
        }
        for(int i=1;i<sweep.size();i++){
            sweep[i]+=sweep[i-1];
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>sweep[i]) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int low=0;
        int high=queries.size();
        int ans=-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,nums,queries)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};