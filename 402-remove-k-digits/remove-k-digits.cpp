class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n=num.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && (st.top()-'0')>(num[i]-'0')){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
            //deleting from back coz in the back there will be larget number
        }
        // ab iske baad stack pura ka pura empty ho skta hai so lets check
        if(st.empty()) return "0";
        // ab empty nhi hai then res me value store krlo
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        // ab problem ye hai ki ans ke piche 0 ho skta hai jo ki count nhi krna hai to usko deletr krte hai
        while(ans.length()!=0 && ans.back()=='0'){
            ans.pop_back();
        } 
        // ab iske baad bhi ho skta hai sbb zero ho so lets check
        if(ans.length()==0) return "0";
        
        //ab kyuki stack se nikale the to ulta tha to sidha kiye
        reverse(ans.begin(),ans.end());
        return ans;
    }
};