#include "PlikZAdresatami.hpp"

bool PlikZAdresatami::dopiszAdresataaDoPliku(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::out | ios::app);
    
    if (plikTekstowy.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
        
        if (czyPlikJestPusty() == true)
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
        idOstatniegoAdresata++;
        plikTekstowy.close();
        return true;
    }
    return false;
}


string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';
    
    return liniaZDanymiAdresata;
}

vector <Adresat> PlikZAdresatami::wczytajAdresatowZPliku(int idZalogowanegoUzytkownika)
{
    
    vector<Adresat>adresaci;
    Adresat adresat;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstatniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(),ios::in );
    if (plikTekstowy.good() == true){
        while(getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)){
            if (idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)) {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstatniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        plikTekstowy.close();
    }
    if (daneOstatniegoAdresataWPliku != "") {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstatniegoAdresataWPliku);
    }
    return adresaci;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));
    
    return idUzytkownika;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;
    
    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
                case 1:
                    adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                    break;
                case 2:
                    adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                    break;
                case 3:
                    adresat.ustawImie(pojedynczaDanaAdresata);
                    break;
                case 4:
                    adresat.ustawNazwisko(pojedynczaDanaAdresata);
                    break;
                case 5:
                    adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                    break;
                case 6:
                    adresat.ustawEmail(pojedynczaDanaAdresata);
                    break;
                case 7:
                    adresat.ustawAdres(pojedynczaDanaAdresata);
                    break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

string PlikZAdresatami::pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

int PlikZAdresatami::pobierzIdOstatniegoAdresata()
{
    return idOstatniegoAdresata;
    
}

//

void PlikZAdresatami::zaktualizujDaneWybranegoAdresata(Adresat adresat, int idEdytowanegoAdresata)
{
    string liniaZDanymiAdresata = "";
    int numerLiniiWPlikuTekstowym = 1;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    fstream plikTekstowy, tymczasowyPlikTekstowy;
    
    tymczasowyPlikTekstowy.open("temp.txt", ios::in | ios::app);
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    
    
    if (plikTekstowy.good() == true || idOstatniegoAdresata != 0)
    {
        while(getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idEdytowanegoAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                if (numerLiniiWPlikuTekstowym == 1){
                    liniaZDanymiAdresata =zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
                   tymczasowyPlikTekstowy << liniaZDanymiAdresata;
                
                }
                else if (numerLiniiWPlikuTekstowym > 1){
                    liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
                   tymczasowyPlikTekstowy << endl << liniaZDanymiAdresata;
                }
                numerLiniiWPlikuTekstowym++;
            }
        
        else{
            if (numerLiniiWPlikuTekstowym == 1){
                tymczasowyPlikTekstowy << daneJednegoAdresataOddzielonePionowymiKreskami;
            }
            else if (numerLiniiWPlikuTekstowym > 1){
                tymczasowyPlikTekstowy << endl << daneJednegoAdresataOddzielonePionowymiKreskami;
            }
            numerLiniiWPlikuTekstowym++; //
        }
        }
        
        plikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(pobierzNazwePliku());
        zmienNazwePliku("temp.txt", pobierzNazwePliku());
   
    }
    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}



void PlikZAdresatami::usunPlik(string nazwaPlikuZRozszerzeniem)
{
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}

void PlikZAdresatami::zmienNazwePliku(string staraNazwa, string nowaNazwa)
{
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}

void PlikZAdresatami::usunWybranaLinieWPliku(int idUsuwanegoAdresata)
{
    fstream plikTekstowy, tymczasowyPlikTekstowy;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    int numerLiniiWPlikuTekstowym = 1;

    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open("temp.txt", ios::out | ios::app);

    if (plikTekstowy.good() == true)
    {
        while(getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idUsuwanegoAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)){
                ;
            }
        
        else{
            if (numerLiniiWPlikuTekstowym == 1){
                tymczasowyPlikTekstowy << daneJednegoAdresataOddzielonePionowymiKreskami;
            }
            else if (numerLiniiWPlikuTekstowym > 1){
                tymczasowyPlikTekstowy << endl << daneJednegoAdresataOddzielonePionowymiKreskami;
            }
        }
            numerLiniiWPlikuTekstowym++;
        }
        
        plikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(pobierzNazwePliku());
        zmienNazwePliku("temp.txt", pobierzNazwePliku());
   
    }
    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}

int PlikZAdresatami::pobierzZPlikuIdOstatniegoAdresata()
{
    int idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {}
            daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
            plikTekstowy.close();
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }
    return idOstatniegoAdresata;
}
        
        
        
        
        
        
        
        
        
        
        
        
        
 

