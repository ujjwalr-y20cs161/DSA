/*
Problem: Find the repeating and missing numbers

Statement:
=>	 You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

LINK::https://www.interviewbit.com/problems/repeat-and-missing-number-array/

Companies:

Flipkart
Microsoft
Google
Tekion-corp
Netflix
Oracle
CRED
Meesho
Swiggy
Dream11
InMobi

*/
#include <bits/stdc++.h>
#define endd
using namespace std;

vector<int> repeatedNumber(const vector<int> &A)
{

  // sum of first n natural numbers = n*(n+1)/2

  // if we are able to calculate the sum of the array and the sum of the first n natural numbers, we will get the difference of missing number and repeating number.-->a

  // sum of squares of first n natural numbers = n*(n+1)*(2*n+1)/6

  // if we are able to calculate the sum of the squares of the array and the sum of the squares of the first n natural numbers, and divide with difference from above, we will get the sum of missing number and repeating number.-->b

  // we have both sum and difference of missing number and repeating number, so we can find both of them.
  // x = (a+b)/2, y = (b-a)/2

  int n = A.size();

  //  long long is taken because the sum of squares of first n natural numbers can be very large.
  long long sumCal = 0;
  long long sqrCal = 0;
  long long sum = (n * (n + 1)) / 2;
  long long sqr = (n * (n + 1) * (2 * n + 1)) / 6;

  // unordered_set is used to store the numbers in the array, so that we can find the repeating number. if possible.
  // this is another version :
  unordered_set<int> numSet;

  for (int i : A)
  {
    sumCal += i;
    sqrCal += (long long)i * i;

    if (numSet.count(i))
    {
      return {i, (int)(sum + i - sumCal)};
    }
    numSet.insert(i);
  }

  long long a = sum - sumCal;
  long long b = (sqr - sqrCal) / a;
  long long X = (a + b) / 2;
  long long Y = abs(a - b) / 2;

  return {(int)Y, (int)X};
}

// complexity: O(n) time and O(n) space
