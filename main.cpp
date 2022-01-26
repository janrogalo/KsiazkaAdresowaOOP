#include <iostream>
#include "KsiazkaAdresowa.hpp"

int main() {
    
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy2.txt", "Kontakty.txt");
    int idZalogowanegoUzytkowika = 0;
    
    do{
        char wybor;
   
        if (idZalogowanegoUzytkowika == 0){
            ksiazkaAdresowa.menuGlowne();
            wybor = getchar();
            switch (wybor)
            {
                case '1':
                    ksiazkaAdresowa.rejestracjaUzytkownika();
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
        }
        
        if ( idZalogowanegoUzytkowika != 0){
            ksiazkaAdresowa.menuUzytkownika();
            wybor = getchar();
            switch (wybor)
            {
                case '1':
                    cout << idZalogowanegoUzytkowika;
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
                    cin.ignore();
                    cout << endl << "Nacisnij klawisz by kontynuować" << endl;
                    cin.ignore();
                    break;
                case '5':
                    ksiazkaAdresowa.usunAdresata();
                    cin.ignore();
                    break;
                case '6':
                    cin.ignore();
                    ksiazkaAdresowa.edytujAdresata();
                    break;
                case '7':
                    ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                    break;
                case '8':
                    ksiazkaAdresowa.wylogujUzytkownika();
                    idZalogowanegoUzytkowika = 0;
                    break;
            }
        }
      
    }
    while (true);
}
