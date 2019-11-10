/* Maylee Gagnon
 * CS 2223 HW3 P1 Palindrome
 * 11.10.19
 */
#include <iostream>
#include <cstring>
#include <ctype.h>
#include <stdlib.h>
using namespace std;

/* Recursively checks whether a given string is a palindrome
 *
 * Starts at either end, gets letters, checks if the same, if not return false, if yes then recursive call rightPoss++, leftPos--,
 * if middle which means reached the last comparison (right++ >=leftpos) then return from function
 * Some examples checked: mom, abc, racecar, race car, mo m, m om, RaCEaRE, Never odd or even, A man, a plan, a canal: Panama!
 *
 * 0 1 2 3 4 5   05 14 23  > (2+1)>=3
 * 0 1 2 3 4 5 6    06 15 24 3 > (3+1)>=3
 */
bool checkPalindrome(char* str, int rightPos, int leftPos) {
	char rChar = str[rightPos];
	char lChar = str[leftPos];
	while(isalpha(rChar) == 0) { // non-letter
		rightPos++;
		rChar = str[rightPos];
	}
	while(isalpha(lChar) == 0) {
		leftPos--;
		lChar = str[leftPos];
	}

	if (rChar != lChar){
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
	cout << "Enter phrase to check" << endl;
	char str[256];
	fgets(str, 256,stdin);

	cout << "Phrase Entered: " << str << endl;

	for (int i = 0; i < strlen(str); i++){ // change to lower case, to ignore case
		str[i] = tolower(str[i]);
	}

	bool result = checkPalindrome(str,0, (strlen(str)-2)); // avoiding null terminator, check for letters anyways though
	if (result) {
		cout << "Yes, Phrase entered is a palindrome" << endl;
	}
	else {
		cout << "No, Phrase entered is not a palindrome" << endl;
	}
	return 0;
}
