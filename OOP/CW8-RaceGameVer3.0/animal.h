#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>
using namespace std;
class animalList{
    public:
        animalList();
        animalList(string);
        animalList(string,int);
        animalList(string,int,int);
        int decTotal(int);
        int setTotal();
        int incTotal(int);
        int getTotal();
        int getVal();
        string getName();
    private:
        string name;
        int val,total;
};
#endif