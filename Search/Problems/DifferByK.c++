// Searching in an array where adjacent differ by at most k

// Normal Binary Search with adjacent element can differ by atmost K.
int search(int arr[], int n, int x, int k)
{
  int i = 0;
  while (i < n)
  {
    if (arr[i] == x)
      return i;
    // we increment the pointer by either 1, or steps calculated from the difference.
    i = i + max(1, abs((x - arr[i]) / k));
  }
  return -1;
}

/*
LINK:::
--------
 https://practice.geeksforgeeks.org/problems/searching-in-an-array-where-adjacent-differ-by-at-most-k0456/1

 */