/*
Problem: Pascals triangle

Statement:  Pascal's Triangle

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above

LINK:: https://leetcode.com/problems/pascals-triangle/description/

Companies:

Amazon
Microsoft
Adobe


*/

//  ### Method 1
class Solution
{
public:
  vector<vector<int>> generate(int numRows)
  {
    vector<vector<int>> Triangle;
    // First row is manually inserted.
    Triangle.push_back({1});

    // Traverse numRows-1 times, as already first row is generated.
    for (int i = 1; i < numRows; i++)
    {
      vector<int> tri;
      // Generate the values by iterating, ith row contains i+1 elements,
      // hence j =   [0 -> i] which are i+1 elements.
      for (int j = 0; j <= i; j++)
      {
        if (j == 0 || j == i)
        {
          tri.push_back(1);
        }
        else
        {
          // current ele = previous row previous ele +previous row current ele
          tri.push_back(Triangle[i - 1][j - 1] + Triangle[i - 1][j]);
        }
      }
      // insert into vector
      Triangle.push_back(tri);
    }
    return Triangle;
  }
};

//  ### Method 2: By using Formula
//  [This method is inefficent to caluculate and print whole Triangle]
// use only when asked to print a particular element or particular row
/*
Formula is  C(r, c) = C(r-1, c-1) + C(r-1, c)

where C is the Combination = nCr
 */

int nCr(int n, int r)
/*

nCr = n!/(n-r)! * r!

 */
{
  if (r > n)
  {
    return 0; // Invalid input, r should be less than or equal to n
  }

  int numerator = factorial(n);
  int denominator = factorial(r) * factorial(n - r);

  int result = numerator / denominator;
  return result;
}

vector<vector<int>> generate(int numRows)
{
  vector<vector<int>> Triangle;

  for (int i = 1; i <= numRows; i++)
  {
    vector<int> temp;

    for (int j = 1; j <= i; j++)
    {
      temp.push_back(nCr(i - 1, j - 1));
    }
    Triangle.push_back(temp);
  }
  return Triangle;
}