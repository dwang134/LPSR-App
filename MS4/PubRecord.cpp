#include "PubRecord.h"
#include <iomanip>
#include <iostream>
#include <cstring>

using namespace std; 

namespace sdds{

    void PubRecord::name(const char * name){
        delete [] m_pName;
        //get the length
        int nameLength= strlen(name);
        //dynamic array
        m_pName= new char[nameLength+ 1];
        //copy content 
        strncpy(m_pName, name, nameLength);
        //end of string 
        m_pName[nameLength]= '\0';
    }

    const char* PubRecord::name() const{
        // if (m_pName!= nullptr){
            return m_pName;
        // }else{
        //     return "";
        // }
    }

    PubRecord::PubRecord(){
        m_pName= nullptr;
        m_shelfNum= 0;
        m_type= 0;
    }

    PubRecord::~PubRecord(){
        delete [] m_pName;
        m_pName= nullptr;
    }

    PubRecord::PubRecord(const PubRecord & other){
        m_shelfNum= other.m_shelfNum;
        m_type= other.m_type;
        if (other.m_pName!= nullptr && other.m_pName[0]!= '\0'){
            int nameLength= strlen(other.m_pName);
            m_pName= new char[nameLength+1];
            strncpy(m_pName, other.m_pName, nameLength);
            m_pName[nameLength] = '\0';
        }
        else{
            m_pName= nullptr;
        }
    }

    PubRecord& PubRecord::operator=(const PubRecord& other){
        if (this != &other){
        // set BOTH type and shelfNUMNEWIEWNRRIWN
        m_shelfNum= other.m_shelfNum;
        m_type= other.m_type;

            if (other.m_pName != nullptr){
                name(other.m_pName);
            }
            else{
                m_pName= nullptr;
            }
        }
        return *this;
    }
    
    int PubRecord::mediaType() const{
        return m_type;
    }

    void PubRecord::mediaType(int type){
        m_type= type;
    }

    //set the shelf number MS4 MS4 MS4 !
    void PubRecord::shelfNo(int value){
        m_shelfNum= value;
    }

    int PubRecord::shelfNo() const{
        return m_shelfNum;
    }

    void PubRecord::readShelfNo(){
        cin >> m_shelfNum;

        while (!(m_shelfNum > 99 && m_shelfNum < 1000)){
            cout<< "Invalid Shelf Number, Enter again: ";
            cin >> m_shelfNum;
        }
    }

    bool PubRecord::operator==(const char* substr) const{

        if (strstr(m_pName, substr) != nullptr){
            return true;
        }
        else {
            return false;
        }

    };

    bool PubRecord::operator==(char type) const{
        
		bool valid = false;

		if (type == recID())
		{
			valid = true;
		}
        else{
            valid= false;
        }

		return valid;

    }

    PubRecord::operator bool() const{
        if (m_pName!= nullptr){
            return true; 
        }
        else{
            return false; 

        }
    }




}