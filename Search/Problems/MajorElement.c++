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
    // create a hashmap to store the frequency
    unordered_map<int, int> map;

    for (int i = 0; i < size; i++)
    {
      // check if element is present in map
      if (map.find(arr[i]) == map.end())
      {
        // if not then initialize that with 1
        map[arr[i]] = 1;
      }
      else
      {
        // if present increment.
        map[arr[i]]++;
      }
      // if frequency cross the given threshold then return the element
      if (map[arr[i]] > size / 2)
        return arr[i];
    }
    // no element crossed the threshold return -1
    return -1;
  }
};