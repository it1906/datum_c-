#include "datum.h"
#include <ctime>
#define MIN 1900
#define MAX 2023

datum::datum() {
    sysDatum();
}
datum::datum(int den, int mesic, int rok) {
    if(platnost(den, mesic, rok)){
        this->den=den;
        this->mesic=mesic;
        this->rok=rok;
    }
    else{
        sysDatum();
    }
}
datum::datum(const datum &orig) {
    this->den = orig.getDen();
    this->mesic = orig.getMesic();
    this->rok = orig.getRok();

}
datum::~datum() {}

void datum::sysDatum() {
    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    this->den = timeinfo->tm_mday;
    this->mesic=timeinfo->tm_mon+1;
    this->rok=timeinfo->tm_year+1900;
    return;
}

int datum::getDen() const {
    return this->den;
}

int datum::getMesic() const {
    return this->mesic;
}

int datum::getRok() const {
    return this->rok;
}

bool datum::prestupnyRok(int rok) const {
    if((rok%4==0) && (rok%100!=0) || (rok%400==0)){
        return true;
    }
    else{
        return false;
    }
}

int datum::pocetDni(int mesic, int rok) const {
    int dny [] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(mesic==2 && prestupnyRok(rok)){
        return dny[1]+1;
    }
    return dny[mesic-1];

}

bool datum::platnost(int den, int mesic, int rok) const {
    if(rok<MIN || rok > MAX){
        return false;
    }
    if(mesic<1 || mesic > 12){
        return false;
    }
    if(den<1 || den > pocetDni(mesic, rok)){
        return false;
    }
    return true;
}

int datum::pocetOd() const {
    int dny = 0;
    for (int i = MIN; i < this->rok; ++i) {
        dny += prestupnyRok(i) ? 366:365;
    }
    for(int i =1; i < this->mesic; i++){
        dny+= pocetDni(i, this->rok);
    }
    dny+=this->den-1;
    return dny;
}

int datum::denVTydnu() const {
    return pocetOd()%7+1;
}

//jednotlive funkce pro nastaveni dne, mesice, roku...nepouzivane
bool datum::setDen(int d) {
    if(platnost(d, this->mesic, this->rok)){
        this->den=d;
        return true;
    }
    else{
        return false;
    }
}

bool datum::setMesic(int m) {
    if(platnost(this->den, m, this->rok)){
        this->mesic=m;
        return true;
    }
    else{
        return false;
    }
}

bool datum::setRok(int r) {
    if(platnost(this->den, this->mesic, r)){
        this->rok=r;
        return true;
    }
    else{
        return false;
    }
}

//nastaveni celeho data, vyvolani v mainu
bool datum::setDatum(int d, int m, int r) {
    if(platnost(d, m, r)){
        this->den=d;
        this->mesic=m;
        this->rok=r;
        return true;
    }
    else{
        return false;
    }
}