/*

Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.

LINK:: https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1

COMPANY ::
----------
Flipkart
Accolite
Amazon
Microsoft
D-E-Shaw
Google
Nagarro
Atlassian
 */

class Solution
{
public:
  int majorityElement(int arr[], int size)
  {
    unordered_map<int, int> map;
    for (int i = 0; i < size; i++)
    {
      if (map.find(arr[i]) == map.end())
      {
        map[arr[i]] = 1;
      }
      else
      {
        map[arr[i]]++;
      }
      if (map[arr[i]] > size / 2)
        return arr[i];
    }
    // your code here
    return -1;
  }
};