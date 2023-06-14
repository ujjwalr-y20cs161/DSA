/*
Problem: Merge Sorted Arrays

Statement:
=>	You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

LINK::https://leetcode.com/problems/merge-sorted-array

Companies:

Tekion-corp
Bloomberg
Oracle
Microsoft
Flipkart
Walmart
CRED
Meesho
Swiggy
Dream11
InMobi
Oyo
Amazon
*/
#include <bits/stdc++.h>
#define endd
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
  // resize the nums1 to accomadate new insertions
  nums1.resize(m + n);

  // from back insert each element, if nums1[i] > nums2[j], then insert nums1[i] from the back;

  // pointers:
  int i = m - 1;
  int j = n - 1;
  // additional pointer to point the insertion:
  int k = m + n - 1;

  while (i >= 0 and j >= 0)
  {

    if (nums1[i] > nums2[j])
    {
      // insert nums1[i] at nums1[k]
      nums1[k] = nums1[i];
      // decrement the pointers i,k
      --i;
      --k;
    }
    else
    {
      nums1[k] = nums2[j];
      // decrement pointers j,k:
      --j;
      --k;
    }
  }

  // insert the remaining of either of the arrays:

  while (i >= 0)
  {
    nums1[k] = nums1[i];
    --i;
    --k;
  }

  while (j >= 0)
  {
    nums1[k] = nums2[j];
    --j;
    --k;
  }
}

// Time Complexity : O(n+m)
// Space Complexity :O(1)