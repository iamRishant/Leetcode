class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]++;
        }
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int ans=1e9;
        for(int i=1000;i>=1;i--){
            int count=0;
            // int countn=0;
            map<int,int> temp=mp;
            for(int j=0;j<nums1.size();j++){
                int newNum=nums1[j]-i;
                if(newNum<0) continue;
                if(temp.find(newNum)!=temp.end()){
                    count++;
                    temp[newNum]--;
                    if(temp[newNum]==0) temp.erase(newNum);
                    cout<<count<<" "<<i<<endl;
                }
            }
            if(count==nums2.size()){
                ans=i;
                break;
            }
        }
        // cout<<"iam here"<<endl;
        if(ans!=1e9) return -ans;

        

        for(int i=0;i<=1000;i++){
            int count=0;
            // int countn=0;
            map<int,int> temp=mp;
            for(int j=0;j<nums1.size();j++){
                int newNum=nums1[j]+i;
                if(temp.find(newNum)!=temp.end()){
                    count++;
                    temp[newNum]--;
                    if(temp[newNum]==0) temp.erase(newNum);
                }
            }
            if(count==nums2.size()){
                ans=i;
                break;
            }
        }
        return ans;

    }
};