#include <iostream>
using namespace std;

int globalArray[S]; // The actual size S will be entered by the Tutor !
                    // The actual values in the array will also be initialized by the Tutor !
void my_own_Quicksort_Version(char direction, int lo, int hi)
{
   if (direction == '<')
   {
      // Insert here: Your code for quick-sorting from smallest to largest
      if (lo >= hi || lo < 0 || hi >= S || globalArray == NULL) // base cases
      {
         return;
      }

      int pivot = globalArray[hi]; // pivot last element
      int i = lo - 1;              // temp pivot index, becomes index of last element smaller than pivot
      int temp;                                                

      // partition section
      int j = lo;
      while (j < hi)
      {
         if (globalArray[j] <= pivot) // find element smaller than pivot, swap with [i++]
         {
            i++;
            temp = globalArray[i];
            globalArray[i] = globalArray[j]; // swap current element with temp pivot
            globalArray[j] = temp;           // swaps elements to the left of pivot
         }
         j++;
      }

      // pivot swapped here so it does not move to left side of array
      i++;
      temp = globalArray[i];
      globalArray[i] = globalArray[hi]; // actual pivot swapped, to remain in correct plave for partition
      globalArray[hi] = temp;

      // using pivot index i
      my_own_Quicksort_Version(direction, lo, i - 1); // left side of pivot
      my_own_Quicksort_Version(direction, i + 1, hi); // right side of pivot
   }
   else if (direction == '>')
   {
      // Insert here: Your code for quick-sorting from largest to smallest
      if (lo >= hi || lo < 0 || hi >= S || globalArray == NULL) // base caseS
      {
         return;
      }

      int pivot = globalArray[hi]; // pivot last element
      int i = lo - 1;              // temp pivot index
      int temp;

      int j = lo;
      while (j < hi)
      {
         if (globalArray[j] > pivot) // find value bigger than pivot, and swap so that it is on the correct side
         {
            i++;
            temp = globalArray[i];
            globalArray[i] = globalArray[j]; // swap current element with temp pivot
            globalArray[j] = temp;
         }
         j++;
      }

      i++;
      temp = globalArray[i];
      globalArray[i] = globalArray[hi]; // pivot swapped here so it remains in the correct position
      globalArray[hi] = temp;           // where all values bigger than pivot on the left and smaller on the right

      my_own_Quicksort_Version(direction, lo, i - 1); // left side of pivot
      my_own_Quicksort_Version(direction, i + 1, hi); // right side of pivot
   }
   else
      cout << " error ";
};

int main()
{
   // Tutor will insert code here to initialize the global array !
   
   int l;  // Tutor will give the initial value to this variable !
   int h;  // Tutor will give the initial value to this variable !
   char d; // Tutor will give the initial value to this variable !

   // Tutor will make this Test-Call to your own function of above:
   my_own_Quicksort_Version(d, l, h);

   // Tutor will use this code to inspect the final global array,
   // whereby Tutor will also replace size S by a proper number:
   int c = 0;
   while (c < S)
   {
      cout << globalArray[c];
      c++;
   }

   return 0;
}