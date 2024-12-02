class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> vec;
        string s="";

        for(int i=0;i<sentence.size();i++){
            if(sentence[i] ==' ') {vec.push_back(s);s="";}
            else s+=sentence[i];
        }

        if(s!="") vec.push_back(s);

        int n=vec.size();
        for(int k=0;k<n;k++){
            string word=vec[k];
            int i=0;
            int j=0;
            while(i< word.size() && j<searchWord.size()){
                if(word[i]==searchWord[j]){
                    i++;
                    j++;
                }
                else break;
            }
            if(j==searchWord.size()) return k+1;

        }
        return -1;
    }
};