class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
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

        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            // count++;
            topo.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(topo.size()==numCourses) return topo;
        return {};
    }
};