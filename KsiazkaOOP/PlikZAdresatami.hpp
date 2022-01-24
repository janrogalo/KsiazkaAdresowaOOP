#ifndef PlikZAdresatami_hpp
#define PlikZAdresatami_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Adresat.hpp"
#include "MetodyPomocnicze.hpp"

using namespace std;

class PlikZAdresatami{
    const string nazwaPlikuZAdresatami;
    int idOstatniegoAdresata;
    int idZalogowanegoUzytkownika;
    
    bool czyPlikJestPusty();
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    
    Adresat pobierzDaneAdresata(string daneJednegoAdresataOddzielonePionowymiKreskami);
    
public:
    PlikZAdresatami(string NAZWAPLIKUZADRESATAMI) : nazwaPlikuZAdresatami(NAZWAPLIKUZADRESATAMI){
        idOstatniegoAdresata = 0;
    };
    
    bool dopiszAdresataaDoPliku(Adresat adresat);
    vector <Adresat> wczytajAdresatowZPliku (int idZalogowanegoUzytkownika);
   int pobierzIdOstatniegoAdresata();
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
  
};

#endif /* PlikZAdresatami_hpp */
