#include <stdio.h>

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right)   /* do nothing if array contains */
        return;           /* fewer than two elements */
    swap(v, left, (left + right)/2); /* move partition elem */
    last = left;                     /* to v[0] */
    for (i = left+1; i <= right; i++)   /* partition */
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);         /* restore partition elem */
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

/* swap:   interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int main()
{
    int v[5];
    v[0] = 1;
    v[1] = 2;
    v[2] = 5;
    v[3] = 6;
    v[4] = 1;
    int a = 1, b = 2;
    qsort(v, a, b);
    printf("qsort of %d and %d is\n", a, b);
    int j;
    for (j = 0; j <= 5; j++) 
        printf("%d\n",v[j]);
    return 0;
}