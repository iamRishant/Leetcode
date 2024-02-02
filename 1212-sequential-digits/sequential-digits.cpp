class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s="123456789";
        vector<int> anss;
        for(int i=0;i<s.length();i++){
            string ans="";
            for(int j=i;j<s.length();j++){
                ans+=s[j];
                if(stoi(ans)>=low && stoi(ans)<=high) anss.push_back(stoi(ans));
            }
        }
        sort(anss.begin(),anss.end());
        return anss;
    }
};