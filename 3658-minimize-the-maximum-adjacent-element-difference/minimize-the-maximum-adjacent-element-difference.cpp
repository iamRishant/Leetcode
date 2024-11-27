class Solution {
public:
    bool check(int maxD,vector<int> nums){
        // first we need x and y to jo -1 ke aas pas hai unka min and max
        // chhaiye

        int x=INT_MAX;
        int y=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=-1 && ((i!=0 && nums[i-1]==-1) || ((i!=(nums.size()-1)) && nums[i+1]==-1) )){
                // this means this number is adjacent of -1
                x=min(x,nums[i]);
                y=max(y,nums[i]);
            }
        }

        int X=x+maxD;// min val me maxD add krdo wo mera preferred x hai
        int Y=y-maxD;// max val me maxD substract krdo ye mera prefered y hai

        int flag1=1;
        int flag2=1;
        vector<int> copyNums=nums;

        // coz now they can cover more numbers
        // now we just need to replace -1 with either x or y
        for(int i=0;i<nums.size();i++){
            
            if(nums[i]==-1){
                // lets check left and right neighbour of current -ve one
                if((i==0 || abs(nums[i-1]-X)<=maxD) && (i==(nums.size()-1) || nums[i+1]==-1 || abs(nums[i+1]-X)<=maxD)) nums[i]=X;
                else nums[i]=Y;
            }
        } 
        // final check
        
        

        for(int i=0;i<nums.size()-1;i++){
            if(abs(nums[i]-nums[i+1])>maxD) {
                flag1=0;
            }
        }

        nums=copyNums;
        for(int i=0;i<nums.size();i++){
            
            if(nums[i]==-1){
                // lets check left and right neighbour of current -ve one
                if((i==0 || abs(nums[i-1]-Y)<=maxD) && (i==(nums.size()-1) || nums[i+1]==-1 || abs(nums[i+1]-Y)<=maxD)) nums[i]=Y;
                else nums[i]=X;
            }
        } 
        // final check
        
        

        for(int i=0;i<nums.size()-1;i++){
            if(abs(nums[i]-nums[i+1])>maxD) {
                flag2=0;
            }
        }
        return flag1 || flag2;
    }
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        int replaceCount=0;
        for(int i=0;i<n;i++) if(nums[i]==-1) replaceCount++;

        if(replaceCount==0){
            int maxi=0;
            for(int i=0;i<n-1;i++) maxi=max(maxi,abs(nums[i]-nums[i+1]));
            return maxi;
        }
        else if(replaceCount==n) return 0;

        int low=0;
        int high=1e9;
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,nums)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};