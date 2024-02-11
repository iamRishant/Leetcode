class Solution {
public:
    int addDigits(int nums) {
        long long sum=0;
        int count=0;
        // cout<<nums/10<<" "<<nums%10<<endl;
        while(nums>9){
            sum=0;
            while(nums>0){
                int digit=nums%10;
                cout<<digit<<endl;
                sum+=digit;
                cout<<sum<<endl;
                nums=nums/10;
                cout<<nums<<endl;
            }
            nums=sum;
            cout<<nums<<endl;
        }
        return nums;
    }
};