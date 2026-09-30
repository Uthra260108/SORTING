#include <stdio.h>

/* ---------- Insertion Sort ---------- */
void insertionSort(int a[], int n)
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

/* ---------- Merge Sort ---------- */
void merge(int a[], int low, int mid, int high)
{
    int i, j, k;
    int temp[100];

    i = low;
    j = mid + 1;
    k = 0;

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }

        k++;
    }

    while (i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        temp[k] = a[j];
        j++;
        k++;
    }

    k = 0;

    for (i = low; i <= high; i++)
    {
        a[i] = temp[k];
        k++;
    }
}

void mergeSort(int a[], int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

/* ---------- Heap Sort ---------- */
void heapify(int a[], int n, int i)
{
    int largest;
    int left;
    int right;
    int temp;

    largest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    int i, temp;

    /* Build Max Heap */
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    /* Extract elements */
    for (i = n - 1; i > 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}

/* ---------- Quick Sort 1 ---------- */
void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int partition1(int a[], int low, int high)
{
    int pivot, i, j;

    pivot = a[low];
    i = low;

    for (j = low + 1; j <= high; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[low], &a[i]);

    return i;
}

void quickSort1(int a[], int low, int high)
{
    int p;

    if (low < high)
    {
        p = partition1(a, low, high);

        quickSort1(a, low, p - 1);
        quickSort1(a, p + 1, high);
    }
}

/* ---------- Quick Sort 2 ---------- */
int partition2(int a[], int p, int r)
{
    int pv, i, j;

    pv = a[p];

    i = p + 1;
    j = r;

    do
    {
        while (i <= r && a[i] < pv)
            i++;

        while (j >= p && a[j] >= pv)
            j--;

        if (i < j)
            swap(&a[i], &a[j]);

    } while (i < j);

    swap(&a[p], &a[j]);

    return j;
}

void quickSort2(int a[], int p, int r)
{
    int q;

    if (p < r)
    {
        q = partition2(a, p, r);

        quickSort2(a, p, q - 1);
        quickSort2(a, q + 1, r);
    }
}

/* ---------- Counting Sort ---------- */
void countingSort(int A[], int B[], int n)
{
    int C[100] = {0};
    int i;
    int max = A[0];

    /* Find maximum element */
    for (i = 1; i < n; i++)
    {
        if (A[i] > max)
            max = A[i];
    }

    /* Initialize count array */
    for (i = 0; i <= max; i++)
        C[i] = 0;

    /* Count elements */
    for (i = 0; i < n; i++)
        C[A[i]]++;

    /* Cumulative frequency */
    for (i = 1; i <= max; i++)
        C[i] = C[i] + C[i - 1];

    /* Place elements in output array */
    for (i = n - 1; i >= 0; i--)
    {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }

    /* Copy B to A */
    for (i = 0; i < n; i++)
        A[i] = B[i];
}

/* ---------- Display ---------- */
void display(int a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

/* ---------- Main Function ---------- */
int main()
{
    int a[100], B[100];
    int n, i, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\n");
    printf("===== SORTING MENU =====\n");
    printf("1. Insertion Sort\n");
    printf("2. Merge Sort\n");
    printf("3. Heap Sort\n");
    printf("4. Quick Sort - 1\n");
    printf("5. Quick Sort - 2\n");
    printf("6. Counting Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            insertionSort(a, n);
            break;

        case 2:
            mergeSort(a, 0, n - 1);
            break;

        case 3:
            heapSort(a, n);
            break;

        case 4:
            quickSort1(a, 0, n - 1);
            break;

        case 5:
            quickSort2(a, 0, n - 1);
            break;

        case 6:
            countingSort(a, B, n);
            break;

        default:
            printf("Invalid choice!\n");
            return 0;
    }

    printf("\nSorted array: ");
    display(a, n);

    return 0;
}
