class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        priority_queue<int> candidate;
        priority_queue <int, vector<int>, greater<int> > chosen;

        int n=nums.size();
        int ans=0;
        sort(queries.begin(),queries.end());
        int j=0;
        int m=queries.size();
        for(int i=0;i<n;i++){
            // first step is to push valid candidate into max Heap
            while(j<m && queries[j][0]==i){
                candidate.push(queries[j][1]);
                j++;
            }
            // now we will check if we have previous range that cover this element
            nums[i]-=chosen.size();
            // now we need to choose from candidate number of candidate such that
            // his range is correct and required to make nums[i] to 0
            while(nums[i]>0 && !candidate.empty() && candidate.top()>=i){
                // third condition is checking max range of candidate
                // uska range agar i se kam hai then wo koi kaam ka nhi
                ans++;//here this much candidate is needed to make it zero
                nums[i]--;
                chosen.push(candidate.top());
                candidate.pop();
            }
            // if after this we dont have enough candidate to make nums[i] down to 0
            // then return -1
            if(nums[i]>0) return -1;

            // now from chosen invalid range should be removed
            while(!chosen.empty() && chosen.top()<=i) chosen.pop();
        }
        return queries.size()-ans;
    }
};