
#include "UzytkownikMenadzer.hpp"

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



