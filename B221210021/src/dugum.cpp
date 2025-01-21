/**
* @file dugum.cpp
* @description avl agacinin dugumleri olusturuldu agacin elemanlari uzerinde buradan gezilir
* @course 1-B
* @assignment 2
* @date 23.12.2023 son duzenlenme tarihi
* @author osman yildiz osman.yildiz2@ogr.sakarya.edu.tr
*/
#include "dugum.h"

Dugum::Dugum(int veri, int yukseklik, Dugum* left, Dugum* right) {
    this->left = left;
    this->right = right;
    this->veri = veri;
    this->yukseklik = yukseklik;
}
