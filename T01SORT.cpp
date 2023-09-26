#include <iostream>
#include <fstream>

#pragma warning(disable: 6385)

template<typename Type>
void Swap(Type *A, Type *B)
{
	Type tmp = *A;

	*A = *B;
	*B = tmp;
}

template<typename Type>
void Sort(Type* A, int N)
{
	int b = 0, e = N - 1;
	Type x;

	if (N < 2)
		return;

	x = A[N / 2];

	while (b <= e)
	{
		while (A[b] < x)
			b++;
		while (A[e] > x)
			e--;
		if (b <= e)
		{
			if (b != e)
				Swap(&A[b], &A[e]);
			b++;
			e--;
		}
	}

	Sort(A, e + 1);
	Sort(A + b, N - b);
}

template<typename Type>
void RandFill(Type *A, int n)
{
	for (int i = 0; i < n; i++)
		A[i] = rand() % n + rand() % n / (Type)n;
}

int main(void)
{
	double *A;
	std::string fn;
	int n;
	
	std::cin >> n;

	if ((A = (double*)malloc(8 * n)) == NULL)
		return 0;

	RandFill(A, n);

	Sort(A, n);

	std::fstream f("res.txt", std::fstream::out);
	
	for (int i = 0; i < n; i++)
		f << A[i] << "\n";

	f.close();
	free(A);
}