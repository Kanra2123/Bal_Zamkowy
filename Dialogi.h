#include <iostream>
#include <fstream>
#include <string>

using namespace std;


string Straznik(float& pkt)
{
	string npliku = "straznik.txt";
	string npostaci = "Straznik";
	int tmp=0;
	string imie;

	KwestiaDialogowa(0, npliku, npostaci);
	cin.ignore();
	getline(cin, imie);

	do
	{
		KwestiaDialogowa(1, npliku, npostaci);
		KwestiaDialogowa(2, npliku, imie);
		KwestiaDialogowa(3, npliku, imie);
		cin >> tmp;
		switch (tmp)
		{
			case 1:
				KwestiaDialogowa(5, npliku, npostaci);
				break;
			case 2:
				KwestiaDialogowa(4, npliku, npostaci);
				break;
			default:
				cout << "Odpowiedz nie istnieje. Wybierz poprawna odpowiedz" << endl;
				break;
		}
	} while (tmp != 1);

	ZmienPunkty(&pkt, 1);
	return imie;
}

void konferansjer(string name)
{
	int tmp;
	string fnazwa= "konferansjer.txt";

	KwestiaDialogowa(1, "miejsca.txt", " ");
	KwestiaDialogowa(0, fnazwa, name);
	KwestiaDialogowa(1, fnazwa, name);
	cin >> tmp;
	if (tmp == 1)
	{
		KwestiaDialogowa(2, fnazwa, " ");
	}
	else if (tmp == 2)
	{
		KwestiaDialogowa(3, fnazwa, " ");
		cout << "Konferansjer: Wielce szanowny lord "<<name << "! " << endl;
		KwestiaDialogowa(4, fnazwa, " ");
	}
	else
	{
		cout << endl << "Ta odpowiedŸ nie istnieje! Wybierz inn¹" << endl;
	}
}

void poncz(float& pkt, string imie, float T[4][2])
{
	int tmp;
	string fnazwa = "poncz.txt";

	KwestiaDialogowa(0, fnazwa, " ");

	KwestiaDialogowa(4, fnazwa, " ");
	KwestiaDialogowa(5, fnazwa, " ");
	KwestiaDialogowa(6, fnazwa, " ");
	cin >> tmp;

	if (tmp == 1)
	{
		pij(pkt,0,T);
	}
	else if (tmp!= 1 || tmp!=2)
	{
		cout << endl << "Ta odpowiedŸ nie istnieje! Wybierz inn¹" << endl;
	}	
}

void szlachcianka(float& pkt, string imie)
{
	string fname = "szlachcianka.txt";
	int tmp;

	KwestiaDialogowa(0, fname, "");
	KwestiaDialogowa(1, fname, imie);
	KwestiaDialogowa(2, fname, imie);
	cin >> tmp;

	switch (tmp)
	{
	case 1:
		KwestiaDialogowa(3, fname, "");
		break;
	
	case 2:
		KwestiaDialogowa(4, fname, "");
		break;
	}

	KwestiaDialogowa(5, fname, "Szlachcianka");

	KwestiaDialogowa(6, fname, imie);
	KwestiaDialogowa(7, fname, imie);
	cin >> tmp;

	KwestiaDialogowa(8, fname, "");
	KwestiaDialogowa(9, fname, imie);
	KwestiaDialogowa(10, fname, imie);
	KwestiaDialogowa(11, fname, imie);
	cin >> tmp;

	switch (tmp)
	{
	case 1:
		KwestiaDialogowa(12, fname, "Szlachcianka");
		KwestiaDialogowa(13, fname, "");
		ZmienPunkty(&pkt, 4);

		KwestiaDialogowa(14, fname, "Szlachcianka");
		KwestiaDialogowa(15, fname, imie);
		KwestiaDialogowa(16, fname, imie);
		KwestiaDialogowa(17, fname, imie);
		cin >> tmp;

		switch (tmp)
		{
		case 1:
			KwestiaDialogowa(18, fname, "");
			ZmienPunkty(&pkt, 0);
			break;

		case 2:
			KwestiaDialogowa(19, fname, "");
			ZmienPunkty(&pkt, +2);
			break;

		case 3:
			KwestiaDialogowa(20, fname, "");
			ZmienPunkty(&pkt, -1);
			break;
		}
		break;

	case 2:
		KwestiaDialogowa(21, fname, "Szlachcianka");
		KwestiaDialogowa(22, fname, "");
		ZmienPunkty(&pkt, 1);
		break;

	case 3:
		KwestiaDialogowa(23, fname, "Szlachcianka");
		KwestiaDialogowa(24, fname, "");
		ZmienPunkty(&pkt, -(pkt/2));
		break;
	}
}

/*void matka(string name, float& pkt)
{
	string fname = "dziecko.txt";
	int tmp;

	KwestiaDialogowa(0, fname, "");
	KwestiaDialogowa(1, fname, name);
	KwestiaDialogowa(2, fname, name);
	cin >> tmp;

	do 
	{
		switch (tmp)
		{
		case 1:
			KwestiaDialogowa(3, fname, "");
			KwestiaDialogowa(4, fname, "Matka");
			KwestiaDialogowa(5, fname, "Matka");
			ZmienPunkty(&pkt, 1);
			break;

		case 2:
			KwestiaDialogowa(6, fname, "");
			ZmienPunkty(&pkt, -1);
			break;

		default:
			cout << "Taka opcja nie istnieje. Wybierz inna, poprawna opcje" << endl;
		}
	} while (!(tmp == 1 || tmp == 2));

	KwestiaDialogowa(7, fname, "Matka");
	KwestiaDialogowa(8, fname, name);
	KwestiaDialogowa(8, fname, name);
	cin >> tmp;

	do
	{
		switch (tmp)
		{
		case 1:
			KwestiaDialogowa(10, fname, "Matka");
			KwestiaDialogowa(12, fname, "");
			ZmienPunkty(&pkt, 2);
			break;

		case 2:
			KwestiaDialogowa(11, fname, "Matka");
			KwestiaDialogowa(12, fname, "");
			ZmienPunkty(&pkt, -3);
			break;

		default:
			cout << "Taka opcja nie istnieje. Wybierz inna, poprawna opcje" << endl;
		}
	} while (!(tmp == 1 || tmp == 2));
}*/

