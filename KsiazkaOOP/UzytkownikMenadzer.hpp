
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
    };
    int logowanieUzytkownika();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wczytajUzytkownikowZPliku();
    void zmianaHaslaZalogowanegoUzytkownika();
    void ustawIdZalogowanegoUzytkownika (int IDZALOGOWANEGOUZYTKOWNIKA );
    int pobierzIdZalogowanegoUzytkownika();
    void wylogujUzytkownika();
    
};




#endif /* UzytkownikMenadzer_hpp */
