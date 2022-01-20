#include <iostream>
#include "KsiazkaAdresowa.hpp"

int main() {

    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy2.txt");
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    
    return 0;
}

