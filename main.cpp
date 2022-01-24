#include <iostream>
#include "KsiazkaAdresowa.hpp"

int main() {
    
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy2.txt", "Kontakty.txt");
 
    ksiazkaAdresowa.rejestracjaUzytkownika();
    cin.ignore();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.wypiszWszystkichAdresatow();
    ksiazkaAdresowa.wylogujUzytkownika();
    cin.ignore();
    ksiazkaAdresowa.rejestracjaUzytkownika();
    cin.ignore();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    cin.ignore();
    ksiazkaAdresowa.logowanieUzytkownika();
    cin.ignore();
    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.wypiszWszystkichAdresatow();
    ksiazkaAdresowa.wylogujUzytkownika();
    
    

   
 // naprawić pobieranie id uzyytkownika do danych adresata

    return 0;
}

