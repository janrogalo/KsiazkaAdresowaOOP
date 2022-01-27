#ifndef KsiazkaAdresowa_hpp
#define KsiazkaAdresowa_hpp

#include <stdio.h>
#include <iostream>
#include "UzytkownikMenadzer.hpp"
#include "AdresatMenadzer.hpp"

using namespace std;

class KsiazkaAdresowa{
    
    UzytkownikMenadzer uzytkownikMenadzer;
    AdresatMenadzer *adresatMenadzer;
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    
public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) : uzytkownikMenadzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami){
        adresatMenadzer = NULL;
    };
    
    ~KsiazkaAdresowa(){
        delete adresatMenadzer;
        adresatMenadzer = NULL;
    }
    
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void dodajAdresata();
    void wypiszWszystkichAdresatow();
    void wylogujUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();
    void edytujAdresata();
    void usunAdresata();
    void menuUzytkownika();
    void menuGlowne();
    void wyszukajPoImieniu();
    void wyszukajPoNazwisku();
};

#endif /* KsiazkaAdresowa_hpp */

