/**
* @file test.cpp
* @description istenen cikti alinacak sekilde fonksiyonlar kullanildi
* @course 1-B
* @assignment 2
* @date 23.12.2023 son duzenlenme tarihi
* @author osman yildiz osman.yildiz2@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <fstream>
#include <sstream>   
#include "avl.h"     
#include "avldugum.h"

using namespace std;




int main() {
	AvlDugum::LinkedList avlList;

	ifstream dosya("Veri.txt");
	if (!dosya) {
		cout << "Dosya bulunamadi." << endl;
		return 1;
	}





	int avlSayisi = 1;
	string satir;
	while (getline(dosya, satir)) {
		istringstream iss(satir);
		int sayi;
		Avl* avlAgaci = new Avl();

		avlAgaci->yigit = new Yigit();

		while (iss >> sayi) {
			avlAgaci->ekleEgerYoksa(sayi);


		}

		avlAgaci->yapraklariYiginaEkle(avlAgaci->Kok, avlAgaci);
		avlList.addTreeAtIndex(avlAgaci, avlSayisi);
		avlAgaci->asciBul(avlAgaci);

		avlSayisi++;
		avlList.sayi = avlSayisi;
	}




	dosya.close();







	int kontrol = 0;


	while (avlList.head->next ) 
	{



		AvlDugum* enKucuk = avlList.karsilastirkucukYigitlar(avlList.head, avlList.head->next);

		avlList.yigitsonelemanSil(enKucuk);
		int x;
		

		x = enKucuk->avlTree->yigit->isEmpty();
		avlList.agacCikar(enKucuk, avlList);
	
		 
		if (x==0)
		{




			AvlDugum* enBuyuk = avlList.karsilastirBuyukYigitlar(avlList.head, avlList.head->next);
			avlList.yigitsonelemanSil(enBuyuk);
			avlList.agacCikar(enBuyuk, avlList);


		}

	


	}
	system("cls");
	int asci = 0;
	asci = avlList.head->avlTree->Asci;
	char asciiKarakter = static_cast<char>(asci);
	

	cout << endl;
	cout << "    ============================== " << endl << "    |                            "  << "|" << endl << "    |             " << asciiKarakter << " " << avlList.head->avlTree->agacsayi << "          |" << endl << "    |                            " << "|" << endl << "    |                            " << "|" << endl << "    |                            " << "|" << endl << "    |                            " << "|" << endl << "    ============================== ";
	 

	return 0;
}

