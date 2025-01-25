class Solution {
public:
    map<int,int> mp;
    void swap(vector<int> &arr,int left,int right){
        int temp=arr[left];
        arr[left]=arr[right];
        arr[right]=temp;

        mp[arr[left]]=left;
        mp[arr[right]]=right;
    }
    int minSwapsCouples(vector<int>& row) {
        // map<int,int> mp;
        int n=row.size();
        for(int i=0;i<n;i++){
            mp[row[i]]=i;
        }
        int count=0;
        
        for(int i=0;i<n;i+=2){
            int first=row[i];
            int second=first^1;//it first is even it will decrement and vice versa
            if(row[i+1] !=second){
                count++;
                swap(row,i+1,mp[second]);
                // mp[row[i+1]]=mp[second];
                // mp[second]=i+1;

            }
        }
        

        return count;
    }
};