// (Unfinished) Solutions to problems listed on 'https://projecteuler.net/archives'

#pragma warning (disable: 4996) // Disable Warning on Visual Studios

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Helper Functions
int isPalindrome(char *str);

int isPrime(int x);

// Solutions
int SumEvenFibs(int backFib, int frontFib, int maxFib);

int LargestPrimeFactor(int num);

int LargestPalindromeFromTwoThreeDigitNums();

int SmallestMultiple(int numberUpTo);

int SumSquaredDifference(int num);

int SpecialPythagoreanTriplet();

int ConsecutivePrimeSums(int maxSum);

int SelfPowers(int maxNum, int numberOfFinalDigits);

int DistinctPrimeFactors();

int main() // Test
{
	//printf("1. Even Fibonacci numbers up to 4mill sum: %d\n", SumEvenFibs(1, 2, 4000000));
	//printf("2. Largest prime factor for 600851475143 : %d\n", LargestPrimeFactor(600851475143));
	//printf("3. largest palindrome made from the product of two 3-digit numbers: %d\n", LargestPalindromeFromTwoThreeDigitNums());
	//printf("4. Smallest multiple(up to 20): %d\n", SmallestMultiple(10));
	//printf("5. Sum Squared Diff: %d\n", SumSquaredDifference(100));
	//printf("9. Special Pythagorean triplet for 1000: %d\n", SpecialPythagoreanTriplet());
	// Problems 10 - 46 (Unimplemented)
	//printf("47. Distinct Prime Factors: %d\n", DistinctPrimeFactors());
	//printf("48. Self Powers(up to 1000): %d\n", SelfPowers(1000,10));
	//49. Iterate 1k-10k, doing mod math to extract all digits and placing in list of special data structure. checking if digits match previous every iteration.
	//printf("50. Consecutive Prime Sums below 1million: %d\n",ConsecutivePrimeSums(10000));//Use LinkedList Instead
	
	return 0;
}

// Helper Functions
int isPalindrome(char *str) {
	int isPali = 1;
	int len = strlen(str);

	for (int i = 0; i < ceil((float)len / 2); i++) {
		if (str[i] != str[len - 1 - i]) {
			isPali = 0;
			break;
		}
	}
	return isPali;
}

int isPrime(int x) {
	if ((x == 2) | (x == 3)) {
		return 1;
	}
	if (x % 2 == 0) {
		return 0;
	}
	for (int i = 3; i*i <= x; i += 2) {
		if (x%i == 0) {
			return 0;
		}
	}
	return 1;
}

// Solutions

int SumEvenFibs(int backFib, int frontFib, int maxFib) {
	int sum = 0;

	while (frontFib < maxFib) {
		int nextFib = backFib + frontFib;
		if (nextFib % 2 == 0) sum += nextFib;
		backFib = frontFib;
		frontFib = nextFib;
	}
	return sum;
}

int LargestPrimeFactor(int num) {
	int currFactor = floor(sqrt(num));
	if (currFactor*currFactor == num) {
		if (isPrime(currFactor)) {
			return currFactor;
		}
	}
	if (currFactor % 2 == 0) {
		currFactor = currFactor - 1;
	}
	for (currFactor; currFactor > 1; currFactor -= 2) {
		if (isPrime(currFactor)) {
			return currFactor;
		}
	}
	return 0;
}

int LargestPalindromeFromTwoThreeDigitNums() {
	int currLargestPalindrome = 0;
	for (int i = 999; i >= 100; i--) {
		for (int j = 999; j >= 100; j--) {
			int prod = i*j;
			char *prodStr[1000];
			if (isPalindrome(itoa(prod, prodStr, 10))) {
				if (prod > currLargestPalindrome) {
					currLargestPalindrome = prod;
				}
			}
		}
	}
	return currLargestPalindrome;
}

int SmallestMultiple(int numberUpTo) {
	int startNumber = numberUpTo;

	if (startNumber % 2 != 0) {
		startNumber++;
	}
	for (int i = startNumber; 1; i += 2) {
		for (int j = 1; j <= numberUpTo; j++) {
			if (i%j != 0) {
				break;
			}if (j == numberUpTo) {
				return i;
			}
		}
	}
}

int SumSquaredDifference(int num) {
	int sumSq = 0;
	int sqSum = 0;

	for (int i = 1; i <= num; i++) {
		sumSq += i*i;
	}
	for (int i = 1; i <= num; i++) {
		sqSum += i;
	}sqSum *= sqSum;

	return sqSum - sumSq;
}

int SpecialPythagoreanTriplet() {
	int magicNum = 1000;
	int squares[1000];
	int lenSquaresArr = 0;
	for (int i = 1; i <= magicNum / 2; i++) {
		squares[i - 1] = i*i;
		lenSquaresArr++;
	}

	for (int a = 0; a < lenSquaresArr; a++) {
		for (int b = 0; b < lenSquaresArr; b++) {
			int c = sqrt(a*a + b*b);
			if ((c*c == (a*a + b*b)) & ((a + b + c) == magicNum)) {
				return a*b*c;
			}
		}
	}return 0;
}

int ConsecutivePrimeSums(int maxSum) {
	int primes[10000] = { 2 };
	int lenPrimesArr = 1;

	int maxNumOfPrime = 0;
	int maxPrime = 0;

	for (int i = 3; i < maxSum; i += 2) {
		if (isPrime(i)) {
			primes[lenPrimesArr] = i;
			lenPrimesArr++;
		}
	}
	for (int j = 0; j < lenPrimesArr; j++) {
		int currSum = 0;
		for (int i = j; i < lenPrimesArr; i++) {
			currSum += primes[i];
			if (currSum > maxSum) {
				break;
			}
			else if (isPrime(currSum) & ((i - j) > maxNumOfPrime)) {
				maxPrime = currSum;
				maxNumOfPrime = i - j;
			}
		}
		currSum = 0;
	}

	return maxPrime;
}

int SelfPowers(int maxNum, int numberOfFinalDigits) {
	unsigned int modVal = (int)pow(10, numberOfFinalDigits);
	int sum = 0;

	for (int i = 1; i <= maxNum; i++) {
		int currSelfPower = 1;
		for (int j = 0; j < i; j++) {
			currSelfPower = (currSelfPower*i) % modVal;
		}
		sum += currSelfPower;
		sum = sum%modVal;
	}

	return sum;
}

int DistinctPrimeFactors() {

	return 0;
}
