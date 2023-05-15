#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
   const float large_Rectangular_Base_Pizza = 60;
   const float additional_olives = 15.50;
   const float additional_onions = 11;
   const float additional_cheese = 12.30;
   const float additional_salami = 22;
   const float additional_shrimps = 25.40;

   float budget = 300;
   float invoice = 0;

   cout << "WELCOME GIRLS TO ANTONIO'S PIZZERIA ITALIANA." << endl;
   
   budget -= large_Rectangular_Base_Pizza;
   invoice += large_Rectangular_Base_Pizza;
   char answer;
   bool stop;
 
   do
   {
      cout << "any more toppings for you? " << endl;
      cin >> answer;

      switch (answer)
      {
      case 'n':
         stop = true;
         break;
      case 'a':
         if (budget >= additional_olives)
         {
            budget -= additional_olives;
            invoice += additional_olives;
            cout << "Current balance: R" << invoice << endl;
         }
         else 
         {
            cout << "We can't afford that any more!" << endl;
         }
         break;
      case 'b':
         if (budget >= additional_onions)
         {
            budget -= additional_onions;
            invoice += additional_onions;
            cout << "Current balance: R" << invoice << endl;
         }
         else 
         {
            cout << "We can't afford that any more!" << endl;
         }
         break;
      case 'c':
         if (budget >= additional_cheese)
         {
            budget -= additional_cheese;
            invoice += additional_cheese;
            cout << "Current balance: R" << invoice << endl;
         }
         else 
         {
            cout << "We can't afford that any more!" << endl;
         }
         break;
      case 'd':
         if (budget >= additional_salami)
         {
            budget -= additional_salami;
            invoice += additional_salami;
            cout << "Current balance: R" << invoice << endl;
         }
         else 
         {
            cout << "We can't afford that any more!" << endl;
         }
         break;
      case 'e':
         if (budget >= additional_shrimps)
         {
            budget -= additional_shrimps;
            invoice += additional_shrimps;
            cout << "Current balance: R" << invoice << endl;
         }
         else 
         {
            cout << "We can't afford that any more!" << endl;
         }
         break;
      }

   } while (budget >= additional_onions && stop == false);
   
   cout << "Altogether that will be" <<endl;
   cout << "R" << invoice << endl;

   if (invoice > 298)
   {
      cout << "Girls, also fetch yourself a free coffee at our Espresso bar!" <<endl;
   }
   else
   {
      cout << "Enjoy your pizza!" <<endl;
   }

   cout << "Here is your change money" << endl;
   cout << "R" << budget <<endl;

   return 0;
}