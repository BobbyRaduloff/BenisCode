#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <bitset>

using namespace std;

void splitString(string& str, vector<string>& vec){
	string newString = "";
	for(int i = 0; i < str.length(); i++)
		if(str[i] != ' ')
			newString += str[i];
		else{
			vec.push_back(newString);
			newString = "";
		}
	vec.push_back(newString);
}

void encodeStringToNums(string& str, vector<unsigned int>& nums){
	bool isCaps = false;
	for(int i = 0; i < str.size(); i++)
		if(str[i] == ' ')
			nums.push_back(0);
		else if(str[i] >= 'a' && str[i] <= 'z'){
			if(isCaps){
				nums.push_back(28);
				isCaps = false;
			}
			nums.push_back(str[i] - 'a' + 1);
		}else if(str[i] >= 'A' && str[i] <= 'Z'){
			if(!isCaps){
				nums.push_back(27);
				isCaps = true;
			}
			nums.push_back(str[i] - 'a' + 1);
		}else if(str[i] == '.')
			nums.push_back(29);
		else if(str[i] == '?')
			nums.push_back(30);
		else if(str[i] == '!')
			nums.push_back(31);
}

void encodeNumsToBenis(vector<unsigned int>& nums, string& encoded){
	for(int i = 0; i < nums.size(); i++){
		string currentBenis = "benis";
		bitset<5> bits(nums[i]);
		string bitsString = bits.to_string<char, string::traits_type, string::allocator_type>();
		for(int j = 0; j < 5; j++)
			if(bitsString[j] == '1')
				currentBenis[j] = toupper(currentBenis[j]);
		encoded += currentBenis;
		if(i < nums.size() - 1)
			encoded += ' ';
	}
}

void decodeWords(vector<string>& vec, string& str){
	bool isCaps = false;
	for(int i = 0; i < vec.size(); i++){
		bitset<5> bits;
		bits.set();
		for(int j = 0; j < vec[i].length(); j++)
			if(islower(vec[i][j]))
				bits[j] = 0;
		bitset<5> bits2;
		bits2 = bits;
		for(int j = 0; j < 5; j++)
			bits[j] = bits2[4-j];
		unsigned long num = bits.to_ulong();
		if(num == 0)
			str += ' ';
		else if(num >= 1 && num <=26)
			if(!isCaps)
				str += (char) num + 'a' - 1;
			else
				str += (char) num + 'A' - 1;
		else if(num == 27)
			isCaps = true;
		else if(num == 28)
			isCaps = false;
		else if(num == 29)
			str += '.';
		else if(num == 30)
			str += '?';
		else if(num == 31)
			str += '!';
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
		cout << "Text to decode: ";
		getline(cin, input);
		cout << input << endl;
		splitString(input, words);
		decodeWords(words, output);
		cout << "Decoded: " << output << endl;
	}else if(tolower(input[0]) == 'e'){
		cout << "Text to encode: ";
		getline(cin, input);
		encodeStringToNums(input, nums);
		encodeNumsToBenis(nums, output);
		cout << "Encoded: " << output << endl;
	}else
		cout << "Invalid input! Bye..." << endl;
	return 0;
}