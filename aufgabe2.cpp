#include<iostream>
#include <vector>


using namespace std;

int tag,monat,jahr;

vector <int> monate_31  = {1,3,5,7,8,10,12};
vector <int> monate_30 = {4,6,9,11};

/*Eine funktion um zu bestätigen ob ein Jahr schaltjahr ist*/



bool schaltjahr(int jahr){

    bool status = false;

    if(jahr%4==0 && jahr%100!=0 || jahr%400==0)
        status = true;

    return status;

}


int main(){


cout<<"Geben Sie einen Tag ein:";
cin>>tag;

cout<<"Geben Sie einen Monat ein:";
cin>>monat;

cout<<"Geben Sie ein Jahr ein:";
cin>>jahr;

cout<<"Ueberpruefung des datums..."<<endl;


/*
Bei der ersten for schleife schauen wir ob der eingegebene Monat im ersten Vektor drin ist.
Wir iterieren durch die Monate. Wenn unsere bedingung erfüllt wird, wird "weiter"=0 und so vermeiden wir,
dass die Bedingungen von der zweiten for-schleige erfüllt werden.
*/


bool weiter=1;
    for (int m:monate_31){

        if (monat == m && tag <=31){

            cout<<"Gültiges Datum!";
            weiter=0;
            break;

        }
        else if(monat == m && tag>31){

            cout<<"ungültiges Datum!";
            weiter=0;
            break;


        }


    }
/* Wenn unser eingebener Monat nicht zum ersten Vektor gehört (somit bleibt weiter=0), so läuft das Programm weiter zu der zweiten for-Schleife.
Wenn das programm bis zum Ende kommt, und noch keine Bedingung erfüllt geworden ist, dann hat counter den wert 3 und wir wissen dass die eingegebenen Daten falsch sind.
    */

int counter=0;

    for(int m:monate_30){

        if(monat==m&& tag<=30 &&weiter==1){
            cout<<"Gültiges Datum!";
            break;
        }
        else if(monat==2 &&tag<=28 && !schaltjahr(jahr)&&weiter==1){

            cout<<"gültiges Datum";
            break;

        }
        else if(monat==2 && schaltjahr(jahr)&& tag<=29 &&weiter==1){

            cout<<"gueltiges datum!";
            break;

        }
        else if(counter==3 && weiter==1)
            cout<<"ungültiges Datum!";

        counter++;


    }









return 0;
}
