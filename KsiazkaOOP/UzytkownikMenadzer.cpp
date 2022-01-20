
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

void UzytkownikMenadzer::wczytajUzytkownikowZPliku()
{
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}

int UzytkownikMenadzer::logowanieUzytkownika()
{
    Uzytkownik uzytkownik;
    string login = "", haslo = "";
    cout << endl << "Podaj login: ";
    cin >> login;
    int i = 0;
 
    while( i < uzytkownicy.size()){
        if (uzytkownicy[i].pobierzLogin()==login){
            for (int iloscProb = 3; iloscProb > 0; iloscProb--){
                cin.ignore();
                cout <<"Podaj haslo. Pozostało prob: " << iloscProb <<": ";
                cin >> haslo;
                if (uzytkownicy[i].pobierzHaslo()==haslo){
                    cout << endl << "Zalogowales sie." << endl << endl;

                    ustawIdZalogowanegoUzytkownika(uzytkownicy[i].pobierzID());
                    cout << pobierzIdZalogowanegoUzytkownika();
                    return pobierzIdZalogowanegoUzytkownika();
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            return 0;
        }
        i++;
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
   // adresaci.clear();
}

