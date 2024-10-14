class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans=0;
        priority_queue<int> pq;
        for(auto &it:nums) pq.push(it);

        for(int i=0;i<k;i++){
            auto tp=pq.top();
            pq.pop();
            ans+=tp;
            int toInsert=ceil((tp*1.0)/3);
            pq.push(toInsert);
        }
        return ans;
    }
};