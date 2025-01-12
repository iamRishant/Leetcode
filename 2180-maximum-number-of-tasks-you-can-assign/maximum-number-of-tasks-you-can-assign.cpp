class Solution {
public:

    bool check(vector<int> &tasks,vector<int> &workers,int mid,int pills,int strength){
        // we need to store mid number of strongest workers 
        multiset<int> ms(workers.end()-mid,workers.end());
        //now we will check if mid number of smaller tasks can be completed by these workers
        for(int i=mid-1;i>=0;i--){
            auto it=ms.end();
            it--;//pointing on last worker

            if(tasks[i]> *it){
                //means strength required to do the task is more than worker
                // in this case first check do we have pills
                if(!pills) return false;//if no pills then kucch nhi ho skta

                // now check if we have any worker with strength matching with task
                //here is why we need multiset coz we need sbse chota worker + strength who
                // can complete the work so that worker with higher strength can do 
                //other tasks
                //worker+strength>=tasks[i] therefore worker>= tasks[i]-strength
                //it means we need a worker whose strength is tasks[i]-strength atleast
                // we will not delete the current worker we need to find new
                it=ms.lower_bound(tasks[i]-strength);
                if(it!=ms.end()) pills--;
                else return false;
            }
            ms.erase(it); //worker to htanan pdega na
        }
        //it means tasks hogya
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n=tasks.size();
        int m=workers.size();
        int low=0;
        int high=min(n,m);
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());

        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(check(tasks,workers,mid,pills,strength)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};