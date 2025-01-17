class Solution {
public:
    bool check(int mid,vector<int> &tasks,vector<int> & workers,int pills,int strength){
        multiset<int> st(workers.end()-mid,workers.end());
        for(int i=mid-1;i>=0;i--){
            auto it=st.end();
            it--;

            if(tasks[i]>*it){
                if(!pills) return false;
                it=st.lower_bound(tasks[i]-strength);
                if(it!=st.end()) pills--;
                else return false;
            }
            st.erase(it);
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int low=0;
        int high=min(tasks.size(),workers.size());

        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());

        int ans=-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,tasks,workers,pills,strength)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
                    
        }
        return ans;
    }
};