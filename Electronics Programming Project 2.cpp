#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void Wersja_Linux(string, fstream&, bool&);
void Parametry_Jadra(string, fstream&);
void Grupy_Parametrow(string, fstream&);
void Wersja_Linux2(string, fstream&, bool&);
void Parametry_Jadra2(string, fstream&);
void Grupy_Parametrow2(string, fstream&);
int main()
{
    fstream kod_jadra;
    fstream moduly_jadra;
    string linijka;
    fstream plik;
    bool czyuzyto=false;
    bool czyuzyto2=false;
    plik.open("config.txt", ios::in);
    kod_jadra.open("kod_jadra.txt", ios::out);
    moduly_jadra.open("moduly_jadra.txt", ios::out);
    while(plik.good()==true)
    {
        getline(plik, linijka);
        Wersja_Linux(linijka, kod_jadra, czyuzyto);
        Grupy_Parametrow(linijka, kod_jadra);
        Parametry_Jadra(linijka, kod_jadra);
        Wersja_Linux2(linijka, moduly_jadra, czyuzyto2);
        Grupy_Parametrow2(linijka, moduly_jadra);
        Parametry_Jadra2(linijka, moduly_jadra);
    }
    moduly_jadra.close();
    kod_jadra.close();
    plik.close();



    return 0;
}

void Wersja_Linux(string linijka, fstream &kod_jadra, bool &czyuzyto)
{
    if(czyuzyto==false)
    {
        if(linijka.compare(0,7, "# Linux")==0)
        {
            int dlugosc;
            dlugosc=linijka.length();
            for(int i=0; i<dlugosc-2; i++)
            {
                linijka[i]=linijka[i+2];
            }
            linijka[dlugosc-2]=NULL;
            linijka[dlugosc-1]=NULL;
            kod_jadra<<linijka<<endl;
            czyuzyto=true;
        }
    }
}

void Parametry_Jadra(string linijka, fstream &kod_jadra)
{
    if(linijka.compare(0,7, "CONFIG_")==0)
    {
        int dlugosc;
        dlugosc=linijka.length();
        if((linijka[dlugosc-1]=='y')&&(linijka[dlugosc-2]=='='))
        {
            for(int i=0; i<dlugosc-7; i++)
            {
                linijka[i]=linijka[i+7];
            }
            for(int i=0; i<10; i++)
            {
                linijka[dlugosc-i]=NULL;
            }
            kod_jadra<<linijka<<endl;
        }
    }
}

void Grupy_Parametrow(string linijka, fstream &kod_jadra)
{
    if(((linijka[0]=='#')&&(linijka[1]==' ')&&(linijka[2]!=' '))&&
            (linijka.compare(0,5, "# Aut")!=0)&&(linijka.compare(0,5, "# Lin")!=0))
    {
        int dlugosc;
        dlugosc=linijka.length();
        if(linijka.compare(dlugosc-3, 3, "set")!=0)
        {
            for(int i=0; i<dlugosc-2; i++)
            {
                linijka[i]=linijka[i+2];
            }
            linijka[dlugosc-2]=NULL;
            linijka[dlugosc-1]=NULL;
            kod_jadra<<linijka<<endl;
        }
    }
}

void Wersja_Linux2(string linijka, fstream &moduly_jadra, bool &czyuzyto2)
{
    if(czyuzyto2==false)
    {
        if(linijka.compare(0,7, "# Linux")==0)
        {
            int dlugosc;
            dlugosc=linijka.length();
            for(int i=0; i<dlugosc-2; i++)
            {
                linijka[i]=linijka[i+2];
            }
            linijka[dlugosc-2]=NULL;
            linijka[dlugosc-1]=NULL;
            moduly_jadra<<linijka<<endl;
            czyuzyto2=true;
        }
    }
}

void Parametry_Jadra2(string linijka, fstream &moduly_jadra)
{
    if(linijka.compare(0,7, "CONFIG_")==0)
    {
        int dlugosc;
        dlugosc=linijka.length();
        if((linijka[dlugosc-1]=='m')&&(linijka[dlugosc-2]=='='))
        {
            for(int i=0; i<dlugosc-7; i++)
            {
                linijka[i]=linijka[i+7];
            }
            for(int i=0; i<10; i++)
            {
                linijka[dlugosc-i]=NULL;
            }
            moduly_jadra<<linijka<<endl;
        }
    }
}

void Grupy_Parametrow2(string linijka, fstream &moduly_jadra)
{
    if((linijka[0]=='#')&&(linijka[1]==' ')&&(linijka[2]!=' ')&&
            (linijka.compare(0,5, "# Aut")!=0)&&(linijka.compare(0,5, "# Lin")!=0))
    {
        int dlugosc;
        dlugosc=linijka.length();
        if(linijka.compare(dlugosc-3, 3, "set")!=0)
        {
            for(int i=0; i<dlugosc-2; i++)
            {
                linijka[i]=linijka[i+2];
            }
            linijka[dlugosc-2]=NULL;
            linijka[dlugosc-1]=NULL;
            moduly_jadra<<linijka<<endl;
        }
    }
}
