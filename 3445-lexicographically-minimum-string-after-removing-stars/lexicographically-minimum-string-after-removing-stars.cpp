class Solution {
public:
    string clearStars(string s) {
        int n=s.length();
        priority_queue < pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        vector<int> ans(n,-1);
        // int minCharInd=-1;
        // int miniMumChar=1e9;
        for(int i=0;i<s.length();i++){
            if(s[i]!='*'){
                ans[i]=s[i]-'a';
            }
            else if(s[i]== '*' && pq.empty()==true){continue;}
            else{
                auto it=pq.top();
                int ind=n-it.second;
                ans[ind]=-1;
                pq.pop();
            }
            if(s[i]!='*') pq.push({s[i]-'a',n-i});
        }


        string anss="";
        for(int i=0;i<n;i++){
            if(ans[i]!=-1) anss+=ans[i]+'a';
        }
        return anss;

    }
};