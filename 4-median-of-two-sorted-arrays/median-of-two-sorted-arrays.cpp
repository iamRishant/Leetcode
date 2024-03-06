class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        int left=(n1+n2+1)/2;
        int low=0;
        int high=n1;
        int ele1=-1;
        int ele2=-1;
        while(high>=low){
            int mid1=low+(high-low)/2;//number of element froms first array
            int mid2=left-mid1;//number of element form second array
            int l1=INT_MIN;
            int l2=INT_MIN;
            int r1=INT_MAX;
            int r2=INT_MAX;

            if(mid1<n1) r1=nums1[mid1];
            if(mid1-1>=0) l1=nums1[mid1-1];
            if(mid2<n2) r2=nums2[mid2];
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

        if((n1+n2)%2==0) return (double)(ele1+ele2)/2.0;
        return ele1;
    }
};