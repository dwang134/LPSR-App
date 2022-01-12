#include <iostream>
#include <iomanip>
#include "Magazine.h"
#include "Utils.h"
#include "PubRecord.h"

using namespace std;

namespace sdds{

    Magazine::Magazine(){
        m_volume= 0;
        m_iNum= 0; 
    }


    Magazine::Magazine(const Magazine & other): PubRecord(other){
        m_volume= other.m_volume;
        m_iNum= other.m_iNum;
    }

    Magazine& Magazine::operator=(const Magazine& other)
    {
        if (this != &other)
        {
        m_volume = other.m_volume;
        m_iNum = other.m_iNum;
        (PubRecord&)*this = other;
        }
        return *this;
    }

    char Magazine::recID() const{
        return 'M';
        //CHECK NOT DONE YET!!!!
        //Use this function’s return value to tag the Magazine records in the file. (see the Write function).
    }


    void Magazine::checkIn(){
        cout << "Magazines cannot be checked in or out!" << endl;
    }

    void Magazine::checkOut(){
        cout << "Magazines cannot be checked in or out!" << endl;
    }

    std::istream& Magazine::read(std::istream& is){
        //temporary variables in the function block 
        char pubName[PUB_MAX];
        int volume;
        int issueNum;
        int shelfNum;
        // bool valid;

        if (mediaType() == SDDS_CONSOLE)
        {

            if(name()== nullptr){
                cout << "Magazine Name: ";
                validString(pubName, PUB_MAX, "Magazine name too long, Enter again: ");
                //dynamically allocate now
                name(pubName);
                    is.clear();
            }

            if (name()!= nullptr){
                cout<< "Volume: ";
                validInt(volume, 1, 99, "Invalid Volume number, Enter again: ");
                //set
                m_volume = volume;
            }

            if (name()!= nullptr){
                cout << "Issue: ";
                validInt(issueNum, 1, 99, "Invalid Issue number, Enter again: ");
                //set 
                m_iNum= issueNum;
            }

            if (name()!= nullptr){
                cout << "Shelf Number: ";
                readShelfNo();
            }

        }

            else if (mediaType()== SDDS_FILE){ //going to re-use some code from Date.cpp

                    //make a seperator 
                    // char sep; 

                    //read the year, the month, and the day 
                    //fix the name using is.getline(pub, PUB_MAX, '\t')
                    // given an input of C++ Journal\t1\t2\t3
                    // getline gets the C++ Journal and discards the first tab
                    // use is >> style for remaining values
                    is.getline(pubName, PUB_MAX, '\t') >> volume;
                    is.ignore() >> issueNum;
                    is.ignore() >> shelfNum;

                    // is>> pubName >> sep >> volume >> sep >> issueNum >> sep >> shelfNum >> sep; 

                    // if it fails 
                    if (is.fail()) {
                        is.clear();
                        is.ignore(1000, '\n');
                    }
                    else{
                        name(pubName);
                        m_volume= volume; 
                        m_iNum= issueNum;
                        shelfNo(shelfNum);
                    }
                    
            }
            //clear buffer is very good for your mental health : )
            is.clear();
            is.ignore(1000, '\n');
            return is; 

        }// is end


    std::ostream& Magazine::write(std::ostream& os) const //change everything to os!
    {
        if (mediaType() == SDDS_CONSOLE)
        {
            os << std::setw(41) << std::left << name(); 
            os << std::setfill(' ') << std::setw(7) << ' ';
            os << std::setfill('0') << std::setw(2) << std::right << m_volume;
            os << "(" << std::right << std::setw(2)<< std::setfill('0') << m_iNum << ")";
            os << std::setfill(' ') << std::setw(2) << ' ';
            os << shelfNo();
            
        }
         else if (mediaType() == SDDS_FILE)
        {
            //print the recID???
            os << recID();
            os << name();
            os << "\t";
            os << m_volume;
            os << "\t";
            os << m_iNum;
            os << "\t";
            os << shelfNo();
            os << endl;
        }

        // os.clear();
        return os;
        
    }//ostream


}//namespace sdds
