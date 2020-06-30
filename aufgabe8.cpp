/*Written by Lucas Canete the 14th of May*/
/*Programm that identifies all prime numbers until 100 by using the Sieve method made by Eratosthenes. More information at
https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes */


#include <iostream>
#include <vector>


using namespace std;


void output(const vector<bool>& numbers, int width, int columns){

    /*This function returns the values in form of a chart*/

    int index = 2;
    int mein_column = 0;

    for(index;index<numbers.size();index++){
        //We only output the numbers that have indexes that represent a true value
        if (numbers[index] == true){
            //We define the width from one position
            cout.width(width);cout<<right<<index<<" ";
            mein_column++;

        }
	//When the counter mein_column equals the number of columns, then we make a new column and repeat the process
        if (mein_column == columns){
            cout<<" "<<endl;
           mein_column = 0;
        }
    }





}

void sieve(vector<bool> &numbers){
/*Here we know that all multiples from 2 (a prime number) can be deleted or identified as non prime numbers.
In this way, after the first iterarion, we iterate through the rest of the numbers that havent been deleted. At the end we have all values of the 
numbers vector set as false (not a prime number) or true (a prime number). The indexes of this boolean values inside of the numbers vector indicate which number is prime or not prime.
Example: numbers[2] = true or numbers [6] = false.*/



    int i = 2; //Here we begin from 2 because prime numbers begin at 2.

    for ( i; i<numbers.size();i++){
    //i represents the index where we are. We iterare through all values frrom the numbers vector until the end.
    

        if (numbers[i] == true){
	// When the variable has an index true that indicates true (Prime number) we continue.
      

            for(int z=i+1; z<numbers.size(); z++){
	    // We iterate from the value numbers[i+1] until the end of the vector.	

                if(z%i == 0){
		//When the division from both numbers is cero, we set the value for numbers[z] as false.
               
                    numbers[z] = false;
                }

            }


        }
    }

}





int main(){
vector<bool> numbers = {};

int n = 1000; //We will find all prime numbers until n.

//We define a Vector with the name numbers and fill it with n-mal true values.

int counter = 0;
 while (counter <= n){

    numbers.push_back(true);
    counter ++;


 }

sieve(numbers);



output(numbers,4,10);

return 0;

}
