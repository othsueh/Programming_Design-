#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {

	int N, K;
	cin >> N >> K;

	// Number of characters on the current line (not including spaces)
	int word_len = 0;
	for (int i = 0; i < N; i++) {
		string word;
		cin >> word;
    word_len += word.size();
    if(word_len <= K){
      if(i != 0){
        cout << " ";
      }
      cout << word;
    }else{
      cout << '\n';
      cout << word;
      word_len = word.size();
    } 
	}
}
