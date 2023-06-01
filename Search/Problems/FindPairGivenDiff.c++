bool findPair(int arr[], int size, int n)
{

  // this is one way to solve but is not efficient takes overall of O(nlogn)X2

  // sort(arr,arr+size);                                         //--> O(nlogn)
  // for(int i = 0;i<size;i++){
  //     if(binary_search(arr,arr+size,n+i)) return true;
  // }                                                            //--> n*logn
  // return false;
  // ------------------------------------------------------------------------------  // Method 2 : More efficent, use 2 pointers approach             O(nlogn)
  sort(arr, arr + size); //--->nlogn
  int i = 0, j = 1;

  while (i < size and j < size) // ---> n or so
  {
    // check whether the difference == n
    if (i != j and abs(arr[i] - arr[j]) == n)
    {
      return true;
    }
    // if not, increment either one of the pointer based on the condition
    else if (arr[j] - arr[i] < n)
      j++;
    else
      i++;
  }
  return false;
}

/* LINK::
   ======
   https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1

   */