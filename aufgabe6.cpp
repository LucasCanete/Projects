#include <iostream>
#include <vector>
#include <math.h>

/*Von Lucas Canete am 26. April 2020 bearbeitet*/



using namespace std;
vector<double> preise = {0.50,0.60,1.50}; //[0]Mars, [1]Snickers, [2]Rittersport
vector<double> muenzen = {0.01,0.02,0.05,0.1,0.2,0.5,1,2}; //Verfügbare Münzen für die Maschine

void ausgabe (int menge);
void bezahlvorgang(double &rest_preis);
bool eq(double a, double b);
bool isinvektor(double geldstueck);

int main(){

    int produkt;
    int menge;
    double ges_preis;



        cout<<"--- SUESSIGKEITENAUTOMAT ---"<<endl;
        cout<<"Waehlen Sie ein Produkt aus:"<<endl;
        cout<<"1) Mars (0,50 Euro)\n2) Snickers (0,60 Euro)\n3) Rittersport (1,50 Euro)"<<endl;
        cout<<"Geben Sie 1, 2 oder 3 ein:";
        cin>>produkt;
        cout<<"Geben Sie die gewuenschte Menge ein: ";
        cin>>menge;
        ges_preis = (preise[produkt-1]*menge);

        if (menge>0 && produkt >0 && produkt<=3){

            bezahlvorgang(ges_preis);

            ausgabe(menge);


    }


return 0;
}


void bezahlvorgang(double &rest_preis){

    cout<<"--- BEZAHLVORGANG ---"<<endl;

    double mein_geldstueck = 0;

    do {

        cout<<"Es fehlen noch "<<rest_preis<<" Euro."<<endl;
        cout<<"Bitte werfen Sie ein Geldstueck ein: ";
        cin>>mein_geldstueck;
        if(isinvektor(mein_geldstueck)){ //wenn unsere muenze von der maschine aufgenommen werden kann, dann mach weiter
            if(eq(rest_preis,mein_geldstueck)){ // wenn zwei double werte fast gleich sind, dann setzt rest_preis = 0
                rest_preis = 0;
                }

            rest_preis = rest_preis - mein_geldstueck;
    }

    }while(rest_preis > 0);




}

void ausgabe (int menge){

    //Die Funktion gibt aus die Anzahl von Produkten die ausgegeben werden

    cout<<"--- AUSGABE ---"<<endl;
    int i = 0;

    do {

        cout<<"Produkt "<<i+1<<" von "<<menge<<" wurde ausgegeben."<<endl;

        i++;

    } while(i!=menge);

}
bool eq(double a, double b){

    //Die Funktion liefert True wenn zwei Werte fast gleich sind, also der Unterschied is minimal

    bool flag = false;
    const double epsilon = 0.001;
   if (fabs(a-b) < epsilon)
        flag = true;

    return flag;
}
bool isinvektor( double geldstueck){
    /*Diese Funktion kontrolliert ob ein eingegebenes Geldstueck von der Maschine akzeptiert werden kann
    d.h ob das in dem Vektor muenzen ist. */

    bool flag = false;

    for(double i:muenzen){

        if (i == geldstueck)

            flag = true;
    }

    return flag;
}
