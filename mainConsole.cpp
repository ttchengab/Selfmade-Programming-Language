#include <iostream>
#include "tokenizer.cpp"
#include "interpreter.cpp"

using namespace std;

int main(){

    while(true){
        cout<<">";
        string input = "";
        cin>>input;
        if(input == "EXIT") break;

        vector<string> finalTokens = tokenize(input);
        for(int i = 0; i < finalTokens.size(); i ++){
            cout<<finalTokens[i];
            cout<<" ";
        }
        cout<<"\n";
    }


    return 0;

}
