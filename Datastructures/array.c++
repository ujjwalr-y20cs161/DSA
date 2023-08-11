#include <iostream>
using namespace std;

int main()
{

  int arr[] = {10, 20, 30, 40};
  int *arr2 = arr;
  int arr3[2][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};

  for (auto i : arr)
  {
    cout << i << " ";
  }
  cout << endl;

  for (int i = 0; i < 4; i++)
  {
    cout << *(arr2 + i) << "-" << arr2[i] << " ";
  }
  cout << endl;

  for (auto i : arr3)
  {
    cout << endl;
    // for (auto j : i)
    // {
    // }
    for (int j = 0; j < 5; j++)
    {
      cout << i[j] << " ";
    }
  }
}