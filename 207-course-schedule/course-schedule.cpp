class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        // we need to find a safe sequence type of thing which u---> v mean us should come before v
        // lets create a graph bi-->ai
        
        vector<int> adj[numCourses];
        for(int i=0;i<pre.size();i++){
            int bi=pre[i][1];
            int ai=pre[i][0];
            adj[bi].push_back(ai);
        }

        // we can use topo sort to see if a person can get all the course or not
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }

        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(count==numCourses) return true;
        return false;
    }
};