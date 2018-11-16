//repeat of the primes example - Program 7.11(A dynamic prime example
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
	unsigned long long *pPrimes = NULL;		//pointer to primes storage area
	unsigned long long trial = 0;		//intger to be tested
	bool found = false;
	int total = 0;		//total is how many primes are needed to be found
	int count = 0;		//number of the primes that have already been found

	printf("How many primes would you like - you will get atleast 4 ? ");
	scanf("%d", &total);
	total < 4 ?  4 : total;		//make sure that there are atleast 4 primes requested

	//allocate sufficient memory to store the requested number of primes
	pPrimes = (unsigned long long*)malloc(total * sizeof(unsigned long long));	//allocate and cast to ULL* type pointer
	if (!pPrimes)
	{
		printf("Memory allocation failed. End of the program!\n");
		return 1;		//this will help track an error
	}


	//give the program a start by assigning the first 3 known primes
	*pPrimes = 2ULL;		//stored at location 0, count is 1
	*(pPrimes + 1) = 3ULL;	//stored at location 1, count is 2
	*(pPrimes + 2) = 5ULL;	//stored at location 2, count is 3
	trial = 5ULL;	//set to the last available prime
	count = 3;


	//find the requested number of primes
	//a prime is found simply when an odd number is indivisible by the available prime numbers
	while (count < total)
	{
		trial += 2ULL;	//the next odd number for testing

		//test divisibility with all the previously stored primes, store the result in a boolena variable
		for (int i = 1; i < count; ++i)
		{
			found = (trial % *(pPrimes + i));
			if (!found)		//found contain 0, after a division
				break;
		}

		if (found)	//non zero result after the division, therefore trial number is a prime
			*(pPrimes + count++) = trial;		//store in the next available spot in the pointer location
			//the count variable is also incremented to be used on the next loop

	}

	//display all the found primes
	for (int i = 0; i < total; ++i)
	{
		printf("%15llu ", *(pPrimes + i));
		if ((i + 1) % 5 == 0)
			printf("\n");
	}
	printf("\n");

	free(pPrimes);		//release the heap memory...
	pPrimes = NULL;		//...and reset the pointer


	getchar();
	getchar();
	return 0;
}
