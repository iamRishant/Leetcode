class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);//bas bakchodi krr rhe ki first array ka size kam rhe
        int low=0;
        int high=n1;
        //minimum no element from array 1 and max is all element from array one
        int leftElements=(n1+n2+1)/2;// agar odd bhi rhega to 3 element on left so that l1 and l2 ka max se mera nikal jaega
        int ele1=-1;
        int ele2=-1;
        while(high>=low){
            int mid1=low+(high-low)/2;

            int mid2=leftElements-mid1;

            int l1=INT_MIN;
            int l2=INT_MIN;
            int r1=INT_MAX;
            int r2=INT_MAX;
            if(mid1<n1) r1=nums1[mid1];
            if(mid2<n2) r2=nums2[mid2];
            if(mid1-1>=0) l1=nums1[mid1-1];
            if(mid2-1>=0) l2=nums2[mid2-1];

            if(l1<=r2 && l2<=r1){
                ele1=max(l1,l2);
                ele2=min(r1,r2);
                break;
            }
            else if(l1>r2){
                high=mid1-1;
            }
            else low=mid1+1;

        }
        if((n1+n2)%2!=0) return ele1;
        
        return (double)(ele1+ele2)/2.0;


    }
};