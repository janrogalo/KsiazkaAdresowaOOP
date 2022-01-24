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
    const string nazwaPlikuZUzytkownikami;
    bool czyPlikJestPusty();
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
    
    
public:
    PlikZUzytkownikami(string NAZWAPLIKUZUZYTKOWNIKAMI) : nazwaPlikuZUzytkownikami(NAZWAPLIKUZUZYTKOWNIKAMI){};
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
   void  zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownic);
  
};

#endif /* PlikZUzytkownikami_hpp */
