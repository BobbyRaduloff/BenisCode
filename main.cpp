#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <bitset>

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

void encodeStringToNums(string& str, vector<unsigned int>& nums){
	for(int i = 0; i < str.size(); i++){
		if(str[i] == ' '){
			nums.push_back(0);
		}else if(str[i] >= 'a' && str[i] <= 'z'){
			nums.push_back(str[i] - 'a' + 1);	
		}else if(str[i] == ':'){
			nums.push_back(27);
		}else if(str[i] == ';'){
			nums.push_back(28);
		}else if(str[i] == '.'){
			nums.push_back(29);
		}else if(str[i] == '?'){
			nums.push_back(30);
		}else if(str[i] == '!'){
			nums.push_back(31);
		}
	}
}

void encodeNumsToBenis(vector<unsigned int>& nums, string& encoded){
	for(int i = 0; i < nums.size(); i++){
		string currentBenis = "benis";
		bitset<5> bits(nums[i]);
		string bitsString = bits.to_string<char, string::traits_type, string::allocator_type>();
		for(int j = 0; j < currentBenis.length(); j++){
			if(bitsString[j] == '1')
				currentBenis[j] = toupper(currentBenis[j]);
		}
		encoded += currentBenis;
		if(i < nums.size() - 1){
			encoded += ' ';
		}
	}
}


int main(){
	string input;
	vector<string> words;
	vector<unsigned int> nums;
	string output;
	cout << "[D]ecode or [E]ncode: ";
	getline(cin, input);
	if(tolower(input[0]) == 'd'){

	}else if(tolower(input[0]) == 'e'){
		cout << "Text to encode: ";
		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), ::tolower);
		encodeStringToNums(input, nums);
		encodeNumsToBenis(nums, output);
		cout << "Encoded: " << output << endl;
	}else{
		cout << "Invalid input! Bye..." << endl;
	}
	return 0;
}