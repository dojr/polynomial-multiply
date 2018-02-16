#include<stdio.h>

void print_arr(int arr[], int n);

// Input:  A[] = {5, 0, 10, 6} 
//         B[] = {1, 2, 4} 
// Output: prod[] = {5, 10, 30, 26, 52, 24}

// The first input array represents "5 + 0x^1 + 10x^2 + 6x^3"
// The second array represents "1 + 2x^1 + 4x^2" 
// And Output is "5 + 10x^1 + 30x^2 + 26x^3 + 52x^4 + 24x^5"

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
            output = poly1[i]*poly2[j];
            P3[k] += output;
            k++;
        }
        k = k-(p1Size-1);
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
    int A[] = {2, 5, 3, 1, 4, 3, 10};
    int aSize = 7;
    int B[] = {1, 2, 2, 3, 6, 5, 12};
    int bSize = 7;

    int outArr[aSize+bSize-1];
    init_arr(outArr, 13);
    iterative_poly(A, aSize, B, bSize, outArr);
    print_arr(outArr, 13);
}