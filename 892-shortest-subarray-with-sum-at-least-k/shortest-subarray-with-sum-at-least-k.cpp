class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long,long long>> > pq;
        long long sum=0;
        long long ans=1e9;
        int n=nums.size();

        pq.push({0,-1});
        for(int i=0;i<n;i++){
            sum+=nums[i];

            long long rem=sum-k;
            while(!pq.empty() && rem>=pq.top().first){
                ans=min(ans,i-pq.top().second);
                pq.pop();
            }
            pq.push({sum,i});
        }
        return ans==1e9? -1 : ans;
    }
};
// time complexity O(n*logn)