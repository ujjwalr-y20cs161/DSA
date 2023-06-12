/*
Problem:Stock Buy And Sell

Statement:
=>You are given an array of prices where prices[i] is the price of a given stock on an ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

LINK:: https://leetcode.com/problems/best-time-to-buy-and-sell-stock

Companies:

Oracle
Walmart
Google
Adobe
Samsung
Microsoft
Flipkart
Netflix
Facebook
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

int maxProfit(vector<int> &prices)
{
  // init profit
  int profit = 0;

  int n = prices.size();

  // min values and maxProfit
  int min = INT_MAX, maxProfit = 0;
  for (int i = 0; i < n; i++)
  {

    // note down min
    if (prices[i] < min)
    {
      min = prices[i];
    }

    // after having min calcute profit on that time
    maxProfit = prices[i] - min;

    // if profit on that time exceeds past profit, store it as profit
    if (profit < maxProfit)
    {
      profit = maxProfit;
    }
  }
  // return the profit
  return profit;
}
int main()
{
}

// Time Complexity : O(N)
// Space Complexity :O(1)