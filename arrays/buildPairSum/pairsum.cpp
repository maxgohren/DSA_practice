#include <stdio.h>


int main()
{
	printf("Finding sums in int A[] = {6,3,8,10,16,7,4,2,9,14}\n");
	int count = 0;
	int i,j;
	int A[] = {6,3,8,10,16,7,4,2,9,14};

	for(i = 0; i < 10; i++)
	{
		for(j = i+1; j < 10; j++)
		{
			count = 0;
			count += A[i] + A[j];
			if(count == 10)
				printf("The elements %d and %d sum to 10.\n", A[i], A[j]);
		}
	}
	printf("\n");

	printf("Finding sums in int A[] = {6,3,8,10,16,7,4,2,9,14} using hash table\n");
	int H[16] = {0};
	int k = 10;

	for(i = 0; i < 10; i++)
	{
		if( H[k-A[i]] != 0 && k-A[i] > 0)
		{
			printf("%d + %d = %d\n", A[i], k-A[i], k);	
		}
		H[A[i]]++;
	}
	
	printf("\n");


	printf("Finding pair with sum k in sorted array B[] = {1,3,4,5,6,8,9,10,12,14}\n");
	int B[] = {1,3,4,5,6,8,9,10,12,14};
	i = 0;
	j = 9;
	while(i < j)
	{
		if( (B[i] + B[j]) == k)
		{
			printf("The pair %d and %d sum to %d\n", B[i], B[j], k);
			i++;
			j--;
		}
		if( (B[i] + B[j]) < k)
			i++;
		else
			j--;
	}






	return 0;
}
			
