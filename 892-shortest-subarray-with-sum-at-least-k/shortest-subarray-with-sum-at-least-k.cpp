class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        long long preFixSum=0;
        long long ans=INT_MAX;
        deque<pair<long long,long long>> dq;//{prefixsum,index}
        dq.push_back({0,-1});

        for(int i=0;i<n;i++){
            preFixSum+=nums[i];
            while(!dq.empty() && preFixSum<dq.back().first) dq.pop_back();
            long long rem=preFixSum-k;
            while(!dq.empty() && rem>=dq.front().first){
                ans=min(ans,i-dq.front().second);
                dq.pop_front();
            }
            dq.push_back({preFixSum,i});
        }

        return ans==INT_MAX? -1:ans;

    }
};
// time complexity O(n)
// https://www.youtube.com/watch?v=Jm-ZTGd6TOQ