#include "Menu.h"
#include <iostream>
#include <cstring> 
#include <iomanip>
#include "Utils.h"
using namespace std;


namespace sdds{

    MenuItem::MenuItem(const char * description){
            //get the length of the string 
            int descLength= strlen(description);
            //dynamically allocate 
            m_description = new char[descLength+ 1];
            strncpy(m_description, description, descLength);
            m_description[descLength] = '\0';

    }

    // void MenuItem::SetmTitle(const char * title){
    //     //get the length of the string 
    //     int titleLength= strlen(title);
    //     //dynamically allocate 
    //     m_title = new char[titleLength+ 1];
    //     strncpy(m_title, title, titleLength);
    //     m_title[titleLength] = '\0';
    // }

    MenuItem::MenuItem(){
        m_description= nullptr;
    }

//When a MenuItem is casted to “bool” it should return true, 
// if it is not empty and it should return false if it is empty.
    MenuItem::operator bool() const{
        return m_description ? true : false;
    }

//check EMPTY
    // bool MenuItem::isEmpty() const{ 
    //     return ((m_title== nullptr) && (m_numP == 0)) ? true : false; 
    // }

    MenuItem::operator const char*() const{

        if (m_description!= nullptr){
            return m_description;
        }
        else{
            return nullptr; 
        }
    }

//display the description
    std::ostream& MenuItem::write(std::ostream& os) const
    {
        os << m_description; 
        return os;
    }

    MenuItem::~MenuItem(){
        delete [] m_description;
        m_description= nullptr;
    }

    Menu::Menu(){

        m_numP= 0;    
    }

    Menu::~Menu(){
        for (unsigned int i=0; i< MAX_MENU_ITEMS; i++) {
            if (m_menuList[i]!= nullptr){
                delete m_menuList[i];
                m_menuList[i]= nullptr;          
            }
        }
    }

    Menu::Menu(const char* menuTitle){
    
        int descLength= strlen(menuTitle);
        //dynamically allocate 
        title.m_description = new char[descLength+ 1];
        strncpy(title.m_description, menuTitle, descLength);
        title.m_description[descLength] = '\0';

        m_numP= 0;
        // strcpy(m_title, string);
    }

    const char* Menu::getTitle() const{
        if (title.m_description!= nullptr){
            return title.m_description;
        }else{
            return "";
        }
    }

    ostream& Menu::display(ostream& os) const{
        //make index integer
        if (title.m_description != nullptr){
            os<< getTitle() << ":" << endl;
        }
         // have to fix the skip line thing s

        for (int i= 0 ; i < m_numP; i++){ 

            // os << i << std::setw(2) << std::right << "-" << " " << m_menuList[i]->m_description << endl;
            os << std::setw(2) << std::right << i+1 << "-" << " " << m_menuList[i]->m_description << endl;
                    //two spaces on the right put our number and -
        };

        os<< " 0- Exit" << endl;
        os<< "> ";
        return os;
    }


    Menu& Menu::operator<<(const char* itemName){
        for (unsigned int i= 0 ; i < MAX_MENU_ITEMS ; i++){
            if (m_menuList[i]== nullptr){
                if ((unsigned int) m_numP < MAX_MENU_ITEMS){
                    //dynamically create ..?
                    
                    m_menuList[i]= new MenuItem(itemName);
                    // m_menuList[i]->SetmTitle(m_title);
                    m_numP++;
                    return *this;
                }
            }  //else function silently ignores action 
        }
        return *this;
    }

    unsigned int Menu::getSelection() {
        int userInput;

        display(cout); //what would you like the order? 
        read(userInput, 0, 20, "Invalid Selection, try again: ");
        //if m_menuList[0]== nullptr  if nothing got allocated
        //if userInputs 0 

        while (!((userInput >= 0 ) && (userInput <= m_numP))){
            cout<< "Invalid Selection, try again: ";
            read(userInput, 0, 20, "Invalid Selection, try again: ");
        }

        return (unsigned int) userInput;
    }

    //is ok 
    unsigned int Menu::operator~() {
        return getSelection(); 
    }


    Menu::operator unsigned int() const{
        return m_numP;
    }

    Menu::operator bool() const{
        if (m_menuList[0]!= nullptr){
            return true; 
        }
        else{
            return false; 

        }
    }

    ostream & operator<<(ostream & os, const Menu &m){
        os << m.getTitle();
        return os; 
    }

    const char* Menu::operator [] (int index) const
    {
        return m_menuList[index%m_numP]->m_description ;
    }
}