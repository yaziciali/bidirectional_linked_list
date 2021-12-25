/**
* @file main.cpp
* @description Uygulama çift yönlü bir bağıl liste oluşturur. Veri.txt dosyasını okur.
*              Satırlar ekleme için "E(2#Mehmet Can)" formatında ve silme için "S(3) formatında olmalıdır.
*              Satır başı E ile başlıyor ise ( ile # arasındaki indeks numarasını alır.
*               # ile ) harfleri arasındaki texti okur. Verilen indekse göre bağıl listeye texti ekler.
*               Satır başı S ile başlıyorsa ( ve ) harfleri arasındaki indeks numarasını alarak. 
*               İlgili indeksi bağıl listeden siler. Satırlar bitince listeyi ekranda gösterir.
* @course BSM 207 - Veri Yapıları - 1. Öğretim A grubu
* @assignment 1
* @date 08.11.2021
* @author Ali YAZICI ali.yazici3@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <fstream>
#include <string>

#include "linkedList2.hpp"
#define FILENAME "Veri.txt"
using namespace std;

int main(int argc, char const *argv[])
{
    LinkedList2 list1;
    string line;
    ifstream dataFile(FILENAME);
    int lineNumber = 1 ;
    int insertIndex = 0 ;
    int delIndex = 0 ;
    string newitem = "";

    while (getline(dataFile, line))
    {
        switch (line[0]){
        case 'E':
            insertIndex = stoi(line.substr(2,  line.find('#') - line.find('(') - 1 ));
            newitem = line.substr(line.find('#')+1, line.find(')') - line.find('#') - 1 );
            list1.addItem(newitem,insertIndex);
            break;

        case 'S':
            delIndex = stoi(line.substr(2,line.find(')') -  line.find('(')  - 1));
            list1.remove(delIndex);
            break;
        default:
            cout << "Error in line: " << lineNumber << endl;
            break;
        }
        lineNumber++;
    }




    cout << list1 ;

    return 0;
}
