class Solution {
public:
    bool check(long long i, vector<int> nums,int k){
        int student=1;
        int numberOfPages=0;
        // ye andr wala kaam to prefix sum se bhi krr lenge range find krna main kaam tha
        for(int j=0;j<nums.size();j++){
            if(numberOfPages+nums[j]<=i){
                numberOfPages+=nums[j];
            }
            else{
                // goto  next student
                student++;
                numberOfPages=nums[j];
            }
        }
        if(student<=k) return 0;
        return 1;
        
    }
    int splitArray(vector<int>& nums, int k) {
        // this is same as book allocation problem
        int low=-1;
        for(int i=0;i<nums.size();i++) {low=max(nums[i],low);};
        long long high=accumulate(nums.begin(),nums.end(),0);

        int ans=high;
        while(high>=low){
            int mid=low+(high-low)/2;

            bool val=check(mid,nums,k);
            if(val){
                low=mid+1;
            }
            else{
                ans=min(mid,ans);
                high=mid-1;
            }
        }
        return ans;


    }
};