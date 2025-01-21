/**
* @file avldugum.cpp
* @description avl sinifidugumleri olusturuldu agaclar uzerinde gezinme islemleri buradan yapilir
* @course 1-B
* @assignment 2
* @date 23.12.2023 son duzenlenme tarihi
* @author osman yildiz osman.yildiz2@ogr.sakarya.edu.tr
*/

#include "avldugum.h"
#include <iostream>
using namespace std;

AvlDugum::AvlDugum(Avl* avlTree, AvlDugum* next) {
    this->avlTree = avlTree;
    this->next = next;
}

AvlDugum::LinkedList::LinkedList(AvlDugum* head, int sayi) {
    this->head = head;
    this->sayi = sayi;
}

AvlDugum* AvlDugum::LinkedList::karsilastirBuyukYigitlar(AvlDugum* avl1, AvlDugum* avl2) {
    if (avl1 == nullptr || avl2 == nullptr) {
        cout << "Geçersiz AVL düğümü." << std::endl;
        return nullptr;
    }

    return buyukKarsilastirYigitlar(avl1, avl2);
}

AvlDugum* AvlDugum::LinkedList::buyukKarsilastirYigitlar(AvlDugum* enBuyuk, AvlDugum* current) {
    if (current == nullptr) {
        return enBuyuk;
    }

    if (enBuyuk == nullptr || current->avlTree->yigit->topValue() > enBuyuk->avlTree->yigit->topValue()) {
        enBuyuk = current;
    }
    else if (enBuyuk == nullptr || current->avlTree->yigit->topValue() == enBuyuk->avlTree->yigit->topValue()) {
        if (current->avlTree->agacsayi > enBuyuk->avlTree->agacsayi) {
            enBuyuk = enBuyuk;
        }
        else if (current->avlTree->agacsayi < enBuyuk->avlTree->agacsayi) {
            enBuyuk = current;
        }
    }

    else if (enBuyuk == nullptr || current->avlTree->yigit->topValue() < enBuyuk->avlTree->yigit->topValue()) {
        enBuyuk = enBuyuk;
    }

    return buyukKarsilastirYigitlar(enBuyuk, current->next);
}

AvlDugum* AvlDugum::LinkedList::karsilastirkucukYigitlar(AvlDugum* avl1, AvlDugum* avl2) {
    if (avl1 == nullptr || avl2 == nullptr) {
        cout << "Geçersiz AVL düğümü." << std::endl;
        return nullptr;
    }

    return kucukKarsilastirYigitlar(avl1, avl2);
}

AvlDugum* AvlDugum::LinkedList::kucukKarsilastirYigitlar(AvlDugum* enKucuk, AvlDugum* current) {
    if (current == nullptr) {
        return enKucuk;
    }

    if (enKucuk == nullptr || current->avlTree->yigit->topValue() < enKucuk->avlTree->yigit->topValue()) {
        enKucuk = current;
    }
    else if (enKucuk == nullptr || current->avlTree->yigit->topValue() == enKucuk->avlTree->yigit->topValue()) {
        if (current->avlTree->agacsayi > enKucuk->avlTree->agacsayi) {
            enKucuk = enKucuk;
        }
        else if (current->avlTree->agacsayi < enKucuk->avlTree->agacsayi) {
            enKucuk = current;
        }
    }

    else if (enKucuk == nullptr || current->avlTree->yigit->topValue() > enKucuk->avlTree->yigit->topValue()) {
        enKucuk = enKucuk;
    }

    return kucukKarsilastirYigitlar(enKucuk, current->next);
}

void AvlDugum::LinkedList::agacCikar(AvlDugum* avl, LinkedList avlList) {
    if (avl->avlTree->yigit->isEmpty()) {
        if (avlList.head->avlTree == avl->avlTree) {
            avlList.head = avlList.head->next;
        }

        system("cls");

        printTrees();

        removeTreeAtIndex(avl->avlTree);

        AvlDugum* a;
        a = avlList.head;
        while (a) {
            while (a->avlTree->yigit->isEmpty() == 0) {
                a->avlTree->yigit->pop();
            }
            a->avlTree->yapraklariYiginaEkle(a->avlTree->Kok, a->avlTree);

            a = a->next;
        }
    }
}

void AvlDugum::LinkedList::yigitsonelemanSil(AvlDugum* avl) {
    avl->avlTree->yigit->pop();
}

void AvlDugum::LinkedList::addTreeAtIndex(Avl* tree, int index) {
    if (index < 0) {
        cout << "Geçersiz indeks." << std::endl;
        return;
    }

    AvlDugum* newNode = new AvlDugum(tree);

    if (index == 0 || head == nullptr) {
        newNode->next = head;
        head = newNode;
    }
    else {
        AvlDugum* current = head;
        AvlDugum* prev = nullptr;
        int currentIndex = 0;

        while (current != nullptr && currentIndex < index) {
            prev = current;
            current = current->next;
            currentIndex++;
        }

        newNode->next = current;
        prev->next = newNode;
    }
    tree->agacsayi = index;
}

void AvlDugum::LinkedList::printTrees() {
    AvlDugum* current = head;
    while (current != nullptr) {
        int asci = 0;
        asci = current->avlTree->Asci;
        char asciiKarakter = static_cast<char>(asci);
        std::cout << asciiKarakter;
        current = current->next;
    }
}

void AvlDugum::LinkedList::removeTreeAtIndex(Avl* avl) {
    AvlDugum* current = head;
    AvlDugum* prev = nullptr;

    while (current != nullptr && current->avlTree != avl) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Belirtilen indeks bulunamadi." << std::endl;
        return;
    }

    if (prev == nullptr) {
        head = current->next;
    }
    else {
        prev->next = current->next;
    }

    delete current->avlTree;
    delete current;
}

void AvlDugum::LinkedList::YapraklariGeriEkle(AvlDugum* avlList) {
    AvlDugum* d = new AvlDugum();
    d = avlList;

    while (d) {
        d->avlTree->yapraklariYiginaEkle(d->avlTree->Kok, d->avlTree);
        d = d->next;
    }
}

int AvlDugum::LinkedList::toplaYaprakOlmayanDugumler(int index) {
    if (index < 0) {
        cout << "Geçersiz indeks." << std::endl;
        return 0;
    }

    AvlDugum* current = head;
    int currentIndex = 0;

    while (current != nullptr && currentIndex < index) {
        current = current->next;
        currentIndex++;
    }

    if (current == nullptr) {
        cout << "Belirtilen indeks bulunamadi." << std::endl;
        return 0;
    }

    return current->avlTree->toplaYaprakOlmayanDugumler();
}

void AvlDugum::LinkedList::removeTreeFromList(Avl* avl, LinkedList& avlList) {
    AvlDugum* current = avlList.head;
    AvlDugum* prev = nullptr;

    while (current != nullptr && current->avlTree != avl) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Belirtilen AVL agaci bulunamadi." << std::endl;
        return;
    }

    if (prev == nullptr) {
        avlList.head = current->next;
    }
    else {
        prev->next = current->next;
    }

    delete current->avlTree;
    delete current;
}
