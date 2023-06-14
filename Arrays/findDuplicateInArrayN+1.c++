/*
Problem: Find the Duplicate Number

Statement:
=>Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

LINK:: https://leetcode.com/problems/find-the-duplicate-number/

Companies:

Amazon
Adobe
Samsung
Netflix
Walmart
Bloomberg
CRED
Meesho
Swiggy
Dream11
InMobi
Oyo
PayTM
Byju's

*/

#include <bits/stdc++.h>
#define endd
using namespace std;

int findDuplicate(vector<int> &nums)
{
  // naive approach using map

  //     unordered_map<int,int>freq;

  //     for(auto i : nums){
  //         if(freq.find(i)==freq.end()){
  //             freq[i] = 1;
  //         }else{
  //             return i;
  //         }
  //     }

  //     return 0;
  // }

  // naive approach using integer array:

  vector<int> freq(nums.size() + 1, 0);

  for (auto i : nums)
  {
    if (freq[i] == 0)
    {
      freq[i] = 1;
    }
    else
    {
      return i;
    }
  }
  return 0;
}

// Time Complexity : O(N)
// Space Complexity :O(N)

// :: Optimized Approach Using Fast Pointer and Slow pointer.
// Learn Floyd's Cycle Detection
