//Name: Dylan Wang
//Course: OOP244NEF
//StudentNum:  114099187
//Date: 12/02/2019
//File name: Book.h

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include "Date.h"
#include "PubRecord.h"

namespace sdds{

  const long long MIN_ISBN_VALUE= 1000000000000;
  const long long MAX_ISBN_VALUE= 9999999999999;

  class Book: public PubRecord{

    unsigned long long m_ISBN; //13 int length
    unsigned long int m_memberID;

  public:

    Date date;

    //Date today;
    Date currentDate;

    Book();

    Book(const Book & other);

    Book& operator=(const Book& other);

    char recID()const; 

    int memberId() const;

    void checkIn(); 
    
    void checkOut();

    std::istream& read(std::istream& is= std::cin);

    std::ostream& write(std::ostream& os= std::cout) const;

  };







}
#endif