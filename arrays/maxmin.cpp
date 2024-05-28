#include <stdio.h>


int main()
{
	int A[] = {5,8,3,9,6,2,10,7,-1,4};

	int max = A[0];
	int min = A[0];

	for(int i = 1; i < 10; i++)
	{
		if(A[i] < min)
			min = A[i];
		else if(A[i] > max)
			max = A[i];
	}
	
	printf("Max: %d, Min: %d\n", max, min);

}
			
