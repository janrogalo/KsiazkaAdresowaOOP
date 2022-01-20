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
};

#endif /* KsiazkaAdresowa_hpp */

