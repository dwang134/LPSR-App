/***********************************************************************
// OOP244 Workshop 2: read functions for foolproof integer and C string
//                    data entry
// File	utils.cpp
// Version 1.0
// Date	2019/09/15
// Author	Fardad Soleimanloo
// Description
// 
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
using namespace std;
#include "Utils.h"
namespace sdds {
   // reads an integer from console the integer referenced by "val"
   // argument.
   // if the user enters an invalid integer or values outside of the 
   // boundries set by "min" or "max" , this function flushes the 
   //keyboard, prints the "errorMessage and reads again
   // untill user enters an acceptable integer
   void validInt(int& val, int min, int max, const char* ErrorMess) {
      bool ok;
      char newline;
      do {
         cin >> val;
         newline = cin.get();
         if (cin.fail() || newline != '\n') {
            ok = false;
            cin.clear();
            cin.ignore(1000, '\n');
         }
         else {
            ok = val <= max && val >= min;
         }
      } while (!ok && cout <<ErrorMess);
   }
   // reads a C style string from console up to "len" characters into the
   // the string pointed by the "str" pointer
   // if the user enters more than "len" characters, this function
   // flushes the keyboard, prints the "errorMessage and reads again
   // untill user enters an acceptable string
   void validString(char* str, int len, const char* errorMessage) {
      bool ok;
      do {
         ok = true;
         cin.getline(str, len+1, '\n');
         if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            ok = false;
         }
      }while(!ok && cout << errorMessage);
   }

   //fool proof 
   //always clear buffer even if they type in junk 

// for ISBN
      void validISBN(long long int& val, long long int min, long long int max, const char* ErrorMess) {
      bool ok;
      char newline;
      do {
         cin >> val;
         newline = cin.get();
         if (cin.fail() || newline != '\n') {
            ok = false;
            cin.clear();
            cin.ignore(1000, '\n');
         }
         else {
            ok = val <= max && val >= min;
         }
      } while (!ok && cout <<ErrorMess);
   }

   //for memberID!!!
      void validID(unsigned long int& val, unsigned long int min, unsigned long int max, const char* ErrorMess) {
      bool ok;
      char newline;
      do {
         cin >> val;
         newline = cin.get();
         if (cin.fail() || newline != '\n') {
            ok = false;
            cin.clear();
            cin.ignore(1000, '\n');
         }
         else {
            ok = val <= max && val >= min;
         }
      } while (!ok && cout <<ErrorMess);
   }



}