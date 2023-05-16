#include <iostream>
using namespace std;

void printFields(char **p);
void convertID(int pos, char **p, char player);
bool checkVictory(char **p, char player);

int main()
{
   char **field = new char*[3];
   for (int i = 0; i < 3; i++)
   {
      field[i] = new char[3];
   }

   char **p; 
   p = field;

   int counter = 1;
   bool ongoing = true;

   while (counter < 10 && ongoing == true)
   {
      cout << "The fields with the following field ID numbers are still free \n";
      printFields(p);// function call that uses **p to find and print the free fields

      int idPos; 
      char playerChar;

      if (counter % 2 == 0)
      {
         playerChar = 'b';

         cout << "Black choose empty field! ";
         cin >> idPos; // input number from player

         while (idPos < 1 || idPos > 9) 
         {
            cout << "Invalid input! Choose integer between 1 and 9 \n";
            cin >> idPos;
         }
         
         // function call that converts integer ID into 2-D pointer postion 
         convertID(idPos, p, playerChar);
         // using pointer, write 'b' into position

         // function call using pointer to check whether latest placement of 'b' is victory
         bool result = checkVictory(p, playerChar);
      
         if (result)
         {
            cout << "Victory for Black! \n";
            ongoing = false;
            printFields(p);
         }
      }
      else if (counter % 2 != 0)
      {
         playerChar = 'w';
         
         cout << "White choose empty field! ";
         cin >> idPos; // input number from player
         
         while (idPos < 1 || idPos > 9) 
         {
            cout << "Invalid input! choose integer between 1 and 9. \n";
            cin >> idPos;
         }

         // function call that converts integer ID into 2-D pointer postion 
         convertID(idPos, p, playerChar);
         // using pointer, write 'w' into position

         // function call using pointer to check whether latest placement of 'w' is victory
         bool result = checkVictory(p, playerChar);
      
         if (result)
         {
            cout << "Victory for White! \n";
            ongoing = false;
            printFields(p);
         }    
      }
   
      counter++;
   }
   
   cout << "The game has ended \n";

   for (int i = 0; i < 3; i++) 
   {
      delete[] p[i]; // free up memory;
   }
   delete[] p;

   return 0;
}

//function to find and print free fields using **p
void printFields(char **p)
{
   // go through array and if it does not have b/w, print
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         if (*(*(p + i) + j) != 'b' && *(*(p + i) + j) != 'w')
         {
            int x = i * 3 + j; // converts 2-D position to integer position
            cout << x + 1 << " | ";         
         }
         else
         {
            cout << *(*(p + i) + j) << " | ";
         }
      }
      cout << endl;
   }
}

// function that converts integer ID to 2-D postion and writes in that position
void convertID(int pos, char **p, char player)
{
   int row = (pos - 1) / 3;
   int col = (pos - 1) % 3;

   while (pos > 9 || pos < 1 || *(*(p + row) + col) == 'b' || *(*(p + row) + col) == 'w') // keep asking for input until user enters a valid ID
   {
      cout << "ID already in use or out of bounds of playing field. DO NOT TRY TO CHEAT, please choose another ID: ";
      cin >> pos;
      row = (pos - 1) / 3;
      col = (pos - 1) % 3; 
   }
   
   if (player == 'b')
   {
      *(*(p + row) + col) = 'b';
   }
   else if (player == 'w')
   {
      *(*(p + row) + col) = 'w';
   }
}

// function that uses pointer to test for victory
bool checkVictory(char **p, char player)
{
   for (int i = 0; i < 3; i++) // Check rows
   {
      if (p[i][0] == player && p[i][1] == player && p[i][2] == player)
      {  
         return true;
      }
      if (p[0][i] == player && p[1][i] == player && p[2][i] == player)
      {
         return true;
      }   
   }

   if (p[0][0] == player && p[1][1] == player && p[2][2] == player) // Check diagonal
   {
      return true;
   } 
   if (p[0][2] == player && p[1][1] == player && p[2][0] == player) // Check diagonal
   {
      return true;
   }
    
   // No victory found
   return false;
}