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

    adresat.ustawId(plikZAdresatami.pobierzZPlikuIdOstatniegoAdresata() +1);
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
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
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


void AdresatMenadzer::edytujAdresata()
{
 
    Adresat adresat;
    int idEdytowanegoAdresata = 0;
   // int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = podajIdWybranegoAdresata();

    bool czyIstniejeAdresat = false;

    for (int i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].pobierzId() == idEdytowanegoAdresata)
        {
            czyIstniejeAdresat = true;
            char wybor;

            cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
            cout << "---------------------------" << endl;
            cout << "Ktore dane zaktualizowac: " << endl;
            cout << "1 - Imie" << endl;
            cout << "2 - Nazwisko" << endl;
            cout << "3 - Numer telefonu" << endl;
            cout << "4 - Email" << endl;
            cout << "5 - Adres" << endl;
            cout << "6 - Powrot " << endl;
            cout << endl << "Twoj wybor: ";
            wybor = getchar();

            switch (wybor)
            {
            case '1':
                cout << "Podaj nowe imie: ";
                    cin.ignore();
                adresaci[i].ustawImie(MetodyPomocnicze::wczytajLinie());
                    
                    adresaci[i].ustawImie( MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].pobierzImie()));
        
            
                    plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
              
                break;
            case '2':
                    
                cout << "Podaj nowe nazwisko: ";
                    cin.ignore();
                    adresaci[i].ustawNazwisko(MetodyPomocnicze::wczytajLinie());
                        adresaci[i].ustawNazwisko( MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].pobierzNazwisko()));
                    
                    plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                     break;
                    
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                    cin.ignore();
                    adresaci[i].ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());
                    plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                    break;
            case '4':
                cout << "Podaj nowy email: ";
                    cin.ignore();
                    adresaci[i].ustawEmail(MetodyPomocnicze::wczytajLinie());
                    plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                     break;
            case '5':
                    cin.ignore();
                    cout << "Podaj nowy adres zamieszkania: ";
                    adresaci[i].ustawAdres(MetodyPomocnicze::wczytajLinie());
                    plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                    break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
}


int AdresatMenadzer::podajIdWybranegoAdresata()
{
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = MetodyPomocnicze::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}



void AdresatMenadzer:: usunAdresata(){
    int idUsuwanegoAdresata = 0;
 
    cin.ignore();
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();


    char znak;
    bool czyIstniejeAdresat = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
    {
        if (itr -> pobierzId() == idUsuwanegoAdresata)
        {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = getchar();
            if (znak == 't')
            {
           
                plikZAdresatami.usunWybranaLinieWPliku(idUsuwanegoAdresata);
                adresaci.erase(itr);
            
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                break;
            }
            else
            {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
    }
}
void AdresatMenadzer::wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}



void AdresatMenadzer::wyszukajAdresatowPoImieniu()
{
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        cin.ignore();
        imiePoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        imiePoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (vector <Adresat>::iterator  itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if (itr -> pobierzImie() == imiePoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    
}


void AdresatMenadzer::wyszukajAdresatowPoNazwisku()
{
    string nazwiskoPoszukiwanegoAdresata;
    int iloscAdresatow = 0;

 
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        cin.ignore();
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if (itr -> pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
}
