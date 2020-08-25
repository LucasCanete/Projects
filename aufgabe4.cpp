/*Lucas Cañete Ramirez. Bearbaitet am 30. April, 2020.
Converts any given year between year 1 and year 2100 to  
roman year.
*/

#include <iostream>
#include <vector>

using namespace std;

int jahreszahl,bruch;


vector <int> zahlen  = {1,4,5,9,10,40,50,90,100,400,500,900,1000}; //Man nimmt "Grundwerte" mit denen die eingegebene Jahreszahl geteilt wird
vector <string> rom = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};

int main() {

cout <<"Geben Sie eine Jahreszahl zwischen 1-2100:";
cin>>jahreszahl;
cout<<"Die Zahl "<<jahreszahl<<" in roemischer roemischer Schreibweise ist: ";

int i = 12; // Anzahl von Werten die man im "zahlen" Vektor hat

if (jahreszahl !=0 || jahreszahl<=2100) {

    while(i!=-1){

        bruch = jahreszahl/zahlen[i]; //Wir teilen unsere Jahreszahl durch die Werte von unserem ersten Vektor. Wir beginnen von dem grössten Wert bis zu dem kleinsten
        if (bruch!=0){

            for(int n=0;n<bruch;n++){

                cout<<rom[i]; //Wenn das Ergebnis !=0 ist, Z.B. 2, dann drücken wir 2 mal den Buchstabe "M" in dem Fall das wir am Anfang Jahreszahl durch 1000 geteilt haben usw

                }
        }
        jahreszahl = jahreszahl%zahlen[i]; //Der Wert Jahreszahl nimmt jetzt den Wert von dem Rest der Division an

        i--; //Bei jeder Iteration substraieren wir i um eins damit das nächste mal der neue wert von jahreszahl durch einen kleineren Wert geteilt wird
    }

}
else {

    cout<<"Fehler in der Eingabe: Zahl nicht im Bereich 1-2100!";

}




return 0;
}
