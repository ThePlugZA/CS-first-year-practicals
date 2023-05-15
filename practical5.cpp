#include <iostream>
#include <string>
using namespace std;

bool my_EXOR_implementation(bool input1, bool input2);
bool my_NAND_implementation(bool input1, bool input2);

int main()
{
   bool b1;
   bool b2;

   cout << "Enter truth-value (1/0): \n";
   cin >> b1;
   cout << "Enter truth-value (1/0): \n";
   cin >> b2;

   bool answer = my_EXOR_implementation(b1, b2);

   if (answer)
   {
      cout << answer << " true\n" ;
   }
   else
   {
     cout << answer << " false\n" ;
   }

   return 0;
}

bool my_EXOR_implementation(bool input1, bool input2)
{
   bool val1 = my_NAND_implementation(input1, input2);
   bool val2 = my_NAND_implementation(val1, input1);
   bool val3 = my_NAND_implementation(val1, input2);
   bool result = my_NAND_implementation(val2, val3);

   return result;
}

bool my_NAND_implementation(bool input1, bool input2)
{
   if (input1)
   {
      if (input2)
      {
         return false;
      }
      else
      {
         return true;
      }
   }
   else
   {
      return true;
   }
}