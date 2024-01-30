class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.size()) return false;
        string newString=s;
        newString+=s;
        auto found=newString.find(goal);
        return !(found==-1);
    }
};