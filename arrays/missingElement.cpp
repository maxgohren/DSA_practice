#include <iostream>

using namespace std;

inline void printArray(int *a, int n)
{
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
}

int main()
{
    // one missing element
    int a[] = {1,2,3,4,5,6,8,9,10,11,12};
    int n = 12; // how many should be here
    int sum = 0;

    for(int i = 0; i < 11; i++)
    {
        sum = sum + a[i];
    }

    int S = n * (n+1) / 2;

    int diff = S - sum;

    cout << "Find a single missing element in a[] = "; 
	printArray(a, n);
    cout << endl << "Missing number is " << diff << endl;
	cout << endl;

    // multiple missing element
    int b[] = {6,7,8,9,11,12,15,16,17,18,19};
    int bdiff = b[0] - 0;

    cout << "Find missing elements of b[] = "; 
	printArray(b, 11);
	cout << endl;
    for(int i = 0; i < 11; i++)
    {
        if(b[i] - i != bdiff)
        {
            while(bdiff < b[i] - i)
            {
                cout << i + bdiff << " ";
                bdiff++;
            }
        }
    }
    cout << endl << endl;

    // hash table finding missing elements
	int l = 1;  
	int h = 12; // largest element of c[]
	n = 10; // number of elements in c[]
    int d[] = {3,7,4,9,12,6,1,11,2,10};
    int H[h] = {0,0,0,0,0,0,0,0,0,0,0,0}; 

    for(int i = 0; i < n; i++)
        H[d[i]]++;

    cout << "Find missing elements (using a hash table) of c[] = ";
	printArray(d, n);
	cout << endl;
    for(int i = l; i < h; i++)
        if(H[i] == 0) cout << i << " ";

    cout << endl << endl;
	
	// finding duplicate elements
	int e[] = {3,6,8,8,10,12,15,15,15,20};
	int lastDup = 0;

	cout << "Finding duplicates in e[] = ";
	printArray(e, 10);
	cout << endl;
	for(int i = 0; i < 10; i++)
	{
		if( e[i] == e[i+1] && e[i] != lastDup)
		{
			cout << e[i] << " ";
			lastDup = e[i];
		}
	}
	cout << endl << endl;

	// counting duplicates
	int f[] = {3,6,8,8,10,12,15,15,15,15};
	n = 10;
	int j = 0;
	int lastDupf;

	cout << "Counting duplicates in f[] = ";
	printArray(f, n);
	cout << endl;
	for(int i = 0; i < n-1; i++)
	{
		if( f[i] == f[i+1] )
		{
			j = i + 1;
			while( f[i] == f[j] ) j++;
			cout << f[i] << " appears " << (j - i) << " times" << endl;
			i = j-1;
		}
	}
	cout << endl << endl;

	// counting duplicates with hashing
	cout << "Counting duplicates with a hash table" << endl;
	int g[] = {3,6,8,8,10,12,15,15,15,20};
	int G[20] = {0};
	
	for(int i = 0; i < 10; i++)
		G[g[i]]++;

	for(int i = 0; i < 20; i++)
		if(G[i] > 1) cout << "The duplicate " << i << " appears " << G[i] << " times" << endl;	

	cout << endl;

	// finding duplicates in unsorted array
	cout << "Finding duplicates in unsorted array" << endl;
	int unsorted[] = {8,3,6,4,6,5,6,8,2,7};
	n = 10;
   	printArray(unsorted,n);
	cout << endl;

	int count = 0;
	int x = 0, y = 0;

	for(x = 0; x < n-1; x++)
	{
		count = 1;
		if(unsorted[x] != -1)
		{
			for(y = x+1; y < n-1; y++)
			{
				if(unsorted[x] == unsorted[y])
				{
					count++;
					unsorted[y] = -1;
				}
			}
		}
		if(count > 1) cout << "The element: " << unsorted[x] << " appears " << count << " times" << endl;
	}
    return 0;
}

