class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=0;
        deque<int> maxD,minD;
        int right=0;
        int left=0;
        int n=nums.size();

        while(right<n){
            while(!maxD.empty() && nums[right]>= nums[maxD.back()]) maxD.pop_back();
            while(!minD.empty() && nums[right]<= nums[minD.back()]) minD.pop_back();
            maxD.push_back(right);
            minD.push_back(right);
            // now maxD is in increasing order and minD is in decresing order
            while(nums[maxD.front()]-nums[minD.front()]>2){
                left++;
                if(maxD.front()<left) maxD.pop_front();
                if(minD.front()<left) minD.pop_front();

                //moving left pointer and removing element from deque accordingly

            }
            ans+=(right-left+1);
            right++;
        }

        return ans;
    }
};