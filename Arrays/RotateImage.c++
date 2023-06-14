/*
Problem: Rotate Image : Rotate Matrix

Statement:
=>	Given a matrix, your task is to rotate the matrix 90 degrees clockwise.

LINK::https://leetcode.com/problems/rotate-image/

Companies:
Walmart
Bloomberg
Oracle
Flipkart
Samsung
Amazon
Facebook
CRED
Meesho
Swiggy
Dream11
InMobi
*/
#include <bits/stdc++.h>
#define endd
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
  // main Idea : to rotate a matrix by 90 degrees, first transpose the matrix
  // and reverse the rows.

  int n = matrix.size();

  // in-place transposing
  // 1 2 3        1 4 7
  // 4 5 6   ==>  2 5 8
  // 7 8 9        3 6 9

  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      swap(matrix[i][j], matrix[j][i]);
    }
  }

  // Reverse the matrix:
  //  1 4 7       7 4 1
  //  2 5 8  ==>  8 5 2
  //  3 6 9       9 6 3
  // inplace reversal.
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n / 2; j++)
    {
      swap(matrix[i][j], matrix[i][n - j - 1]);
    }
  }
}

// Time Complexity : O(n^2)+O(n^2)
// Space Complexity :O(1)