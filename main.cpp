#include <iostream>
#include "KsiazkaAdresowa.hpp"

int main() {
    
KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy2.txt", "Kontakty.txt");
    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.usunAdresata();
    ksiazkaAdresowa.dodajAdresata();
   // ksiazkaAdresowa.dodajAdresata();
    //cin.ignore();
    ksiazkaAdresowa.edytujAdresata();
    
    
   /*
    
    
    int idZalogowanegoUzytkowika = 0;

  
    while (true) {
    char wybor;

    cout << endl << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    
    wybor = getchar();
    if (idZalogowanegoUzytkowika == 0){
      
        switch (wybor)
        {
        case '1':
            ksiazkaAdresowa.rejestracjaUzytkownika();
                cin.ignore();
            break;
        case '2':
            ksiazkaAdresowa.logowanieUzytkownika();
                idZalogowanegoUzytkowika = ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika();
                cout << idZalogowanegoUzytkowika;
            break;
        case '9':
            exit(0);
            break;
        default:
            cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
            break;
        }
        cout << idZalogowanegoUzytkowika << endl;
    }
    
    if ( idZalogowanegoUzytkowika != 0){
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
            wybor = getchar();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.dodajAdresata();
                break;
            case '2':
              //  wyszukajAdresatowPoImieniu(adresaci);
                break;
            case '3':
             //   wyszukajAdresatowPoNazwisku(adresaci);
                break;
            case '4':
                    ksiazkaAdresowa.wypiszWszystkichAdresatow();
                break;
            case '5':
            //    idUsunietegoAdresata = usunAdresata(adresaci);
                break;
            case '6':
              //  edytujAdresata(adresaci);
                break;
            case '7':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                ksiazkaAdresowa.wylogujUzytkownika();
                cin.ignore();
                break;
        }
    }
    }
    
    */
}
