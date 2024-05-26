class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        map<long long,int> mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]*k]++;
        }
        long long ans=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%k!=0) continue;//if it is not divisble by k then k ke kissy factor se divide nhi hoga
            for(int f=1;f*f<=nums1[i];f++){
                if(nums1[i]%f==0){
                    // it means f is a factore
                    int f1=f;
                    int f2=nums1[i]/f;
                    ans+=mp[f1];
                    if(f1!=f2) ans+=mp[f2];
                }
            }


        }
            return ans;
        
    }
};