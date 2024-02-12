class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int person1=INT_MIN;
        int person2=INT_MIN;
        int cPerson1=0;
        int cPerson2=0;
        for(int i=0;i<nums.size();i++){
            if(cPerson1==0 && nums[i]!=person2){
                cPerson1=1;
                person1=nums[i];
            }
            else if(cPerson2==0 && nums[i]!=person1){
                cPerson2=1;
                person2=nums[i];
            }
            else if(nums[i]==person1) cPerson1++;
            else if(nums[i]==person2) cPerson2++;
            else{
                cPerson1--;
                cPerson2--;
            }
        }

        cPerson1=0;
        cPerson2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==person1) cPerson1++;
            else if(nums[i]==person2) cPerson2++;
        }
        vector<int> ans;
        if(cPerson1>nums.size()/3) ans.push_back(person1);
        if(cPerson2>nums.size()/3) ans.push_back(person2);
        return ans;
    }
};