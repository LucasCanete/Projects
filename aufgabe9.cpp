/*Written by Lucas Canete am 24.Mai 2020*/
/*This program checks if a given string is a palindrom (reversed word is the same as original word)
and returns the reversed string, without any spaces or symbols that do not belong to the alphabet
*/
#include<iostream>


using namespace std;


string clean(const std::string& text){
//Deletes chars that do not contain letters

    string new_text = text;

    int length = text.size();

    for (int i = 0;i<length;i++){
        //When following chars are found,delete them
       if(new_text[i] == ' ' || new_text[i] == '-' || new_text[i] == '!' || new_text[i] == '?' || new_text[i] == '.' || new_text[i] == ',')
            new_text.erase(new_text.begin() + i);
    }
    
return new_text;
    
}

void swap(char& a, char& b){
    //Convert one string to another one by every letter
    a = b;

}




bool reverse(std::string& text){
    //Reverse text

    string new_text = text;
    int length = text.size()-1;
    int counter = text.size()-1;

    for(int i = 0; i<=length;i++){
        //Last letter takes value from the last one.
        text[i] = new_text[counter];

        counter--;
    }


    //When new string is the same as the original, then return true
    bool flag = true;
    if (new_text != text)
            flag = false;


    return flag;

}





int main(){

string text;
cout<<"Introduce a new line: ";
getline(cin,text);

cout<< "Cleaned text: "<<clean(text)<<"."<<endl;
string neu_text = clean(text);
cout<<"Length: "<<neu_text.size()<<endl;


for (int i = 0;i<text.size();i++){

    swap(text[i],neu_text[i]);

}
for (int i = text.size()-1; i>=0 ;i--){

    if(text[i]=='\0'){
        text.erase(text.begin() + i);
    }

}

reverse(text);
cout<<"Reversed order: "<<text<<endl;
cout<<"Palindrom? ";
if (reverse(text))
    cout<<"Yes.";
else{
    cout<<"No.";
}


return 0;
}
