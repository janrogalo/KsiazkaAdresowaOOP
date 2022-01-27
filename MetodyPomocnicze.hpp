#ifndef MetodyPomocnicze_hpp
#define MetodyPomocnicze_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Uzytkownik.hpp"

using namespace std;

class MetodyPomocnicze{
    
public:
static string konwerjsaIntNaString(int liczba);
static string wczytajLinie();
static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
static int konwersjaStringNaInt(string liczba);
static int wczytajLiczbeCalkowita();

};


#endif /* MetodyPomocnicze_hpp */
