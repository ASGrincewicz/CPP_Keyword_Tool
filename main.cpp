#include <iostream>
#include "KeywordPicker.h"
using namespace std;


int main()
{
   int option;
   KeywordPicker* keywordPicker;
   while(true)
   {
       keywordPicker = new KeywordPicker();
       cout << "---------------------------------\n";
       cout << "1. Pick Random Keywords" << "\n";
       cout << "2. Save to File" << "\n";
       cout << "3. Get Total Combinations" << "\n";
       cout << "4. Exit" << "\n";
       cout << "Enter your option: " << endl;
       cin >> option;


       try
       {
           switch(option)
           {
               case 1:
                   keywordPicker->pickRandomKeywords();
                   break;
               case 2:
               {
                   auto keywords_to_save = keywordPicker->Get_Keywords();
                   keywordPicker->sortAndSaveToFile(keywords_to_save);
                   break;
               }
               case 3:
                   cout << "The Total number of possible keyword combinations is : "<< keywordPicker->total_combinations(24) << endl;
                   break;
               case 4:
                   delete keywordPicker;
                   exit(0);
               default:
                   cout << "Invalid option." << endl;
           }
       }
       catch(exception& e)
       {
           cout << "An error occurred: " << e.what() << endl;
       }

       delete keywordPicker;
   }

}