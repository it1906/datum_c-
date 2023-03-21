#ifndef DATUM_DATUM_H
#define DATUM_DATUM_H


class datum {
public:
    //Deklarace konstruktoru a destruktoru
    datum();
    datum(int, int , int);
    datum(const datum& orig);
    virtual ~datum();

    //Deklarace int funkci pro ziskani dne, mesice, roku
    int getDen()const;
    int getMesic()const;
    int getRok()const;

    //bool funkce pro nastaveni data
    bool setDen(int);
    bool setMesic(int);
    bool setRok(int);
    bool setDatum(int, int, int);

    //funkce pro praci se dny
    int denVTydnu()const;
    int pocetOd()const;

private:
    //privatni promenne
    int den;
    int mesic;
    int rok;
    int pocetDni(int, int)const;

    //privatni funkce pro praci s datem
    bool prestupnyRok(int)const;
    bool platnost(int, int, int)const;

    //funkce pro nastaveni systemoveho data jakozto vychoziho
    void sysDatum();
};


#endif //DATUM_DATUM_H
