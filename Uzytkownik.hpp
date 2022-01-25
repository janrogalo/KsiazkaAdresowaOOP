#ifndef Uzytkownik_hpp
#define Uzytkownik_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Uzytkownik{

    int id;
    string login;
    string haslo;

public:
    void ustawId(int noweId);
    void ustawLogin( string nowyLogin);
    void ustawHaslo (string noweHaslo);
    
    int pobierzID();
    string pobierzLogin();
    string pobierzHaslo();

};


#endif /* Uzytkownik_hpp */

