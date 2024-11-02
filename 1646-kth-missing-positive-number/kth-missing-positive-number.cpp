class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // brute force

        int i=0;
        int n=arr.size();
        int num=1;
        while(i<n && k>0){
            if(arr[i]==num){
                i++;
            }
            else k--;
            num++;
        }

        while(k--){//agr abhi tk missing number nhi mila ho
            num++;
        }
        return num-1;
    }
};