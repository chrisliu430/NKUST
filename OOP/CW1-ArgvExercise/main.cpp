/*
Date: 20190917
Course Name: Object-oriented Programming
Exercise Contents: Using Command Line to enter assign command for specific decode/encode and assign decode/encode bit
*/
#include <iostream>
#include <cstring>
#include <fstream>
//#include <stdio.h>

using namespace std;

int main(int argc,char *argv[]){
    char char_ascii,ascii_num,kb_ipt;
    int status = 0;
    if (argc == 2){
        if (strcmp(argv[1],"--help") == 0){
            printf("\nUSAGA: 0917_exercise [options] <inputs> <outputs>\n\n");
            printf("OPTIONS:\n\t-decode\t\tDecode input data to output file\n");
            printf("\t-encode\t\tEncode input data to output file\n");
            printf("\t--help\t\tSearch command\n");
        }else{
            printf("Command Error\n");
        }
    }else if (argc == 5){
        ifstream fin(argv[2]);
        ofstream fout(argv[3]);
        if (strcmp(argv[1],"-encode") == 0){
            if (!fin){
                printf("Cant open file.\n");
            }else{
                while(!fin.eof()){
                    if (status){
                        fout << endl;
                    }
                    status = 1;
                    fin >> char_ascii;
                    ascii_num = char_ascii + atoi(argv[4]);
                    fout << ascii_num;
                    fin.get(char_ascii);
                }
            }
        }else if (strcmp(argv[1],"-decode") == 0){
            if (!fin){
                printf("Cant open file.\n");
            }else{
                while(!fin.eof()){
                    if (status){
                        fout << endl;
                    }
                    status = 1;
                    fin >> ascii_num;
                    char_ascii = ascii_num - atoi(argv[4]);
                    fout << char_ascii;
                    fin.get(char_ascii);
                }
            }
        }else{
            printf("Command Error\n");
        }
    }else{
        printf("Command Error\n");
    }
    return 0;
}