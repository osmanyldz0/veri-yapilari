/**
* @file yigit.h
* @description yigit sinifinin header dosyasi
* @course 1-B
* @assignment 2
* @date 23.12.2023 son duzenlenme tarihi
* @author osman yildiz osman.yildiz2@ogr.sakarya.edu.tr
*/
#ifndef YIGIT_H
#define YIGIT_H

class Yigit {
public:
    int* data;
    int top;
    int kapasite;

    Yigit(int initialCapacity = 10);
    ~Yigit();

    bool isEmpty() const;
    bool isFull() const;
    void push(int value);
    int topValue() const;
    int pop();
};

#endif // YIGIT_H
