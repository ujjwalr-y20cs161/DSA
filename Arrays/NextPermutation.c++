/*
Problem: Next Permutation

Statement: A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).


LINK:: https://leetcode.com/problems/next-permutation/description/

Explanation : https://www.geeksforgeeks.org/next-permutation/,
              https://youtu.be/JDOXKqF60RQ

Companies:

Uber + Goldman Sachs + Adobe Interview Qs
*/
#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums)
{

  // find the index which is dipping point from back
  int p = -1;
  int n = nums.size();
  // now we find the first minimal point from back to swap it
  for (int i = n - 2; i >= 0; i--)
  {
    if (nums[i] < nums[i + 1])
    {
      p = i;
      break;
    }
  }
  // if p is -1, it means it's the biggest permutation
  // hence we take the smallest permutaion, by reversing it
  // return
  if (p == -1)
  {
    reverse(nums.begin(), nums.end());
    return;
  }
  // now we swap p with, number that is immediately greater than p
  for (int i = n - 1; i > p; i--)
  {
    if (nums[i] > nums[p])
    {
      swap(nums[i], nums[p]);
      break;
    }
  }
  // after swapping, we reverse sub arr after the position of swap
  // since everything is ascending order from back, to get the next
  // smallest change, we reverse it

  reverse(nums.begin() + p + 1, nums.end());
}

/*

Example :

arr ->  1 2 3 4 1 0

now we traverse from back

1 2 3 4 1 0
. . * . . . here at three we find minimal point from back 1<4 but 4 is not < 3

now we find the pivot point that is slightly greater than 3 from back:

1 2 3 4 1 0
. . * ^ . . here we swap 3,4

1 2 4 3 1 0
. . * . . . it's not the next permutaion, to get next perm, we reverse the sub array after the point of swap

1 2 4 0 1 3
. . * - - -

Here we have the next permutation
 */

int main()
{

  vector<int> arr = {1, 2, 3, 4, 1};

  nextPermutation(arr);

  for (auto i : arr)
    cout << i << " ";
  cout << "\n";
}