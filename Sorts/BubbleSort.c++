#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

void BubbleSort(int a[], int n)
{

  // Outer loop will run for n-1 times
  for (int i = 0; i < n - 1; i++)
  {
    // Inner loop will run for n-1 * n-i-1 times
    for (int j = 0; j < n - i - 1; j++)
    {

      if (a[j] > a[j + 1])
        swap(a[j], a[j + 1]);
    }
  }
}

int main()
{

  int a[] = {10, 20, -10, 4, 2, 200};
  int n = sizeof(a) / sizeof(a[0]);

  for (auto i : a)
    cout << i << " ";
  cout << endl;

  BubbleSort(a, n);

  for (auto i : a)
    cout << i << " ";
  cout << endl;
}
