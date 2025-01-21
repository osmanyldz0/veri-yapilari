/**
* @file avl.h
* @description avl sinifinin header dosyasi
* @course 1-B
* @assignment 2
* @date 23.12.2023 son duzenlenme tarihi
* @author osman yildiz osman.yildiz2@ogr.sakarya.edu.tr
*/
#ifndef AVL_H
#define AVL_H

#include "dugum.h"
#include "yigit.h"

class Avl {
public:
    Dugum* Kok;
    Yigit* yigit;

    int Asci;
    int agacsayi;

    Avl(Dugum* Kok = nullptr, Yigit* yigit = nullptr, int Asci = 0, int agacsayi = 0);

    bool varmi(Dugum* aktif, int aranan);
    bool varmi(int veri);

    int yukseklik(Dugum* aktifDugum);

    Dugum* solaDondur(Dugum* buyukEbeveyn);
    Dugum* sagaDondur(Dugum* buyukEbeveyn);

    Dugum* ekle(int veri, Dugum* aktifDugum);
    void ekle(int veri);
    void ekleEgerYoksa(int veri);

    void tumDugumleriSil(Dugum* aktifDugum);
    int toplaYaprakOlmayanDugumler(Dugum* aktifDugum);
    int toplaYaprakOlmayanDugumler();
    int asciBul(Avl* avl);
    void yapraklariYiginaEkle(Dugum* aktifDugum, Avl* avl);
};

#endif // AVL_H
