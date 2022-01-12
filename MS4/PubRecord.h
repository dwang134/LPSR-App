#ifndef SDDS_PUBRECORD_H
#define SDDS_PUBRECORD_H
#include "ReadWriteable.h"
#include "Date.h"
#include <iostream>
#include <fstream>

namespace sdds{
    
    const int SDDS_CONSOLE = 0;

    const int SDDS_FILE= 1;

    class PubRecord : public ReadWriteable{


        char * m_pName;

        int m_shelfNum;

        int m_type; 

        protected: 

            void name(const char * name);

            const char* name() const;

            //ADDED PROTECTED MS4
            //used to set the shelf number!
            void shelfNo(int value);

        public: 

            virtual char recID()const = 0;
    
            virtual void checkIn() = 0; 
            
            virtual void checkOut() = 0;

            PubRecord();

            virtual ~PubRecord()= 0;

            PubRecord(const PubRecord & other);

            PubRecord& operator=(const PubRecord& other);

            int mediaType() const; //return mediaType

            void mediaType(int type); //set media type 
            
            int shelfNo() const;

            void readShelfNo();

            bool operator==(const char*) const;

            bool operator==(char) const;

            operator bool() const;
    };

}
#endif