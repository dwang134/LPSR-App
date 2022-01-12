/***********************************************************************
// OOP244 Project Milestone 2 tester
//
// File: ms2tester.cpp
// Version 1.0
// Date	2019/11/18
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019/11/18      Initial Release
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "ReadWriteable.h"
using namespace std;
using namespace sdds;
class Message :public ReadWriteable {
   char m_data[81];
public:
   Message(const char* data="") {
      strcpy(m_data, data);
   }
   std::istream& read(std::istream& is = std::cin) {
      is.getline(m_data, 80, '\n');
      return is;
   }
   std::ostream& write(std::ostream& os = std::cout)const {
      return os << m_data;
   }
};

int main() {
   fstream ms2file("ms2.txt", ios::out);
   Message m1("This is a test message."), m2;
   cout << "The following two lines should match:" << endl << "1-This is a test message." << endl;
   cout << "2-" << m1 << endl;
   cout << "Enter \"Green Eggs and Ham\": ";
   cin >> m1;
   cout << "               You entered: " << m1 << endl;
   ms2file << m1 << endl;
   ms2file.close();
   ms2file.open("ms2.txt", ios::in);
   cout << "The following two lines should match,\nif they don't, it means your helper operator oveloads are not implemented correctly." << endl;
   ms2file >> m2;
   cout << "1-" << m2 << endl;
   cout << "2-" << "Green Eggs and Ham." << endl;
   return 0;
}
