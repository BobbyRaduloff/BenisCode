#include <iostream>
#include <vector>

using namespace std;

bool isStringOnlySpace(string& str){
	if(str.find_first_not_of(' ') != string::npos)
		return false;
	return true;
}

void printVecString(vector<string>& vec){
	for(int i = 0; i < vec.size(); i++){
		cout << vec[i] << endl;
	}
}

void splitString(string& str, vector<string>& vec){
	int start = 0;
	string newString = "";
	for(int i = 0; i < str.length(); i++){
		if(str[i] != ' '){
			newString += str[i];
		}else{
			if(!isStringOnlySpace(str)){
				vec.push_back(newString);
				newString = "";
			}
		}
	}
	for(int i = 0; i < vec.size(); i++){
		cout << vec[i] << endl;
	}
}

void encodeWord(string& str, vector<unsigned int>& nums){
	for(int i = 0; i < str; i++){
		
	}
} 

int main(){
	string input;
	vector<string> words;
	cout << "[D]ecode or [E]ncode: ";
	getline(cin, input);
	if(tolower(input[0]) == 'd'){

	}else if(tolower(input[0]) == 'e'){
		cout << "Text to encode: ";
		getline(cin, input);
		splitString(input, words);
		
	}else{
		cout << "Invalid input! Bye..." << endl;
	}
	return 0;
}