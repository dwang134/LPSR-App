/***********************************************************************
// OOP244 Workshop 2: read functions for foolproof integer and C string
//                    data entry
// File	utils.h
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

//Name: Dylan Wang
//Course: OOP244NEF
//StudentNum:  114099187
//Date: 12/02/2019
//File name: Utils.h
//MODIFIED!!!!!!!!!!!!!!!!!!!!!!!!!
#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
namespace sdds {
   // reads an integer from console the integer referenced by "val"
   // argument.
   // if the user enters an invalid integer or values outside of the 
   // boundries set by "min" or "max" , this function flushes the 
   //keyboard, prints the "errorMessage and reads again
   // untill user enters an acceptable integer
   
   void validInt(int& val, int min, int max , const char* errorMessage = "");

   //for ISBN long long int!
    void validISBN(long long int& val, long long int min, long long int max , const char* errorMessage = "");

   //for MEMBER ID LONG INT!!
   void validID(unsigned long int& val, unsigned long int min, unsigned long int max , const char* errorMessage = "");


   // reads a C style string from console up to "len" characters into the
  // the string pointed by the "str" pointer
  // if the user enters more than "len" characters, this function
  // flushes the keyboard, prints the "errorMessage and reads again
  // untill user enters an acceptable string
   
   void validString(char* str, int len, const char* errorMessage = "");
}
#endif // !