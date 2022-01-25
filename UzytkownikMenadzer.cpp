
#include "UzytkownikMenadzer.hpp"

void UzytkownikMenadzer::ustawIdZalogowanegoUzytkownika (int IDZALOGOWANEGOUZYTKOWNIKA ){
    idZalogowanegoUzytkownika = IDZALOGOWANEGOUZYTKOWNIKA;
}

int UzytkownikMenadzer::pobierzIdZalogowanegoUzytkownika(){
    return idZalogowanegoUzytkownika;
}


void UzytkownikMenadzer::rejestracjaUzytkownika(){
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();
    uzytkownicy.push_back(uzytkownik);
    // PlikZUzytkownikami plikZUzytkownikami;
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
}


Uzytkownik UzytkownikMenadzer::podajDaneNowegoUzytkownika(){
    Uzytkownik uzytkownik;
    string login, haslo;
    
    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);
    
    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);
    return uzytkownik;
}

int UzytkownikMenadzer::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzID() + 1;
}

bool UzytkownikMenadzer::czyIstniejeLogin(string login)
{
    for(int i=0; i <  uzytkownicy.size(); i++){
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            cout << "Istnieje użytkownik o takim loginie" << endl;
            return true;
        }
    }
    return false;
}

void UzytkownikMenadzer::wypiszWszystkichUzytkownikow()
{
    for(int i=0; i <  uzytkownicy.size(); i++){
        cout << uzytkownicy[i].pobierzID()<<endl;
        cout << uzytkownicy[i].pobierzLogin()<< endl;
        cout << uzytkownicy[i].pobierzHaslo()<< endl;
    }
}


int UzytkownikMenadzer::logowanieUzytkownika()
{
    Uzytkownik uzytkownik;
    string login = "", haslo = "";
    cin.ignore();
    
    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();
    
    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr -> pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();
                
                if (itr -> pobierzHaslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    idZalogowanegoUzytkownika = itr -> pobierzID();
                    return idZalogowanegoUzytkownika;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    return 0;
}


void UzytkownikMenadzer::zmianaHaslaZalogowanegoUzytkownika()
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    cin >> noweHaslo;
    
    
    for (int i=0; i < uzytkownicy.size(); i++){
        if (uzytkownicy[i].pobierzID() == pobierzIdZalogowanegoUzytkownika())
        {   uzytkownicy[i].ustawHaslo(noweHaslo);
            cout <<"Haslo zostalo zmienione." << endl << endl;
        }
        
        plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
    }
}

void UzytkownikMenadzer::wylogujUzytkownika(){
    ustawIdZalogowanegoUzytkownika(0);
}

bool UzytkownikMenadzer::czyUzytkownikJestZalogowany()
{
    if (idZalogowanegoUzytkownika >0)
        return true;
    else
        return false;
}
