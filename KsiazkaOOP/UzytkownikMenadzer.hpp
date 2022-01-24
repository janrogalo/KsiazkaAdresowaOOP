
#ifndef UzytkownikMenadzer_hpp
#define UzytkownikMenadzer_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream> 

#include "PlikZUzytkownikami.hpp"
#include "MetodyPomocnicze.hpp"

using namespace std;

class UzytkownikMenadzer{
    
    
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
    PlikZUzytkownikami plikZUzytkownikami;
    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    
    
    
public:
    UzytkownikMenadzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami( nazwaPlikuZUzytkownikami){
        idZalogowanegoUzytkownika = 0;
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    
    };
    int logowanieUzytkownika();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    //void wczytajUzytkownikowZPliku();
    void zmianaHaslaZalogowanegoUzytkownika();
    void ustawIdZalogowanegoUzytkownika (int IDZALOGOWANEGOUZYTKOWNIKA );
    int pobierzIdZalogowanegoUzytkownika();
    void wylogujUzytkownika();
    bool czyUzytkownikJestZalogowany();
    
};


#endif /* UzytkownikMenadzer_hpp */
