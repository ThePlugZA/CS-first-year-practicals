#include <iostream>
#include <string>
using namespace std;

/*
   if budget is enough for topping
      ask if user wants topping
         update budget and invoice
         <iomanip>
*/

int main()
{
   const double basePizza = 40;
   const double olives = 15.50;
   const double onions = 11;
   const double cheese = 12.30;
   const double salami = 22;
   const double shrimps = 25.40;

   double budget = 100;
   double invoice = 0;

   cout << "WELCOME TO ANTONIO'S PIZZERIA ITALIANA." << endl;
   
   budget -= basePizza;
   invoice += basePizza;
   string answer;

   if (budget >= olives)
   {
      cout << "ANY OLIVES? (Y/N)" << endl;
      cin >> answer;
      if (answer == "Y") 
      {
         budget -= olives;
         invoice += olives;
      }
   }

   if (budget >= onions)
   {
      cout << "ANY ONIONS? (Y/N)" << endl;
      cin >> answer;
      if (answer == "Y")
      {
         budget -= onions;
         invoice += onions;
      } 
   }

   if (budget >= cheese)
   {
      cout << "ANY CHEESE (Y/N)" << endl;
      cin >> answer;
      if (answer == "Y")
      {
         budget -= cheese;
         invoice += cheese;
      }
   }

   if (budget >= salami)
   {
      cout << "ANY SALAMI (Y/N)" << endl;
      cin >> answer;
      if (answer == "Y")
      {
         budget -= salami;
         invoice += salami;
      }
   }
       
   if (budget >= shrimps) 
   {
      cout << "ANY SHRIMPS (Y/N)" << endl;
      cin >> answer;
      if (answer == "Y") 
      {
         budget -= shrimps;
         invoice += shrimps;
      }
   }

   cout << "ALTHOGETHER THAT WILL BE: R" << invoice << endl;
   if (invoice >= 99) 
   { 
      cout << "HERE IS ALSO A FREE COOLDRINK FOR YOU" << endl;
   }
   else 
   {
      cout << "ENJOY YOUT PIZZA" << endl;
   }

   cout << "HERE IS YOUR CHANGE MONEY: R" << budget << endl;

return 0;
}