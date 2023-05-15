#include <iostream>
#include <string>
#include <array>
using namespace std;

int main()
{
   const double large_Rectangular_Base_Pizza = 60;
   const double small_Round_Base_Pizza = 40;
   const double additional_olives = 15.50;
   const double additional_onions = 11;
   const double additional_cheese = 12.30;
   const double additional_salami = 22;
   const double additional_shrimps = 25.40;

   double invoice = 0;

   int smallPizza = 0;
   int largePizza = 0;
   int olives = 0;
   int onions = 0;
   int cheese = 0;
   int salami = 0;
   int shrimps = 0;
   const int SIZE = 7;
   int array[SIZE] = {smallPizza, largePizza, olives, onions, cheese, salami, shrimps};

   string answer;
   cout << "Group-Pizza was chosen?" << endl;
   cin >> answer;
   if (answer == "yes")
   {
      array[1]++;
   }
   else 
   {
      array[0]++;
   }

   char topping;
   for (int i = 0; i < 10; i++)
   {
      cout << "Select additional topping" <<endl;
      cin >> topping;
      switch (topping)
      {
      case 'a':
         array[2]++;
         break;
      case 'b':
         array[3]++;
         break;
      case 'c':
         array[4]++;
         break;
      case 'd':
         array[5]++;
         break;
      case 'e':
         array[6]++;
         break;
      default:
         //intentionally left empty
         break;
      }
   }

   cout << "here is your detailed invoice:" <<endl;

   double small_pizza;
   double large_pizza;
   double olive_toppings;
   double salami_toppings;
   double onion_toppings;
   double cheese_toppings;
   double shrimps_toppings;

   for (int count = 0; count < SIZE; count++)
   {
      if (count == 0 && array[count] > 0)
      {
         cout << "1-Person Base-Pizza: "<< array[count] <<endl;
         small_pizza = array[count] * small_Round_Base_Pizza;
         cout << "Sub total: R" << small_pizza <<endl;
      }
      if (count == 1 && array[count] > 0)
      {
         cout << "Group-Large Base-Pizza: "<< array[count] <<endl;
         large_pizza = array[count] * large_Rectangular_Base_Pizza;
         cout << "Sub total: R" << large_pizza <<endl;
      }
      if (count == 2 && array[count] > 0)
      {
         cout << "Olive toppings: "<< array[count] <<endl;
         olive_toppings = array[count] * additional_olives;
         cout << "Sub total: R" << olive_toppings <<endl;
      }
      if (count == 3 && array[count] > 0)
      {
         cout << "Onion toppings: "<< array[count] <<endl;
         onion_toppings = array[count] * additional_onions;
         cout << "Sub total: R" << onion_toppings <<endl;
      }
      if (count == 4 && array[count] > 0)
      {
         cout << "Cheese toppings: "<< array[count] <<endl;
         cheese_toppings = array[count] * additional_cheese;
         cout << "Sub total: R" << cheese_toppings <<endl;
      }
      if (count == 5 && array[count] > 0)
      {
         cout << "Salami toppings: "<< array[count] <<endl;
         salami_toppings = array[count] * additional_salami;
         cout << "Sub total: R" << salami_toppings <<endl;
      }
      if (count == 6 && array[count] > 0)
      {
         cout << "Shrimps toppings: "<< array[count] <<endl;
         shrimps_toppings = array[count] * additional_shrimps;
         cout << "Sub total: R" << shrimps_toppings <<endl;
      }
   }
   double total_sum_price = small_pizza + large_pizza + olive_toppings + onion_toppings + cheese_toppings + salami_toppings + shrimps_toppings;

   cout << "The Total Sum-Price is: R" << total_sum_price <<endl;
   
   return 0;
}