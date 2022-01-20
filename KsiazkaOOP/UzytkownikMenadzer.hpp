
#ifndef UzytkownikMenadzer_hpp
#define UzytkownikMenadzer_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream> 

#include "PlikZUzytkownikami.hpp"

using namespace std;

class UzytkownikMenadzer{
    
    
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
    PlikZUzytkownikami plikZUzytkownikami;
    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    
    
    
public:
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wczytajUzytkownikowZPliku();

    
};




#endif /* UzytkownikMenadzer_hpp */
