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

void KsiazkaAdresowa::menuUzytkownika(){
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
}

void KsiazkaAdresowa::menuGlowne(){
    cout << endl << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
}


void KsiazkaAdresowa::wyszukajPoImieniu(){
    adresatMenadzer->wyszukajAdresatowPoImieniu();
}

void KsiazkaAdresowa::wyszukajPoNazwisku(){
    adresatMenadzer->wyszukajAdresatowPoNazwisku();
}
