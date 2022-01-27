#ifndef PlikZAdresatami_hpp
#define PlikZAdresatami_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Adresat.hpp"
#include "MetodyPomocnicze.hpp"
#include "PlikTekstowy.hpp"

using namespace std;

class PlikZAdresatami :  public PlikTekstowy {
    int idOstatniegoAdresata;
    int idZalogowanegoUzytkownika;
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    Adresat pobierzDaneAdresata(string daneJednegoAdresataOddzielonePionowymiKreskami);
    
public:
    PlikZAdresatami(string nazwaPliku) : PlikTekstowy(nazwaPliku)
    {
        idOstatniegoAdresata = 0;
    };
    
    bool dopiszAdresataaDoPliku(Adresat adresat);
    vector <Adresat> wczytajAdresatowZPliku (int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresata();
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    void zaktualizujDaneWybranegoAdresata(Adresat adresat, int idEdytowanegoAdresata);
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);
    void usunWybranaLinieWPliku(int idUsuwanegoAdresata);
    int  pobierzZPlikuIdOstatniegoAdresata();
};

#endif /* PlikZAdresatami_hpp */
