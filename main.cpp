#include <iostream>
#include "datum.h"

using namespace std;

int main() {
    //Definice konstruktoru
    datum d1;
    datum d2(19,12,2004);
    datum d3(d1);

    //Zalozeni lokalnich promennych
    int den;
    int mesic;
    int rok;
    int volba;

    //Vypis do terminalu
    cout<<"Konstruktor c.1:" <<endl;
    cout<<"Dnes je "<<d1.getDen()<<". "<<d1.getMesic()<<". "<<d1.getRok()<<", "<<d1.denVTydnu()<<". den v tydnu."<<endl;
    cout<<"Od 1. 1. 1900 ubehlo "<<d1.pocetOd()<<" dni."<<endl;
    cout<<endl;
    cout<<"Konstruktor c.2:" <<endl;
    cout<<"Dnes je "<<d2.getDen()<<". "<<d2.getMesic()<<". "<<d2.getRok()<<", "<<d2.denVTydnu()<<". den v tydnu."<<endl;
    cout<<"Od 1. 1. 1900 ubehlo "<<d2.pocetOd()<<" dni."<<endl;
    cout<<endl;
    cout<<"Konstruktor c.3:" <<endl;
    cout<<"Dnes je "<<d3.getDen()<<". "<<d3.getMesic()<<". "<<d3.getRok()<<", "<<d3.denVTydnu()<<". den v tydnu."<<endl;
    cout<<"Od 1. 1. 1900 ubehlo "<<d3.pocetOd()<<" dni."<<endl;
    cout<<endl;

    //Cyklus do-while pro uzivatelsky vstup
    do{
        cout<<"Zadejte den: ";
        cin>>den;
        cout<<"Zadejte mesic: ";
        cin>>mesic;
        cout<<"Zadejte rok: ";
        cin>>rok;
        if(d3.setDatum(den, mesic, rok)){
            cout<<d3.getDen()<<". "<<d3.getMesic()<<". "<<d3.getRok()<<endl;
            cout<<"Dni od 1. 1. 1900: "<<d3.pocetOd()<<endl;
            cout<<"Poradove cislo dne v tydnu: "<<d3.denVTydnu()<<endl;
        }
        else{
            cout<<"Neplatne datum"<<endl;
            cout<<"Chcete pokracovat? 1 = ANO/2 = NE";
            cin>>volba;
        }
    } while(volba==1);
    return 0;
}
