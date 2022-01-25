#include "KsiazkaAdresowa.hpp"

void KsiazkaAdresowa::rejestracjaUzytkownika(){
uzytkownikMenadzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow(){
uzytkownikMenadzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika(){
uzytkownikMenadzer.logowanieUzytkownika();
    if (uzytkownikMenadzer.czyUzytkownikJestZalogowany()){
        adresatMenadzer = new AdresatMenadzer (NAZWA_PLIKU_Z_ADRESATAMI,  uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){
uzytkownikMenadzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::dodajAdresata(){
    adresatMenadzer -> dodajAdresata();
}

void KsiazkaAdresowa::wypiszWszystkichAdresatow(){
    adresatMenadzer -> wypiszWszystkichAdersatow();
}

void KsiazkaAdresowa::wylogujUzytkownika(){
    uzytkownikMenadzer.wylogujUzytkownika();
    delete adresatMenadzer;
    adresatMenadzer = NULL;
}

int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika(){
   return uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::edytujAdresata(){
    adresatMenadzer->edytujAdresata();
}

void KsiazkaAdresowa::usunAdresata(){
    adresatMenadzer->usunAdresata();
}
