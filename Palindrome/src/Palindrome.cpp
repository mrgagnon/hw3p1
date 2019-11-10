/* Maylee Gagnon
 * CS 2223 HW3 P1 Palindrome
 * 11.10.19
 */
#include <iostream>
#include <cstring>
#include <ctype.h>
#include <stdlib.h>
using namespace std;

/* Start at either end, checks if the same, if not return false, if yes then recursive call rightPoss++, leftPos--,
 * if middle aka base case(?) if right++ >=leftpos
 * 0 1 2 3 4 5   05 14 23
 * 0 1 2 3 4 5 6  06 15 24 3
 * 0 1 2
 *
 */
bool checkPalindrome(char* str, int rightPos, int leftPos) {
	bool isEqual;
	 cout << rightPos << " " << leftPos << endl;

	char rChar = str[rightPos];
	while(isalpha(rChar) == 0) { // non-letter
		rightPos--;
		rChar = str[rightPos];
	}

	char lChar = str[leftPos];
	while(isalpha(lChar) == 0) { // non-letter
		leftPos--;
		lChar = str[leftPos];
	}

	if (rChar == lChar) {
		//cout << rChar << " " << lChar << " true" << endl;
		isEqual = true;
	}
	else if (rChar != lChar){
		cout << "false" << endl;
		return false; //pair are not equal so return false
	}

	if ((rightPos+1) >= leftPos) { // base case, reached middle, all letters have been checked
		return true;
	}
	else {
		rightPos++;
		leftPos--;
	checkPalindrome(str,rightPos,leftPos);
	}
}

int main() {
	cout << "Hello" << endl;

	cout << "Enter phrase to check" << endl;
	char str[256];
	fgets(str, 256,stdin);

	cout << "String: " << str << endl;

	// change to lower case, to ignore case
	for (int i = 0; i < strlen(str); i++){
		str[i] = tolower(str[i]);
	}
	cout << "String: " << str << endl;

	bool result = checkPalindrome(str,0, (strlen(str)-2)); // avoiding null terminator, check for letters anyways though
	cout << "result: " << result << endl;

	return 0;
}
