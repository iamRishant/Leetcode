class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            string word=it.first;
            int step=it.second;
            if(word==endWord) return step;

            for(int i=0;i<word.size();i++){
                // we will linearly change each character and check if it exists or not
                char original=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(st.find(word)!=st.end()){
                        q.push({word,step+1});
                        st.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        return 0;

    }
};