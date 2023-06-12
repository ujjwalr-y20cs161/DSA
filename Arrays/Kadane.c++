/*
Problem: Maximum Subarray


Statement:
=>Given an integer array nums, find the subarray with the largest sum, and return its sum.

LINK::https://leetcode.com/problems/maximum-subarray/

Companies:

Adobe
Samsung
Amazon
Facebook
Netflix
Flipkart
Tekion-corp
Bloomberg
CRED
Meesho
Swiggy
Dream11
InMobi

*/

#include <bits/stdc++.h>
using namespace std;

int ansStart, ansEnd;

int maxSubArray(vector<int> &nums)
{

  int n = nums.size();

  // Max sum is stored!
  int maxx = INT_MIN;
  int sum = 0;

  // to keep the sub-array that produces the MaxSum
  int start;

  // selecting from start
  for (int i = 0; i < n; i++)
  { // O(n)
    // logs the start position of new sub-array
    if (sum == 0)
      start = i;

    // sequentially add sum
    sum += nums[i];

    if (maxx < sum)
    {
      maxx = sum;
      ansStart = start;
      ansEnd = i;
    }

    sum = sum > 0 ? sum : 0;
  }

  return maxx;
  // To return a sub-array indices
  // return {ansStart,ansEnd};
}

// Time Complexity : O(N)
// Space Complexity :O(1)

int main()
{
  vector<int> arr = {2, 1, -3, 4, -1, 2, 1, -5, 4};

  // Print Sum of max subarray
  cout << maxSubArray(arr) << endl;

  // PRINT THE SUBARRAY
  vector<int> subArr(arr.begin() + ansStart, arr.begin() + ansEnd + 1);

  for (auto i : subArr)
  {
    cout << i << " ";
  }
  cout << endl;
}