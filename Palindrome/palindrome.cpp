// palindrome.cpp -- solve C++ Primer Plus chapter 16, 
// 1-2 excercice problems about palindromes
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <iterator>

// Debug purpose, comment if don't need debugging
//#define DEBUG

// The main idea -- is create a reverse string
// by using reverse iterators 
// and then check for equivalence;
inline bool is_palindrome(const std::string& str)
{
	// 1st stage, create a convinient string 
	// without spaces, dots, etc.
	// And convert all uppercase letters to lower 
	std::string word;
	std::copy_if(str.begin(), str.end(), 
		std::insert_iterator<std::string>(word,word.begin()), 
		std::isalpha);
#ifdef DEBUG
	using std::clog;
	using std::endl;
	clog << "Original string: " << str << endl;
	clog << "Copied string: " << word << endl;
#endif // DEBUG
	std::transform(word.begin(), word.end(), word.begin(), std::tolower);
#ifdef DEBUG
	clog << "Transformed string: " << word << endl;
#endif // DEBUG
	// 2nd stage, create a reverse string
	// by using reverse iterators
	std::string reverse;
	std::copy(word.rbegin(), word.rend(),
		std::insert_iterator<std::string>(reverse,reverse.begin()));
#ifdef DEBUG
	clog << "Reversed string: " << reverse << endl;
#endif // DEBUG
	// Last stage, check for equivalance
	if (word == reverse) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	using std::cout;

	cout << "This program will request input a word and then check if it's a palindrome.\n";
	std::string input;
	cout << "Enter a word(<q> to quit): ";
	while (std::getline(std::cin,input) && input != "q")
	{
		cout << "Is \"" << input << "\" palindrome?\n";
		cout << std::boolalpha << is_palindrome(input) << "\n\n";
		cout << "Enter another word(<q> to quit): ";
	}
	return 0;
}