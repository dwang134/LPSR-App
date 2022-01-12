#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Date.h"
#include "Magazine.h"
#include "PubRecord.h"
#include "Utils.h"

using namespace std;
#include "Book.h"

using namespace std;

namespace sdds{

  Book::Book(){
      // PubRecord();
      m_ISBN = 0;
      m_memberID = 0;
  }

  Book::Book(const Book& other) : PubRecord(other)
  {
    m_ISBN = other.m_ISBN;
    m_memberID = other.m_memberID;
  }

  Book& Book::operator=(const Book& other)
  {
    if (this != &other)
    {
      m_ISBN = other.m_ISBN;
      m_memberID = other.m_memberID;
      (PubRecord&)*this = other;
    }
    return *this;
  }

  char Book::recID() const
  {
    return 'B';
  }


  int Book::memberId() const{
    return m_memberID;
  }

  void Book::checkIn()
  {
    m_memberID= 0 ;
    cout << name() << " checked in!" << endl;
  }

  void Book::checkOut()
  {
    //didn't make set function instead just going to read into member variable 
    cout << "Entere Member id: ";
    validID(m_memberID, 10000, 99999, "Invalid Member ID, Enter again: ");

    cout << "Enter return date: ";
    cin >> date;
   
    while (!date)
    {
      cout << "Please enter a future date." << endl;
      cout << "Enter return date: ";
      cin >> date;
    }
    
    int daysBetween = date - currentDate;
    
    while (daysBetween > 30)
    {
      cout << "The return date must be earlier than 30 days away from today." << endl;
      cout << "Enter return date: ";
      cin >> date;
    }

  }

  std::istream& Book::read(std::istream& is)
  {
    char pubName[PUB_MAX]= "";
    long long int ISBN;
    int memberID;
    int shelfNum;
    if (mediaType() == SDDS_CONSOLE)
    {
      //first set the member id to 0 
      m_memberID= 0;

      if (name()== nullptr) //if name is empty 
      {
          //SDDS_CONSOLE

            cout << "Book Name: ";

          // is.getline(pubName, len+1, '\n');

          //allocate memory           

          // while (!(strlen(pubName) >= 1 && strlen(pubName) < 40))
          // {
          //   cout << "Magazine name too long, Enter again: ";
          //   is.getline(pubName, len+1, '\n');
          // }
            // is.clear();
            // is.ignore();
            validString(pubName, PUB_MAX, "Book name too long, Enter again: ");

          //dynamic membory needed
          name (pubName);
          
          // is.clear();
          // publicationName = pubName;
        }

        if (name()!= nullptr)
        {
          cout << "ISBN: ";

          validISBN(ISBN, MIN_ISBN_VALUE, MAX_ISBN_VALUE, "Invalid ISBN number,  Enter again: ");

          //set
          m_ISBN = ISBN;
        }

        if (name()!= nullptr){
          cout << "Shelf Number: ";
          readShelfNo();
        }
          is.clear();
          is.ignore(1000, '\n');
        
    }//CONSOLE


      // if (name()!= nullptr)
      // {
          else if (mediaType() == SDDS_FILE){
            // char ch;
            
            // pubName needs to follow the same strategy as Magazine with getline
            // memberId needs to be checkced for after recieving values from file
            // if (memberId()!= 0){                             
            is.getline(pubName, PUB_MAX, '\t') >> ISBN;
            is.ignore();
            is >> shelfNum;
            is.ignore();
            is >> memberID;
            //  >> ch >> date;             
              // cin >> pubName>> ch >> ISBN >> ch >> shelfNum >> ch >> memberID >> ch >> date >> ch;

            // }else{ example for record with 0 for member ID
            //   cin >> pubName>> ch >> ISBN >> ch >> shelfNum >> ch >> memberID >> ch;
            // }

            // memberId conditional
            if (memberID == 0){
              is.ignore();
            }
            else{
                is.ignore();
                is >> date;
            }
            is.ignore();
    

            // if it fails 
            // if (is.fail()) {
            //     is.clear();
            //     is.ignore(1000, '\n');
            // }
            // else{
                name(pubName);
                m_ISBN= ISBN; 
                shelfNo(shelfNum);
                m_memberID= memberID;
            // }

            // //clear bufffffffFFferrrRRr
            // is.clear();
            // is.ignore(1000, '\n');
            // is.ignore();
            // return is;
          }
          // else{
          //   cout << "Shelf Number: ";
          //   readShelfNo();  
          // }


        // }// nullptr


        return is;
      }//if CONSOLE



  //   is.ignore(1000, '\n');
  //   return is;
  // }

  std::ostream& Book::write(std::ostream& os) const
  {
    if (mediaType() == SDDS_CONSOLE)
    {
        os << std::setw(41) << std::left << name();
        os << m_ISBN;
        os << std::setfill(' ') << std::setw(2) << ' ';
        os << shelfNo();

        if (memberId() != 0 && date!= currentDate){ 
            os << ' ' << memberId();
            os << std::setfill(' ') << std::setw(3) << ' ';
            os << date;
          }
       }

    else if (mediaType()== SDDS_FILE)
    {
      os << recID();
      os << name();
      os << '\t';
      os << m_ISBN;
      os << '\t';
      os << shelfNo();
      os << '\t';
      os << m_memberID;
      if (m_memberID!= 0 ){
        os << '\t' << date;
      }
      os<< endl;
    }

    return os;
  }


}