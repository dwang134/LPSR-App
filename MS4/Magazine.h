//Name: Dylan Wang
//Course: OOP244NEF
//StudentNum:  114099187
//Date: 12/02/2019
//File name: Magazine.h

#ifndef SDDS_MAGAZINE_H
#define SDDS_MAGAZINE_H
#include "PubRecord.h"
#include "Utils.h"
#include <iostream>
#include <istream>

namespace sdds{

    const int PUB_MAX= 40;
    
    class Magazine: public PubRecord{


            int m_volume; //((m_volume >= 1) && (m_volume <= 99));

            int m_iNum; //(m_volume >= 1) && (m_volume <= 99);

            public:

            Magazine();

            Magazine(const Magazine & other);

            Magazine& operator=(const Magazine& other); 

            char recID()const;

            void checkIn();

            void checkOut();

            std::ostream& write(std::ostream& os= std::cout) const;

            std::istream& read(std::istream& is= std::cin);


    };



}
#endif