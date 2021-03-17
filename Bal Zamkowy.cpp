#include "Funkcje.h"
#include "Dialogi.h"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void kontynuuj();

int main()
{
    
    int kont = 0;

    cout << "Chcesz kontynuowac gre(1) czy rozpoczac nowa(2)?" << endl;
    cin >> kont;
    if (kont == 2)
    {
        string imie;
        float pkt = 0;
        float Wyniki[4][2];

        Zapis(pkt);

        KwestiaDialogowa(0, "miejsca.txt", " ");
        imie = Straznik(pkt);
        Wyniki[0][0] = 1;
        Wyniki[0][1] = pkt;
        system("pause");
        system("cls");

        konferansjer(imie);
        Wyniki[1][0] = 2;
        Wyniki[1][1] = pkt;
        system("pause");
        system("cls");

        poncz(pkt, imie,Wyniki);
        Wyniki[2][0] = 3;
        Wyniki[2][1] = pkt;
        system("pause");
        system("cls");

        szlachcianka(pkt, imie);
        Wyniki[3][0] = 4;
        Wyniki[3][1] = pkt;
        system("pause");
        system("cls");

        //matka(imie, pkt);

        endGame(pkt, Wyniki);
    }
    else
    {
        kontynuuj();
    }
}

void kontynuuj()
{
    float pkt = 0;
    float Wyniki[4][2];
    string imie;
    int postep;

    cout<< "Straznik: Chyba juz cie tu widzialem. Kim jestes? (podaj imie)" << endl;
    cin >> imie;

    cout << "Z kim ostatnim rozmawiałes? 1.Straznik 2.Komferansjer  3.Szlachcianka " << endl;
    cin >> postep;

    pkt = WczytajPkt();

    switch (postep)
    {
    case 1:
        Wyniki[0][0] = 1;
        Wyniki[0][1] = pkt;

        konferansjer(imie);
        Wyniki[1][0] = 2;
        Wyniki[1][1] = pkt;
        system("pause");
        system("cls");

        poncz(pkt, imie, Wyniki);
        Wyniki[2][0] = 3;
        Wyniki[2][1] = pkt;
        system("pause");
        system("cls");

        szlachcianka(pkt, imie);
        Wyniki[3][0] = 4;
        Wyniki[3][1] = pkt;
        system("pause");
        system("cls");

        endGame(pkt, Wyniki);
        break;

    case 2:
        Wyniki[0][0] = 1;
        Wyniki[0][1] = pkt;
        Wyniki[1][0] = 2;
        Wyniki[1][1] = pkt;

        poncz(pkt, imie, Wyniki);
        Wyniki[2][0] = 3;
        Wyniki[2][1] = pkt;
        system("pause");
        system("cls");

        szlachcianka(pkt, imie);
        Wyniki[3][0] = 4;
        Wyniki[3][1] = pkt;
        system("pause");
        system("cls");

        endGame(pkt, Wyniki);
        break;

    case 3:
        Wyniki[0][0] = 1;
        Wyniki[0][1] = pkt;
        Wyniki[1][0] = 2;
        Wyniki[1][1] = pkt;
        Wyniki[2][0] = 3;
        Wyniki[2][1] = pkt;
        Wyniki[3][0] = 4;
        Wyniki[3][1] = pkt;

        endGame(pkt, Wyniki);
        break;

   /* case '4':

        break;

    case'5':

        break;

    case '6':

        break;

    default:

         break;*/
    }
}