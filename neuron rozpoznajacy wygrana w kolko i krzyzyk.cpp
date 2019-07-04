// AUTORZY : M. Widzyk, M. Ostrowski
// Wykonanie: 06.01.2018
// Dotyczy: Neuron ucz¹cy, który rozpoznaje wygran¹ w kó³ko i krzy¿yk


#include <iostream>
#include <cstdlib>
#include <time.h>
#include <math.h>



using namespace std;

// #define N 8 // deklaracja liczby ci¹gów ucz¹cych


//Program realizuj¹cy pojedynczy neuron
//Na wejœciu neuronu beda podawane  liczby

//definicja neuronu
class Neuron{

protected:
	double x[9]; //wejscia
	double w[9]; //wagi



public:
    int procent=0; //tutaj przechowuje wartosc procentowa na ile % taka sytuacja bedzie wygrana (1) lub przegrana (0)
    int yy=0; //tutaj przechowuje wartosc zaokraglona y
    int N=8; // liczba ci¹gów ucz¹cych



   //wyswietlanie wag (sprawdzanie dzialania programu - domyslnie zakomentowane
    void wysw_wagi(){
         cout<<w[0]<<" |";
         for (int i=1;i<9;i++) cout<<"\t"<<w[i];
         }



    //blok inicjalizacyjny zwiazany z randomowymi wagami
	void inicjalizacja(){
	    srand(time(0));

		  x[0]=1, x[1]=0, x[2]=0, x[3]=0, x[4]=0, x[5]=0, x[6]=0, x[7]=0, x[8]=0,  x[9]=0; //domyslnie na wyjsciu jest 0
		  
		  	  
  		  w[0]=(rand()%1000)/1000.0; //ustawienie wag na RANDomowe
  		  w[1]=(rand()%1000)/1000.0; //ustawienie wag na RANDomowe
  		  w[2]=(rand()%1000)/1000.0; //ustawienie wag na RANDomowe
  		  w[3]=(rand()%1000)/1000.0; //ustawienie wag na RANDomowe
  		  w[4]=(rand()%1000)/1000.0; //ustawienie wag na RANDomowe
	      w[5]=(rand()%1000)/1000.0; //ustawienie wag na RANDomowe
 		  w[6]=(rand()%1000)/1000.0; //ustawienie wag na RANDomowe
  	  	  w[7]=(rand()%1000)/1000.0; //ustawienie wag na RANDomowe
  		  w[8]=(rand()%1000)/1000.0; //ustawienie wag na RANDomowe
  		    		    		    		    		    		    		    		    		  
	}



	//blok sumujacy
	double suma (int liczby[9]){
		int Z=0;
		x[0]=1;
		for (int i=1;i<9;i++)  x[i]=liczby[i]; //zapêtlone, ogranicza linie kodu
		
		
		for (int i=0;i<9;i++)  Z+=(x[i]*w[i]);//zapêtlone, ogranicza linie kodu
		
		
		return Z;
	}


	//wykonywanie bloku sumujacego, a nastepnie bloku aktywacji
	double aktywacja(int liczby[9]){
		double y, Z=0;
		x[0]=1;
		for (int i=1;i<9;i++)  x[i]=liczby[i];
		for (int i=0;i<9;i++)  Z+=(x[i]*w[i]);
		y=1.0/(1.0+exp(-1.0*Z));
	
	
		if (y>=0.5) {
            procent=100*y;
            yy=1;
		}
		else if (y<0.5) {
            procent=100-y;
            yy=0;
		}
		return y;
	}

	//blok uczacy
	void nauka(int xxxx[9], int yyyy){
	    double wynik=0;
		wynik=aktywacja(xxxx);
		if (wynik!=yyyy){
           cout<<"zmiana "; //w kazdej linijce, w ktorej wagi zostaly zmienione, na poczatku znajdzie sie napis "Zmiana"  TUTAJ TRZEBA ODKOMENTOWAC, GDY CHCE SIE SPRAWDZIC DIALANIE PROGRAMU
			w[0]=w[0]+0.05*(yyyy-wynik);
			for (int i=1;i<9;i++)  w[i]=w[i]+0.05*x[i]*(yyyy-wynik);
		}
	}
};


// ------------------------------------------------------------------------------------


int main(){
    Neuron proba; //okreslam obiekt klasy

    //definiuje wektory uczace
	int wektor_uczacy[proba.N][10]={
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 1},
    {0, 1, 0, 0, 1, 0, 0, 1, 0, 1},
    {0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 0, 0, 1, 0, 0, 1, 1},
    {1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
    {0, 0, 1, 0, 0, 1, 0, 0, 0, 0}
    };
    
    
// ------------------------------------------------------------------------------------    

    // przekazanie wartosci dla metod
	int Tab[9],y1;
	

	int tablica1[9]={0, 0, 0, 1, 1, 1, 0, 0, 0}; // tablica "tablica1" - neuron pokaze nam na ile % jest pewny wygranej oraz czy jest wygrana/czy jej nie ma
	int tablica2[9]={0, 1, 0, 0, 0, 0, 1, 0, 1}; // tablica "tablica2" - neuron pokaze nam na ile% jest pewny wygranej oraz czy jest wygrana/czy jej nie ma
	int tablica3[9]={0, 1, 0, 0, 1, 0, 0, 1, 0}; // tablica "tablica3" - neuron pokaze nam na ile% jest pewny wygranej oraz czy jest wygrana/czy jej nie ma


	//tutaj nastepuje ustawienie poczatkowych wartosci wag i wejsc
	proba.inicjalizacja();

	//nauka neuronu, zmiana wag i wyswietlenie dzialania
	for (int j=0;j<1000;j++){  // im J jest mniejsze, tym mniejsze prawdopodobienstwo, ze program "rozpozna" czy jest wygrana
        for (int i=0;i<proba.N;i++){
            for (int k=0;k<9;k++) {Tab[k]=wektor_uczacy[i][k];}

            y1=wektor_uczacy[i][9];
    proba.nauka(Tab, y1);
    proba.wysw_wagi(); 				
    proba.aktywacja(Tab);				
    cout<<"   --"<<proba.yy<< "["<<proba.procent<<"%]"<<"\n";		
    }
    }

// ------------------------------------------------------------------------------------

    //sprawdzamy dzia³anie programu (neuronu)
   proba.aktywacja(tablica1);
   cout<<endl<<"-----"<< endl<<proba.yy<<" ("<<proba.procent<<" %)";
    proba.aktywacja(tablica2);
   cout<<endl<<"-----"<<endl <<proba.yy<<" ("<<proba.procent<<" %)";
       proba.aktywacja(tablica3);
   cout<<endl<<"-----"<<endl<<proba.yy<<" ("<<proba.procent<<" %)";
}

