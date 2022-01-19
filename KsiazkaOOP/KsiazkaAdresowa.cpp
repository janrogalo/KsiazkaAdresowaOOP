#include "KsiazkaAdresowa.hpp"


KsiazkaAdresowa::KsiazkaAdresowa(){
    uzytkownikMenadzer.wczytajUzytkownikowZPliku();
}


void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenadzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenadzer.wypiszWszystkichUzytkownikow();
}
