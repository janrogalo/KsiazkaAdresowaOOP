#ifndef KsiazkaAdresowa_hpp
#define KsiazkaAdresowa_hpp

#include <stdio.h>
#include <iostream>
#include "UzytkownikMenadzer.hpp"

using namespace std;

class KsiazkaAdresowa{
    
    UzytkownikMenadzer uzytkownikMenadzer;
    
public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenadzer(nazwaPlikuZUzytkownikami){
        uzytkownikMenadzer.wczytajUzytkownikowZPliku();
    };
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();

};

#endif /* KsiazkaAdresowa_hpp */

