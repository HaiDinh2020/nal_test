#include<iostream>

using namespace std;

bool checkLatinIsVn(string latin) {
	string vn[] = {"aa", "dd", "oo", "ee", "aw", "ow", "w"};
	int size = sizeof(vn) / sizeof(vn[0]);
	for(int i = 0; i < size; i++) {
		if(vn[i] == latin) return true;
	}
	return false;
}

int countLatinToVn(string latin)  {
	int result = 0;
	
	int j = 1;
	for (int i = 0; i < latin.length(); i= i+j) {
		if(checkLatinIsVn(string(1, latin[i]))) {
			result++;
			j = 1;
			cout << string(1, latin[i]) << " ";
		} else if(i < latin.length() -1 && checkLatinIsVn(string(1, latin[i]) + string(1, latin[i+1]))) {
			result++;
			j = 2;
			cout << string(1, latin[i]) + string(1, latin[i+1]) << " ";
		}
	}
	return result;
}

int main(){
	string latin;
	cin >> latin;
	cout << endl << countLatinToVn(latin);
	return 0;
}

