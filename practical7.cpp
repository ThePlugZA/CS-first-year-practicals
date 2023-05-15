#include <iostream>
using namespace std;

void recur_F(int &val, char oper, int argu)
{
   int a0;
   int a1;
   int a2;
   
   if (!(val < 3))
   {
      return;
   }
   else
   {
      if (oper == '+')
      {
         switch (val)
         {
         case 0:
            a0 = val + argu;
            break;
         case 1:
            a1 = val + argu;
            break;
         case 2:
            a2 = val + argu;
            break;
         default:
            break;
         }
      }
      else
      {
         if (oper == '*')
         {
            switch (val)
            {
            case 0:
               a0 = val * argu;
               break;
            case 1:
               a1 = val * argu;
               break;
            case 2:
               a2 = val * argu;
               break;
            default:
               break;
            }
         } // else do nothing
      }
      
      switch (val)
      {
      case 0:
         cout << a0 << "|";
         break;
      case 1:
         cout << a1 << "|";
         break;
      case 2:
         cout << a2 << "|";
         break;
      default:
         break;
      }

      val = val + 1;
      recur_F(val, oper, argu);
   }
}

int main()
{
   int i = 0;
   char op; // operator
   int arg; // argument value to multiple or add by

   cin >> op;
   cin >> arg;

   recur_F(i, op, arg);
   return 0;
}