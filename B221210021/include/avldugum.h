/**
* @file avldugum.h
* @description avldugum sinifinin header dosyasi
* @course 1-B
* @assignment 2
* @date 23.12.2023 son duzenlenme tarihi
* @author osman yildiz osman.yildiz2@ogr.sakarya.edu.tr
*/
#ifndef AVLDUGUM_H
#define AVLDUGUM_H

#include "avl.h"

class AvlDugum {
public:
    Avl* avlTree;
    AvlDugum* next;

    AvlDugum(Avl* avlTree = nullptr, AvlDugum* next = nullptr);

    class LinkedList {
    public:
        AvlDugum* head;
        int sayi;

        LinkedList(AvlDugum* head = nullptr, int sayi = 0);
        AvlDugum* karsilastirBuyukYigitlar(AvlDugum* avl1, AvlDugum* avl2);
        AvlDugum* buyukKarsilastirYigitlar(AvlDugum* enBuyuk, AvlDugum* current);
        AvlDugum* karsilastirkucukYigitlar(AvlDugum* avl1, AvlDugum* avl2);
        AvlDugum* kucukKarsilastirYigitlar(AvlDugum* enKucuk, AvlDugum* current);

        void agacCikar(AvlDugum* avl, LinkedList avlList);
        void yigitsonelemanSil(AvlDugum* avl);
        void addTreeAtIndex(Avl* tree, int index);
        void printTrees();
        void removeTreeAtIndex(Avl* avl);
        void YapraklariGeriEkle(AvlDugum* avlList);
        int toplaYaprakOlmayanDugumler(int index);
        void removeTreeFromList(Avl* avl, LinkedList& avlList);
    };
};

#endif // AVLDUGUM_H
