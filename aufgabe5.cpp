/*Bearbeitet am 16.04.2020 von Lucas Canete Ramirez
This program converts a given decimal number to its binary. 
Also, you can decide to add or delete any 0 or 1 from the binary
number and see what its decimal counterpart is.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
void binary_to_decimal(vector<int> &my_vector,int bit,int stelle);

int main(){
    vector<int> binary={};
    //unsigned int hat 4 bytes , d.h 32 bits
   int counter =  0;
   int stelle;
   int bit;

   unsigned int var;

   cout<<"Geben Sie eine Zahl ein: ";

   cin>>var;

    cout<<var<<" : ";
   for (int i=31;i >=0;i--){

       int neu_num = var>>i;

       cout<<(neu_num&1);

       binary.insert(binary.begin(),(neu_num&1)); // Hier fügt man jedes neue bit am Anfang, sodass man eine umgekehrte bit-kette hat. Diese umgekehrte kette macht es einfacher die bits in eine zahl umzuwandeln.

       if ((neu_num&1) == 1)
            counter++;


   }
   cout<<" "<<endl;

   cout<<"das Bitmuster hat "<<counter<<" Einsen."<<endl;

   cout<<"Welches Bit (0-31 von rechts beginnend) soll geaendert werden? ";

   cin>>stelle;

   cout<<"Auf welchen Wert (0 oder 1) soll das Bit gesetzt werden? ";
   cin>>bit;


   if(stelle <= 31 && stelle>=0 &&( bit == 1 || bit == 0 ))

        binary_to_decimal(binary,bit,stelle);

    else{
        cout<<"Error in der Eingabe";
    }


return 0;


}



void binary_to_decimal(vector<int> &my_vector, int bit,int stelle){

    my_vector[stelle] = bit; // man bechselt das eingegebene bit an der stelle x

    int decimal = 0;


    for (int i = 0;i <= 31;i ++)
        decimal += (my_vector[i]*pow(2,i)); //Hier wandeln wir die Bits in dezimal Zahl um und addieren alle Werte in der decimal variable



    cout<<decimal<<" : ";

    for (int i = 31;i >= 0;i --)
        cout<<my_vector[i];


}
