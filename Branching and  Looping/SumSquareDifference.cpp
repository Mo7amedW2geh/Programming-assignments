#include <iostream>
using namespace std;

int main() {
	
	//Problem 6 (Project Euler)
	//The difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
	
	
	int n = 100;     //we can use cin

	int sum = 0;     //The sum of the squares
	int square = 0;  //The square of the sum

	for (int i = 1; i <= n; i++) {
		sum += i * i;
		square += i;
	}
	
	square = square * square;

	cout << "The difference between the sum of the squares and the square of the sum = " << square - sum << endl;

	return 0;
}
