class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score=0;
        set<pair<int,int>> st;
        for(int i=0;i<nums.size();i++) st.insert({nums[i],i});

        while(st.size()!=0){
            auto top=*st.begin();
            int idx=top.second;
            int val=top.first;
            st.erase(top);
            
            score+=val;
            int leftIdx=idx-1;
            int rightIdx=idx+1;
            
            if(leftIdx>=0 && st.find({nums[leftIdx],leftIdx})!=st.end()) st.erase({nums[leftIdx],leftIdx});
            if(rightIdx<nums.size() && st.find({nums[rightIdx],rightIdx})!=st.end()) st.erase({nums[rightIdx],rightIdx});
        }
        return score;

    }
};