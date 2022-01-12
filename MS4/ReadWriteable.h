
//Name: Dylan Wang
//Course: OOP244NEF
//StudentNum:  114099187
//Date: 12/02/2019
//File name: ReadWriteable.h

#ifndef SDDS_WRITEABLE_H
#define SDDS_WRITEABLE_H
#include <iostream>
#include <fstream>
using namespace std;

namespace sdds{

    class ReadWriteable{
        
        public:

        virtual std::ostream& write(std::ostream& os= std::cout) const = 0;

        virtual std::istream& read(std::istream& is= std::cin) = 0;


    };

    	std::ostream& operator<<(std::ostream& , const ReadWriteable&);
		std::istream& operator>>(std::istream& , ReadWriteable&);

}
#endif