class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int> count(26,0);
        vector<int> Size;
        int ans=0;

        for(int i=0;i<words.size();i++){
            Size.push_back(words[i].size());

            for(auto it: words[i]){
                int index=it-'a';
                count[index]++;
            }
        }
        int even=0;
        int odd=0;
        for(int i=0;i<count.size();i++){
            even+=(count[i]/2)*2;//suppose a ka frequency 7 hai to even 6 hoga and odd 1
            odd+=count[i]%2;
        }
        sort(Size.begin(),Size.end());
        for(int i=0;i<Size.size();i++){
            if(Size[i]%2==0){
                if(even<Size[i]) break;
                even-=Size[i];
            }
            else{
                if(Size[i]-1>even) break;
                even-=(Size[i]-1);//even number of pair decrement krr diye
                Size[i]=1;//decrement krne ke baad sirf ek hi character baccha hoga
                if(odd==0 && even==0) break;
                if(odd==0){
                    //ab agar odd 0 hogya hai to even ko break krenge and odd me add krenge
                    even-=2;
                    odd+=2;
                }
                // now simply one place is empty we will fill it with odd
                odd--;
            }
            // if we reached this place it means answer exist
            ans++;
        }
        return ans;
    }
};
// https://www.youtube.com/watch?v=JmyUGaj4BCY