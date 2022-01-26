#ifndef PlikTekstowy_hpp
#define PlikTekstowy_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
 
using namespace std;
 
class PlikTekstowy {
 
    const string NAZWA_PLIKU;
 
public:
 
    PlikTekstowy(string nazwaPliku) : NAZWA_PLIKU(nazwaPliku) {
    }
 
    string pobierzNazwePliku();
    bool czyPlikJestPusty();
    
};

#endif /* PlikTekstowy_hpp */
