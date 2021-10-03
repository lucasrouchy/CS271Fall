#include <stdio.h>
/* Ex.1: Return the larger value */
int max(int x, int y)
{
  if (x >= y) {
       return(x);
   } else if (y > x) {
       return(y);
   }

   return x;
}

/* Ex.2: Add [0..100] and return the sum */
int add100(void)
{
    int i = 100;
    int sum = 0;
    sum += i;

  return(sum);
}

/* Ex.3: Sum the elements in the array */
int sum(int arr[], int n)
{
  int sum = 0;

  for (int i =0; i< n; i++)
  sum += arr[i];
  return sum;
}

/* Ex.4: Find the largest element in the array */
int largest(int arr[], int n)
{
  int i;
  int max = arr[0];
  for (i =1; i<n; i++)
    if (arr[i] > max) {
      max =arr[i];
    }
  return max;
}

/* Provided */
int main() {
   // Exercise 1
   printf("Sum of 1..100 is %d\n", add100());

   // Exercise 2
   printf("The max of 12 and 20 is %d\n", max(12, 20));
   printf("The max of 37 and 14 is %d\n", max(37, 14));

   // Create an array and calculate its length n
   int arr[] = {12, 5, 7, 14, 8};
   int n = sizeof(arr) / sizeof(arr[0]);

   // Exercise 3
   printf("Sum of the array is %d\n", sum(arr, n));

   // Exercise 4
   printf("Largest element in the array is %d\n", largest(arr, n));

   return 0;
}
