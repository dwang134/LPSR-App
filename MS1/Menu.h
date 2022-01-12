//Name: Dylan Wang
//Course: OOP244NEF
//StudentNum:  114099187
//Date: 11/14/2019
//File name: Menu.h

#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
using namespace std; 

namespace sdds{

    //CONST INT
    const unsigned int MAX_MENU_ITEMS= 20;

    class MenuItem{

        private: 

            char* m_description; //description 

        //make menu a friend class 
            friend class Menu;

        //constructor default value 
            MenuItem();

        //constructor with DMA 
            MenuItem(const char * description);
            void SetmTitle(const char * description);

        //copy assignment prevention 
            MenuItem(const MenuItem& temp_obj) = delete;
            MenuItem& operator=(const MenuItem& temp_obj) = delete;

        //Cast overload 
            operator bool() const;
            operator const char*()const;

            // bool isEmpty() const;

        //Write function 
            std::ostream& write(std::ostream& os = std::cout) const;

        //destructor DMA

            ~MenuItem();
    };

    class Menu{

        private: 


            MenuItem title; 

            MenuItem* m_menuList[MAX_MENU_ITEMS] = {nullptr};  //address of menuItem

            int m_numP= 0;

        public: 

            Menu();

            ~Menu();

            Menu(const char*);

            const char* getTitle() const;

            ostream& display(ostream& os) const;

            unsigned int operator~();

            unsigned int getSelection();

            Menu& operator<<(const char* itemName);

            //type casting 
            operator unsigned int() const;

            operator bool() const;

            // int& operator[] (int index);

            const char* operator [](int index) const;

    };

        std::ostream& operator<<(ostream& os, const Menu& m);

        //  void read(int& val, int min, int max , const char* errorMessage = "");
        //  void read(char* str, int len, const char* errorMessage = "");


}
#endif