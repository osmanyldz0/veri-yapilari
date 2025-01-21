/**
* @file avl.cpp
* @description avl sinifi olusturuldu agaclar burada tutulur
* @course 1-B
* @assignment 2
* @date 23.12.2023 son duzenlenme tarihi
* @author osman yildiz osman.yildiz2@ogr.sakarya.edu.tr
*/

#include "avl.h"
#include <iostream>
#include <algorithm>
using namespace std;
Avl::Avl(Dugum* Kok, Yigit* yigit, int Asci, int agacsayi) {
	this->Kok = Kok;
	this->yigit = new Yigit();
	this->Asci = Asci;
	this->agacsayi = agacsayi;
}

bool Avl::varmi(Dugum* aktif, int aranan) {
	if (aktif == nullptr) {
		return false;
	}
	else if (aktif->veri < aranan) {
		return varmi(aktif->right, aranan);
	}
	else if (aktif->veri > aranan) {
		return varmi(aktif->left, aranan);
	}
	else {
		return true;
	}
}

bool Avl::varmi(int veri) {
	return varmi(Kok, veri);
}

int Avl::yukseklik(Dugum* aktifDugum) {
	if (aktifDugum) {
		return 1 + max(yukseklik(aktifDugum->left), yukseklik(aktifDugum->right));
	}
	return -1;
}

Dugum* Avl::solaDondur(Dugum* buyukEbeveyn) {
	Dugum* sagCocuk = buyukEbeveyn->right;
	buyukEbeveyn->right = sagCocuk->left;
	sagCocuk->left = buyukEbeveyn;

	buyukEbeveyn->yukseklik = yukseklik(buyukEbeveyn);
	sagCocuk->yukseklik = 1 + max(yukseklik(sagCocuk->right), buyukEbeveyn->yukseklik);

	return sagCocuk;
}

Dugum* Avl::sagaDondur(Dugum* buyukEbeveyn) {
	Dugum* solCocuk = buyukEbeveyn->left;
	buyukEbeveyn->left = solCocuk->right;
	solCocuk->right = buyukEbeveyn;
	buyukEbeveyn->yukseklik = yukseklik(buyukEbeveyn);
	solCocuk->yukseklik = 1 + max(yukseklik(solCocuk->left), buyukEbeveyn->yukseklik);
	return solCocuk;
}

Dugum* Avl::ekle(int veri, Dugum* aktifDugum) {
	if (aktifDugum == nullptr)
		return new Dugum(veri);

	if (veri < aktifDugum->veri) {
		aktifDugum->left = ekle(veri, aktifDugum->left);
		if (yukseklik(aktifDugum->left) - yukseklik(aktifDugum->right) == 2) {
			if (veri < aktifDugum->left->veri)
				aktifDugum = sagaDondur(aktifDugum);
			else {
				aktifDugum->left = solaDondur(aktifDugum->left);
				aktifDugum = sagaDondur(aktifDugum);
			}
		}
	}
	else if (veri > aktifDugum->veri) {
		aktifDugum->right = ekle(veri, aktifDugum->right);
		if (yukseklik(aktifDugum->right) - yukseklik(aktifDugum->left) == 2) {
			if (veri > aktifDugum->right->veri)
				aktifDugum = solaDondur(aktifDugum);
			else {
				aktifDugum->right = sagaDondur(aktifDugum->right);
				aktifDugum = solaDondur(aktifDugum);
			}
		}
	}

	aktifDugum->yukseklik = yukseklik(aktifDugum);
	return aktifDugum;
}

void Avl::ekle(int veri) {
	Kok = ekle(veri, Kok);
}

void Avl::ekleEgerYoksa(int veri) {
	if (!varmi(veri))
		Kok = ekle(veri, Kok);
}

void Avl::tumDugumleriSil(Dugum* aktifDugum) {
	if (aktifDugum != nullptr) {
		tumDugumleriSil(aktifDugum->left);
		tumDugumleriSil(aktifDugum->right);
		delete aktifDugum;
	}
}

int Avl::toplaYaprakOlmayanDugumler(Dugum* aktifDugum) {
	if (aktifDugum == nullptr) {
		return 0;
	}

	int toplam = 0;

	if (aktifDugum->left != nullptr || aktifDugum->right != nullptr) {
		toplam += aktifDugum->veri;
	}

	toplam += toplaYaprakOlmayanDugumler(aktifDugum->left);
	toplam += toplaYaprakOlmayanDugumler(aktifDugum->right);

	return toplam;
}

int Avl::toplaYaprakOlmayanDugumler() {
	return toplaYaprakOlmayanDugumler(Kok);
}

int Avl::asciBul(Avl* avl) {
	int a = 0;
	a = avl->toplaYaprakOlmayanDugumler();
	a = a % (90 - 65 + 1) + 65;

	avl->Asci = a;

	return a;
}

void Avl::yapraklariYiginaEkle(Dugum* aktifDugum, Avl* avl) {
	if (aktifDugum != nullptr) {
		if (aktifDugum->left == nullptr && aktifDugum->right == nullptr) {
			avl->yigit->push(aktifDugum->veri);
		}

		yapraklariYiginaEkle(aktifDugum->left, avl);
		yapraklariYiginaEkle(aktifDugum->right, avl);
	}
}
