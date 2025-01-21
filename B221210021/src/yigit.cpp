/**
* @file yigit.cpp
* @description avl agacinin yapraklarinin saklandigi yigit sinifi olusturuldu
* @course 1-B
* @assignment 2
* @date 23.12.2023 son duzenlenme tarihi
* @author osman yildiz osman.yildiz2@ogr.sakarya.edu.tr
*/
#include "yigit.h"
#include <iostream>
#include <climits>
using namespace std;
Yigit::Yigit(int initialCapacity) {
    if (initialCapacity <= 0) {
        cout << " Geçersiz baþlangýç ??kapasitesi" << std::endl;
        kapasite = 10;
    }
    else {
        kapasite = initialCapacity;
    }
    data = new int[kapasite];
    top = -1;
}

Yigit::~Yigit() {
    delete[] data;
}

bool Yigit::isEmpty() const {
    return top == -1;
}

bool Yigit::isFull() const {
    return top == kapasite - 1;
}

void Yigit::push(int value) {
    if (isFull()) {
        int newKapasite = kapasite * 2;
        int* newData = new int[newKapasite];

        for (int i = 0; i < kapasite; ++i) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        kapasite = newKapasite;
    }
    data[++top] = value;
}

int Yigit::topValue() const {
    if (!isEmpty()) {
        return data[top];
    }
    else {
        cout << "Yigit bos, eleman okunamaz." << std::endl;
        return INT_MIN;
    }
}

int Yigit::pop() {
    if (!isEmpty()) {
        return data[top--];
    }
    else {
        cout << "Yigit bos, eleman cikarilamaz." << std::endl;
        return INT_MIN;
    }
}
