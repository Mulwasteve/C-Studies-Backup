//Program 7.11 - A dynamic prime example
#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
	unsigned long long *pPrimes = NULL;			//pointer to primes storage area
	unsigned long long trial = 0;				//integer to be tested
	bool found = false;							//indicates when a prime is found
	int total = 0;								//number of primes to be found
	int count = 0;								//number pf primes already found

	printf("How many primes would you like - you will get atleast 4? ");
	scanf_s("%d", &total);			//total is how many primes we need to find
	total < 4 ? 4 : total;			//make dure that there are atleast 4 primes requested

	//allocate sufficcient memory to store the number of primes requested
	pPrimes = (unsigned long long*)malloc(total * sizeof(unsigned long long));
	if (!pPrimes)
	{
		printf("Not enough memory. It is the end I'm afraid!\n");
		return 1;
	}

	//the first three primes are obvious, so give the program a start 
	*pPrimes = 2ULL;			//first prime, on the first pointer location
	*(pPrimes + 1) = 3ULL;		//second prime, on the second pointer location
	*(pPrimes + 2) = 5ULL;		//third prime, on the third pointer location
	count = 3;
	trial = 5ULL;			//to the ;ast prime we have

	//find all the primes required
	while (count < total)		//in order for the next one to be found and stored
	{
		trial += 2ULL;			//next candidate for checking/testing it has to be an odd number

		//divide by the primes we have. If an exact division, it is not a prime
		for (int i = 0; i < count; ++i)
		{
			if (!(found = (trial % *(pPrimes + i))))	//an even number will result in found being true, and end(break) of the statement
				break;		//exit if zero remainder
		}

		if (found)		//we got one - if found is true - after non-division on the if statement above]
			*(pPrimes + count++) = trial;		//store it in the address and increment count
	}
	
	//display primes - five on each line
	for (int i = 0; i < count; ++i)
	{
		printf("%12llu ", *(pPrimes + i));
		if (!((i + 1) % 5))
			printf("\n");			//newline after every five lines
	}
	printf("\n");			//newline after all output(any stragglers)

	free(pPrimes);		//release the heap memory...
	pPrimes = NULL;		//...and reset the pointer

	getchar();
	getchar();
	return 0;
}