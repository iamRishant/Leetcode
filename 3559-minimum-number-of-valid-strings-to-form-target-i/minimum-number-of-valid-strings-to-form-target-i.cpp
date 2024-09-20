class Solution {
public:
    vector<int> dp;
    int n;
    struct TrieNode{
        TrieNode*children[26];
        TrieNode(){
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
        }
    };
    class Trie{
        // variable declaration
        TrieNode *root;
        public:
        Trie(){
            root=new TrieNode();
        }
        void insert(string &word){
            TrieNode* mover=root;
            for(int i=0;i<word.size();i++){
                char child = word[i];
                if(mover->children[child-'a']==NULL)
                    mover->children[child-'a']=new TrieNode();
                mover=mover->children[child-'a'];
            }
        }
        int solve(int index,string &target,vector<int> &dp,int n){
            if(index==n) return 0;
            if(dp[index]!=-1) return dp[index];

            int i=index;
            int ans=1e9;
            TrieNode * node=root;
            while(i<n){
                char ch=target[i];
                if(node->children[ch-'a']==NULL) break;
                ans=min(ans,1+solve(i+1,target,dp,n));
                node=node->children[ch-'a'];
                i++;
            } 
            return dp[index]=ans;
        }
    };
    int minValidStrings(vector<string>& words, string target) {
        n=target.size();
        Trie root;
        for(auto word: words){
            root.insert(word);
        }
        dp=vector<int> (n+1,-1);
        int ans=root.solve(0,target,dp,n);
        if(ans>=1e9) return -1;
        
        return ans;
    }
};