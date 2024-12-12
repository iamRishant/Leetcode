class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        set<pair<int,int>> st;

        for(int i=0;i<gifts.size();i++){
            st.insert({gifts[i],i});
        }

        while(k--){
            auto top=*st.rbegin();
            st.erase(top);
            int val=top.first;
            int newVal=floor(sqrt(val));
            st.insert({newVal,top.second});
        }
        long long sum=0;
        for(auto it:st) sum+=it.first;
        return sum;
    }
};