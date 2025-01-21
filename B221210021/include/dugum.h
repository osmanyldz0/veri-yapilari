/**
* @file dugum.h
* @description dugum sinifinin header dosyasi
* @course 1-B
* @assignment 2
* @date 23.12.2023 son duzenlenme tarihi
* @author osman yildiz osman.yildiz2@ogr.sakarya.edu.tr
*/
#ifndef DUGUM_H
#define DUGUM_H

class Dugum {
public:
    int veri;
    Dugum* left;
    Dugum* right;
    int yukseklik = 0;

    Dugum(int veri = 0, int yukseklik = 0, Dugum* left = nullptr, Dugum* right = nullptr);
};

#endif // DUGUM_H
