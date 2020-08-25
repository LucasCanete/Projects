#include <iostream>
/*Programm von Lucas Cañete Ramirez. Freitag den 27. März, 2020 */

using namespace std;

unsigned int uhr,minute;

int main() {

cout<<"Geben Sie die aktuelle Uhrzeit(Stunde Minute) ein:"<<endl;
cout<<"Uhr:";
cin>>uhr;
cout<<"Minute:";
cin>>minute;

/* Von 8 am bis 17:59 pm fahren die Buse jede halbe Stunde. Deswegen gucken wir ob die eingegebene Minute grösser oder
kleiner als 30 ist. Wenn wir das bestimmen, subtraieren wir minute von entweder 30 oder 60 um zu rechnen, wie viele minuten man abwarten musst.*/

if( uhr>=8 && uhr <=18 ){



    if(minute==0){

        cout<<"Ihr Bus kommt in 0 Minuten.";

   }
   else if(minute>=30 && minute<= 59){
    /*minute von 30 bis 59*/
    unsigned int rest = 60 - minute;
    cout<<"Ihr Bus kommt in "<<rest<<" Minute(n)";

        }
    else if(minute<=30 && minute >0){
        /*minute von 1 bis 30*/
        unsigned int rest = 30 - minute;
        cout<<"Ihr Bus kommt in "<<rest<<" Minute(n)";

    }

    else {

    cout<<"Fehlerhafte Eingabe!"; //für minute>59

    }



}

/*von 00 bis 8 und von 18 bis 23 fahren die Buse nur jede Stunde, dass heisst, wenn Minute !=0 kommt der Bus in 60-eingebeneminute minuten zur Haltestelle*/

if(uhr>=0 && uhr<8  ||  uhr>=18 && uhr <=23 ){

    if (minute==0)
        cout<<"Ihr Bus kommt sofort";

    else if(minute <60 &&minute>0) {
        /*von minute 1 bis 59*/
        unsigned int rest = 60- minute;
        cout<<"Ihr Bus kommt in "<<rest<<" minute(n).";

    }

    else{

    cout<<"Fehlerhafte Angabe!";//für minute>59


    }
}
if(uhr>23){
    cout<<"Fehlerhafte Angabe!";
}


return 0;
}
