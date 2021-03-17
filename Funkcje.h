#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

void Zapis(float pkt)
{
    ofstream file("zapis.txt");
    file << pkt;
    file.close();
}

void KwestiaDialogowa (int nr, string fname, string cname)
{
    ifstream file(fname);
    string line;

    for (int i = 0; i < (nr); ++i)
    {
        getline(file, line);
    }
    getline(file, line);

    cout<<endl << cname << line << endl;
    file.close();
}

void ZmienPunkty (float* obecne, float dodatkowe)
{
    float tmp;
    *obecne += dodatkowe;
    tmp = *obecne;
    Zapis(tmp);
}

float WczytajPkt()
{
    float pkt=0;

    std::ifstream plik;
    plik.open("zapis.txt");
    plik >> pkt;
    plik.close();

    return pkt;
}

void wyswietlT(float T[4][2])
{
    cout.width(1);
    cout << "Numer rozmowy: ";
    for (int i = 0; i < 4; i++)
    {
        cout.width(2);
        cout << T[i][0];
    }
    cout.width(1);
    cout << endl << "Iloœæ punktow: ";
    for (int i = 0; i < 4; i++)
    {
        cout.width(2);
        cout << T[i][1];
    }

}

void endGame(float pkt, float T[4][2])
{
    string fname = "endGame.txt";

    if (pkt > 1)
    {
        KwestiaDialogowa(0, fname, " ");
        KwestiaDialogowa(1, fname, "Straznik");
        KwestiaDialogowa(2, fname, " ");
        KwestiaDialogowa(3, fname, " ");
        KwestiaDialogowa(4, fname, " ");
        wyswietlT(T);
    }
    else if (pkt < -100)
    {
        KwestiaDialogowa(6, fname, " ");
    }
    else
    {
        KwestiaDialogowa(0, fname, " ");
        KwestiaDialogowa(1, fname, "Straznik");
        KwestiaDialogowa(5, fname, " ");
        KwestiaDialogowa(6, fname, " ");
        wyswietlT(T);
    }
    exit(0);
}

void pij(float pkt, int ilosc, float T[4][2])
{
    string fname = "poncz.txt";
    int tmp = 0;

    
    
    if (ilosc <= 3)
    {
        KwestiaDialogowa(1, fname, "");

        KwestiaDialogowa(4, fname, "");
        KwestiaDialogowa(5, fname, "");
        KwestiaDialogowa(6, fname, "");
        cin >> tmp;
        if (tmp != 2)
        {
            ilosc += 1;
            ZmienPunkty(&pkt, 1);
            pij(pkt, ilosc,T);
        }
     
    }
    else if (ilosc > 8)
    {
        KwestiaDialogowa(1, fname, "");
        KwestiaDialogowa(2, fname, " ");
        KwestiaDialogowa(3, fname, " ");
        pkt = -1000000000; 
        endGame(pkt,T);
    }
    else
    {
        KwestiaDialogowa(1, fname, "");
        KwestiaDialogowa(2, fname, " ");

        KwestiaDialogowa(4, fname, "");
        KwestiaDialogowa(5, fname, "");
        KwestiaDialogowa(6, fname, "");
        cin >> tmp;
        if (tmp != 2)
        {
            ilosc += 1;
            ZmienPunkty(&pkt, -1);
            pij(pkt, ilosc,T);
        }    
    }

}


