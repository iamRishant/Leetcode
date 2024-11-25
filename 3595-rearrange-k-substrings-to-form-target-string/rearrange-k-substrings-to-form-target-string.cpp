class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int len=s.length();
        if(len%k!=0) return false;

        int number=len/k;

        string str="";
        map<string,int> mp;
        for(int i=0;i<len;i++){
            str+=t[i];
            if((i+1)%number==0){
                mp[str]++;
                str="";
            }
        }
        str="";
        for(int i=0;i<len;i++){
            str+=s[i];
            if((i+1)%number==0){
                if(mp.find(str)!=mp.end()){
                    mp[str]--;
                    if(mp[str]==0) mp.erase(str);
                    str="";
                }
                else return false;
            }
        }
        return true;
    }
};