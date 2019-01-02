#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string findFirstDelim(vector<string> delimiters, string input){
    string delimiter = "";
    size_t minimum = input.find(delimiters[0]);
    delimiter = delimiters[0];
    for(int i = 1; i < delimiters.size(); i ++){
        if(input.find(delimiters[i])<minimum){
            minimum = input.find(delimiters[i]);
            delimiter = delimiters[i];
        }
    }
    return delimiter;
}

vector<string> tokenizer(vector<string> delimiters, string input){
    string token = "";
    vector <string> tokens;
    string delimiter = "";

    //determine if there are any delimiters within the input
    bool noDelims = true;
    for(int i = 0; i < delimiters.size(); i ++){
        if(input.find(delimiters[i])!=string::npos){
            noDelims = false;
        }
    }
    if(noDelims)tokens.push_back(input);


    //use recursion to tokenize each variable
    else{
        delimiter = findFirstDelim(delimiters, input);
        token = input.substr(0,input.find(delimiter)+delimiter.length());
        tokens.push_back(token);
        input.erase(0,input.find(delimiter)+delimiter.length());
        vector <string> next = tokenizer(delimiters, input);
        tokens.insert(tokens.end(),next.begin(), next.end());
    }
    return tokens;
}


vector<string> tokenize(string input){
    string delimiter1 = "(";
    string delimiter2 = ")";
    vector<string> delimiters;
    delimiters.push_back(delimiter1);
    delimiters.push_back(delimiter2);
    vector<string> tokens = tokenizer(delimiters,input);
    return tokens;

}

