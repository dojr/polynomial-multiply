#include <stdio.h>

void print_arr(int arr[], int n);
void add_polys(int *P1, int *P2, int *P3, int arrSize);

    void init_arr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = 0;
    }
}

void iterative_poly(int poly1[], int p1Size, int poly2[], int p2Size, int *P3)
{
    int arrSize = p1Size + p2Size - 1, k = 0, output;

    for (int i = 0; i < p1Size; i++)
    {
        for (int j = 0; j < p2Size; j++)
        {
            output = poly1[i] * poly2[j];
            P3[k] += output;
            k++;
        }
        k = k - (p1Size - 1);
    }
}

void conquer_poly(int poly1[], int p1Size, int poly2[], int p2Size)
{
    int half = p1Size/2, k = 0, arrSize = p1Size+p2Size-1;
    int A0[half], A1[half];
    int B0[half], B1[half];
    int A0A1[half], B0B1[half];
    int U[arrSize], Z[arrSize], Y[arrSize];
    int last[arrSize];
    init_arr(last, arrSize);

    init_arr(A0, half), init_arr(A1, half), init_arr(B0, half), init_arr(B1, half);
    init_arr(A0A1, half), init_arr(B0B1, half);
    init_arr(U, arrSize), init_arr(Z, arrSize), init_arr(Y, arrSize);

    for (int i = 0; i < p1Size; i++)
    {
        if (i < half)
        {
            A0[i] = poly1[i];
            B0[i] = poly2[i];
        }
        else if (i >= half)
        {
            A1[k] = poly1[i];
            B1[k] = poly2[i];
            k++;
        }
    }

    // print_arr(A0, half);
    // print_arr(A1, half);
    // print_arr(B0, half);
    // print_arr(B1, half);

    add_polys(A0, A1, A0A1, half);
    add_polys(B0, B1, B0B1, half);

    // print_arr(A0A1, half);
    // print_arr(B0B1, half);

    iterative_poly(A0A1, half, B0B1, half, Y);
    iterative_poly(A0, half, B0, half, U);
    iterative_poly(A1, half, B1, half, Z);

    print_arr(Y, arrSize);
    print_arr(U, arrSize);
    print_arr(Z, arrSize);

    for (int i = 0; i < arrSize; i++)
    {
        last[i+half] = Y[i] - U[i] - Z[i];
    }

    for (int i = 0; i < arrSize; i++)
    {
        last[i] += U[i];
    }

    for (int i = 0; i < arrSize; i++)
    {
        last[i+p1Size] += Z[i];
    }
    print_arr(last, arrSize);
}

void add_polys(int *P1, int *P2, int *P3, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        P3[i] = P1[i] + P2[i];
    }
}

void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }

    printf("\n");
}

int main()
{
    int A[] = {2, 5, 3, 1, 5, 6};
    int aSize = 6;
    int B[] = {1, 2, 2, 3, 9, 10};
    int bSize = 6;

    conquer_poly(A, aSize, B, bSize);
}