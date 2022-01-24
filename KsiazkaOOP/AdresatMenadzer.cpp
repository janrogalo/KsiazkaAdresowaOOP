#include "AdresatMenadzer.hpp"

void AdresatMenadzer::dodajAdresata()
{
    Adresat adresat;

    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();
    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataaDoPliku(adresat);
}

Adresat AdresatMenadzer::podajDaneNowegoAdresata()
{
    Adresat adresat;

    adresat.ustawId(plikZAdresatami.pobierzIdOstatniegoAdresata() +1);
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);
                            

    cin.ignore();
    cout << "Podaj imie: ";
    adresat.ustawImie(MetodyPomocnicze::wczytajLinie());
    adresat.ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie()));

    
    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(MetodyPomocnicze::wczytajLinie());
    adresat.ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzNazwisko()));

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(MetodyPomocnicze::wczytajLinie());

    return adresat;
}

void AdresatMenadzer::wypiszWszystkichAdersatow()
{
    for(int i=0; i <  adresaci.size(); i++){
        cout << adresaci[i].pobierzId()<<endl;
        cout << adresaci[i].pobierzIdUzytkownika()<<endl;
        cout << adresaci[i].pobierzImie()<<endl;
        cout << adresaci[i].pobierzNazwisko()<<endl;
        cout << adresaci[i].pobierzNumerTelefonu()<<endl;
        cout << adresaci[i].pobierzEmail()<<endl;
        cout << adresaci[i].pobierzAdres()<<endl;
    }
}

int AdresatMenadzer::pobierzIdOstatniegoAdresata(){
    return idOstatniegoAdresata;
}

int AdresatMenadzer::ustawIdOstatniegoAdresata(){
    {
        if (adresaci.empty() == true)
            return 1;
        else
            return adresaci.back().pobierzId() + 1;
    }
}


void AdresatMenadzer::wczytajAdresatowZPliku()
{
    adresaci = plikZAdresatami.wczytajAdresatowZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
}

