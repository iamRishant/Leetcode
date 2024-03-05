class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n=nums.size();
        
        if(n==1 && k%2!=0) return -1;
        else if(n==1 && k%2==0) return nums[0];

        if(n>k){
            int maxi=-1;
            for(int i=0;i<k-1;i++) maxi=max(nums[i],maxi);
            return max(nums[k],maxi);
        }
        else if(n==k){
            int maxi=-1;
            for(int i=0;i<n-1;i++){
                maxi=max(nums[i],maxi);
            }
            return maxi;
        }
        else{
            int insert=k/n;
            k=k%n;
            sort(nums.begin(),nums.end());
            if(insert%2==0){
                if(k==1) return nums[n-2];
                else return nums[n-1];
            }
            else {

                return nums[n-1];
            }
        }
        return -1;
    }
};