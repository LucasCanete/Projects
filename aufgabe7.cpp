/*Written by  Lucas Canete the 10th of May, 2020 */
/*Goal of this programm is to perform a division between two numbers by using iteration and recursion
but without using / % or *. Also, obtain the rest if there is any.*/


#include <iostream>
#include <vector>

using namespace std;

//Function will return a whole vector and in this way we can return two values
vector<int> rekursion (unsigned int zahler, unsigned int nenner,unsigned int counter){

    vector<int> results = {}; //This vector will be returned at the end

	if (zahler>=nenner){

    		zahler-=nenner;
    		counter++;      //We count every time that substract the denominator from numerator and use this value as parameter       

    return rekursion(zahler,nenner,counter);


}



	else if (zahler<nenner){

    		//We add values to our vector and return the whole
    		results.push_back(counter);
    		results.push_back(zahler);

    	return results;

}




}

//this function comes to the result only by using iteration 

vector <int> iteration (unsigned int zahler,unsigned int nenner){

	vector <int> it_results = {};
	int counter = 0;

	while(zahler>=nenner){

    		//instead of using a recursion here we use a while-loop and add by one after every iteration
    		zahler-=nenner;
    		counter++;
	}

	it_results.push_back(counter);
	it_results.push_back(zahler);

	return it_results;



}


int main(){

unsigned int p,q,counter;
counter = 0;

cout<<"Introduce two numbers p/q with p>=0 and q>0 :"<<endl;
cin>>p;
cin>>q;
vector <int> r_result = rekursion(p,q,counter);
vector <int> i_result = iteration(p,q);
cout<<"Iteration "<< p<<"/"<<q<<" = "<<i_result[0]<<" rest is = "<<i_result[1]<<endl;
cout<<"Rekursion "<< p<<"/"<<q<<" = "<<r_result[0]<< " rest is = "<<r_result[1];


return 0;
}

