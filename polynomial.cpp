#include<stdio.h>
#include<math.h>

void print_arr(int arr[], int n);

// Input:  A[] = {5, 0, 10, 6} 
//         B[] = {1, 2, 4} 
// Output: prod[] = {5, 10, 30, 26, 52, 24}

// The first input array represents "5 + 0x^1 + 10x^2 + 6x^3"
// The second array represents "1 + 2x^1 + 4x^2" 
// And Output is "5 + 10x^1 + 30x^2 + 26x^3 + 52x^4 + 24x^5"

void iterative_poly(int poly1[], int p1Size, int poly2[], int p2Size)
{
    int arrSize = p1Size + p2Size - 1, k = 0, output;
    int newArr[50] = {0};
    for (int i = 0; i < p1Size; i++)
    {
        for (int j = 0; j < p2Size; j++)
        {
            output = poly1[i]*poly2[j];
            newArr[k] += output;
            k++;
        }
        k = k-2;
    }
    print_arr(newArr, arrSize);
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
    int A[] = {5, 0, 10, 6};
    int aSize = 4;
    int B[] = {1, 2, 4};
    int bSize = 3;

    iterative_poly(A, aSize, B, bSize);

}