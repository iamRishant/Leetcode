class Solution {
public:
    bool isCircularSentence(string sentence) {
        char first=sentence[0];
        char last=sentence[0];
        for(int i=1;i<sentence.size();i++){
            if(sentence[i-1]==' '){
                if(sentence[i]!=last) return false;
            }
            if(sentence[i]!=' ') last=sentence[i];
        }
        return first==last;
    }
};