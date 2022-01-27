#ifndef AdresatMenadzer_hpp
#define AdresatMenadzer_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Adresat.hpp"
#include "MetodyPomocnicze.hpp"
#include "PlikZAdresatami.hpp"

class AdresatMenadzer{
    
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    int idOstatniegoAdresata;
    
    Adresat podajDaneNowegoAdresata();
    
public:
    AdresatMenadzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika) : plikZAdresatami( nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika){
        adresaci = plikZAdresatami.wczytajAdresatowZPliku(idZalogowanegoUzytkownika);
    };
    
    void dodajAdresata();
    void wypiszWszystkichAdersatow();
    int pobierzIdOstatniegoAdresata();
    int ustawIdOstatniegoAdresata();
    void wczytajAdresatowZPliku();
    int pobierzIdZalogowanegUzytkownika();
    void edytujAdresata();
    int podajIdWybranegoAdresata();
    void usunAdresata();
    void wyszukajAdresatowPoImieniu();
    void wyswietlDaneAdresata(Adresat adresat);
    void wyszukajAdresatowPoNazwisku();
    
};

#endif
