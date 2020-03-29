#include "animal.h"

animalList::animalList(){
    name = "People";
    val = 20;
    total = 1000;
}

animalList::animalList(string in_str){
    name = in_str;
    val = 20;
    total = 1000;
}

animalList::animalList(string in_str,int in_val){
    name = in_str;
    val = in_val;
    total = 1000;
}

animalList::animalList(string in_str,int in_val,int in_total){
    name = in_str;
    val = in_val;
    total = in_total;
}

int animalList::decTotal(int num){
    total -= num;
};

int animalList::setTotal(){
    total = 0;
}

int animalList::incTotal(int num){
    total += num;
}; 

int animalList::getVal(){
    return val;
}

int animalList::getTotal(){
    return total;
}

string animalList::getName(){
    return name;
};