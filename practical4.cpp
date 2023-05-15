#include <iostream>
using namespace std;

/*
apply laws of programming to transform program into equivalent program
Only use one while loop,
No FOR statement
*/

int main()
{
   int x;
   int y;
   cin >> x;
   bool stop = true;

   while (x >= 0) // as long as x is non-negative, run loop
   {
      if (stop)
      {
         cout << " Blue| ";
         if ((x % 2) == 0) // if x is an even number,
         {
            y = x / 2; // y is half of x
         }
         else
         {
            y = (3 * x) + 1; // value of y
         }
      }   
      
      if (y > x) //y is bigger than x
      {
         stop = false;
         cout << " Yellow| ";
         y = y-1; //make y odd/even
      }
      else
      {
         stop = true;
      }

      if (stop)
      {
         cout << " Green| "; // print this while x is non-negative
         if ((x % 2) == 0) // if x is an even number, update the value of x
         {
            x = x - 1;
         }
         else
         {
            x = x -3; 
         }
      }
   }
      cout << " Red| "; // print this at the end

   return 0;
}
