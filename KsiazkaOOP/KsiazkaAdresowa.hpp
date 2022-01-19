#ifndef KsiazkaAdresowa_hpp
#define KsiazkaAdresowa_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Uzytkownik.hpp"

using namespace std;

class KsiazkaAdresowa{
    
    vector <Uzytkownik> uzytkownicy;
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;
    string nazwaPlikuZUzytkownikami;
    
    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    bool czyPlikJestPusty(fstream &plikTekstowy);
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    string konwerjsaIntNaString(int liczba);
    
public:
    
    KsiazkaAdresowa();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();

 
    
};

#endif /* KsiazkaAdresowa_hpp */

