#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

/*
||READ.ME||

Code enters an infinte loop when a character, or a string of characters is inputed. the only way to mitigate this is to add external functions, like typeid, cin.fail
*/

int main()
{
   const int SIZE = 5; // size of array
   float basePizzaPrice;
   float olivesPrice;
   float onionsPrice;
   float salamiPrice;
   float shrimpsPrice;

   float normalDay[SIZE] = {basePizzaPrice, olivesPrice, onionsPrice, salamiPrice, shrimpsPrice};
   float midWeek[SIZE] =  {basePizzaPrice, olivesPrice, onionsPrice, salamiPrice, shrimpsPrice};
   float loyaltyCard[SIZE] =  {basePizzaPrice, olivesPrice, onionsPrice, salamiPrice, shrimpsPrice};
   float *p = NULL;

   for (int counter = 0; counter < SIZE; counter++)
   {
      float price;
      cout << "Enter price for #" << counter + 1 << ": ";
      cin >> price;

      while (price <= 0 || isalpha(price)) // input price > 0
      {
         cout << "Invalid price input, price must be positive & none zero, try again \n";
         cin >> price;
      }
      
      // re-direct pointer to p+counter of normalday -> store price
      p = normalDay;
      *(p + counter) = price;


      float midWeekFactor;
      cout << "Enter Midweek factor for #" << counter + 1 << ": ";
      cin >> midWeekFactor;

      while (midWeekFactor <= 0 || midWeekFactor >= 1)// input 0 < midweekfactor < 1
      {
         cout << "Invalid input for midweek factor, must be 0 < midweekfactor < 0, try again \n";
         cin >> midWeekFactor;
      }

      // re-direct pointer to p+counter of midweek -> store price*midweekfactor
      p = midWeek;
      *(p + counter) = price * midWeekFactor;


      float loyaltyFactor;
      cout << "Enter loyalty factor for #" << counter + 1 << ": ";
      cin >> loyaltyFactor;
      
      while (loyaltyFactor <= 0 || loyaltyFactor >= midWeekFactor)// input 0 < loyalty factor < midweekfactor
      {
         cout << "Invalid input for loyalty factor, must be 0 < loyalty factor < " << midWeekFactor << " ,try again \n";
         cin >> loyaltyFactor;
      }

      // re-direct pointer to p+counter of loyaltycard -> store price*loyaltyfactor
      p = loyaltyCard;
      *(p + counter) = price * loyaltyFactor;
   }

   // Prints out the normalday, midweek, and loyalty card values
   cout << "Normal day Value: \n";
   for (int i = 0; i < SIZE; i++)
   {
      cout << "#" << i + 1 << " is $" << normalDay[i] << "; ";
   }
   cout << endl;

   cout << "Midweek value: \n";
   for (int i = 0; i < SIZE; i++)
   {
      cout << "#" << i + 1 << " is $" << midWeek[i] << "; ";
   }
   cout << endl;

   cout << "Loyalty card value: \n";
   for (int i = 0; i < SIZE; i++)
   {
      cout << "#" << i + 1 << " is $" << loyaltyCard[i] << "; ";
   } 
   cout << endl;
   return 0;
}