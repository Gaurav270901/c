#include <stdio.h>
void main()
{

    int size, shift, t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d%d", &size, &shift);
        int arr[size], arr1[size];

        for (int i = 0; i < size; i++)
        {
            arr[i] = i + 1;
        }

        for (int k = 0; k < shift; k++)
        {

            int j = 0;
            for (int i = 0; i < size / 2 && j < size; i++)
            {
                arr1[i] = arr[j];
                j = j + 2;
            }

            j = 1;
            for (int i = size / 2; i < size && j <= size; i++)
            {
                arr1[i] = arr[j];
                j = j + 2;
            }

            for (int i = 0; i < size; i++)
            {
                arr[i] = arr1[i];
            }
        }

        for (int i = 0; i < size; i++)
        {
            printf("%d\t", arr[i]);
        }
        printf("\n");
    }
}