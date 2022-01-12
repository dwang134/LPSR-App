#include "ReadWriteable.h"
#include <iostream>
#include <fstream>
using namespace std;


namespace sdds{


    ostream& operator<<(std::ostream& os, const ReadWriteable& r1){
        r1.write(os);
        return os;
    }

    istream& operator>>(std::istream& is, ReadWriteable& r2){
        r2.read(is);
        return is;
    }


}