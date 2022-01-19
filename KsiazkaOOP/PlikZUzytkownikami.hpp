
#ifndef PlikZUzytkownikami_hpp
#define PlikZUzytkownikami_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Uzytkownik.hpp"
#include "MetodyPomocnicze.hpp"

using namespace std;

class PlikZUzytkownikami{
    fstream plikTekstowy;
    string nazwaPlikuZUzytkownikami;
    bool czyPlikJestPusty();
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    
public:
    PlikZUzytkownikami();
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
  
};

#endif /* PlikZUzytkownikami_hpp */
