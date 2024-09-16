class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int person1=INT_MIN;
        int person2=INT_MIN;
        int cp1=0;
        int cp2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(cp1==0 && nums[i]!=person2){
                cp1=1;
                person1=nums[i];
            }
            else if(cp2==0 && nums[i]!=person1){
                cp2=1;
                person2=nums[i];
            }
            else if(nums[i]==person1) cp1++;
            else if(nums[i]==person2) cp2++;
            else {cp1--; cp2--;}
        }
        // now here we have two top majority element now we just have to check there count is greater than n/3
        cp1=0;
        cp2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==person1) cp1++;
            else if(nums[i]==person2) cp2++;
        }
        vector<int> ans;
        if(cp1>n/3) ans.push_back(person1);
        if(cp2>n/3) ans.push_back(person2);

        return ans;
        
    }
};