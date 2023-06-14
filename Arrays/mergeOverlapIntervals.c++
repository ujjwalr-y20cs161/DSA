/*
Problem: Merge Overlapping Intervals

Statement:

=> Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

LINK:: https://leetcode.com/problems/merge-intervals/

Companies:

Netflix
Walmart
Bloomberg
Facebook
Samsung
Oracle
Amazon
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

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
  // empty new vector of intervals
  vector<vector<int>> res;
  int n = intervals.size();

  // sort the intervals
  sort(intervals.begin(), intervals.end());

  // take a temp interval to process the first one
  vector<int> temp = intervals[0];

  // start from 2nd interval because we are comparing the current
  // intervals with previous interval
  for (int i = 1; i < n; i++)
  {
    // if 2nd element of previous is greater than 1st element
    //  of current interval.
    if (temp[1] >= intervals[i][0])
    {
      // merge the intervals
      temp[1] = max(temp[1], intervals[i][1]);
    }
    else
    {
      // if not push previous into list
      res.push_back(temp);
      // assign the current interval to temp to process the next interval
      temp = intervals[i];
    }
  }
  // push the last interval
  res.push_back(temp);

  return res;
}
