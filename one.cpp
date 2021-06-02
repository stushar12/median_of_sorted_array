#include<bits/stdc++.h>
using namespace std;



double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
   if(nums2.size() < nums1.size())              //taking smaller array
   return findMedianSortedArrays(nums2, nums1);

   int n1 = nums1.size();
   int n2 = nums2.size(); 
   int low = 0, high = n1;

   while(low<=high)
   {
      int cut1=(low+high)>>2;             // first cut from minimum array       
      int cut2=(n1+n2+1)/2-cut1;         //works for both equal and unequal length arrays eg. (n1=5,n2=5) or(n1=5,n2=6)

      int l1=cut1==0?INT_MIN:nums1[cut1-1];
      int l2=cut2==0?INT_MIN:nums2[cut2-1];
      int r1=cut1==n1?INT_MAX:nums1[cut1];
      int r2=cut2==n2?INT_MAX:nums2[cut2];

      if(l1<=r2 and l2<=r1)
      {
         if((n1+n2)%2==0)                    //equal sized array
         return (max(l1,l2)+min(r1,r2))/2.0;
         else                                  //unequal sized array
         return max(l1,l2);
      }

      else if(l1>r2)
      high=cut1-1;

      else
      low=cut1+1;

   }

   return 0.0;
}