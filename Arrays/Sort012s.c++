/*
Problem:Sort an array of 0s, 1s and 2s

Statement:
=>Problem Statement: Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array without using inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)

LINK:: https://leetcode.com/problems/sort-colors/

Companies:
Google
Amazon
Microsoft
Netflix
Tekion-corp
Flipkart
Bloomberg
Samsung
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
#define endd "\n"
using namespace std;

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

//
void sortColors(vector<int> &nums)
{

  int n = nums.size();

  // 3 pointer approach
  int low = 0;      // low points until the end of zeroes
  int mid = 0;      // mid points untill the end of ones
  int high = n - 1; // high points to start of the twos

  // if mid exceeds means there are no twos left
  while (mid <= high)
  {
    // if mid points 0 then we swap it to zero and update low and mid
    if (nums[mid] == 0)
    {
      swap(nums[low], nums[mid]);
      low++;
      mid++;
    }
    else if (nums[mid] == 1)
    { // if mid points 1, it ok update mid
      mid++;
    }
    else
    { // mid points to two hence swap to high and decrement high
      // donot increment mid
      swap(nums[high], nums[mid]);
      high--;
    }
  }
}

// Time Complexity : O(N)
// Space Complexity :O(1)