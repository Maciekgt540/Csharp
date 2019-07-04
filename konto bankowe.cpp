#include <stdlib.h>
#include<iostream>
/*
 * 
 */

class Osoba{
protected:
    std::string imie, nazwisko;
    int rokUrodzenia;
    Osoba(std::string imie, std::string nazwisko, int rok){
        this->imie=imie;
        this->nazwisko=nazwisko;
        rokUrodzenia=rok;
    }

};

/*class KontoBankowe{
    Osoba wlasciciel;

};*/

class KontoBankowe2: public Osoba{
protected:
    std::string nrKonta;
    double stanKonta,limitDebetu;
public:

    KontoBankowe2(std::string imie, std::string nazwisko, std::string nrKonta, double stanKonta, double limitDebetu):Osoba(imie,nazwisko,1980){
        this->imie=imie;
        this->nazwisko=nazwisko;
        this->nrKonta=nrKonta;
        this->stanKonta=stanKonta;
        this->limitDebetu=limitDebetu;
        rokUrodzenia=1980;
    }


    double wplata(double wpl){
        stanKonta+=wpl;
    }

    double wyplata(double wyp){
        if(wyp<stanKonta+limitDebetu){
            stanKonta-=wyp;
           return wyp;
        }
        else{
            //return 0;
            double tym;
            tym=stanKonta+limitDebetu;
            stanKonta=-limitDebetu;
            return tym;
        }
    }

/*     int wyplata(double wyp){
                 if(wyp<stanKonta+limitDebetu){
                     stanKonta-=wyp;
                     return 0;
                 }
                 else
                 {
                     return -1;
                 }
    }*/

     double dostepneSrodki(){
         return stanKonta+limitDebetu;
     }

};



int main(int argc, char** argv) {

    double tym1;
    KontoBankowe2 kb1("Rafal","Skowronski","122323434234234234v24",10000,5000);

    std::cout<<" Dostepne srodki"<<kb1.dostepneSrodki()<<"\n";

    tym1=kb1.wyplata(3000);
std::cout<<"Wyplata"<<tym1<<" Dostepne srodki"<<kb1.dostepneSrodki()<<"\n";
  tym1=kb1.wplata(16000);

std::cout<<"Wyplata"<<tym1<<" Dostepne srodki"<<kb1.dostepneSrodki()<<"\n";
}
