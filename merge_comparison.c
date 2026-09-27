#include <stdio.h>

#define K 3
#define SIZE 4
#define TOTAL 12

/* Structure for a Min Heap node */
typedef struct
{
    int value;
    int list;
    int index;
} HeapNode;

/* Min Heap */
typedef struct
{
    HeapNode arr[K];
    int size;
} MinHeap;


/* Swap two heap nodes */
void swap(HeapNode *a, HeapNode *b)
{
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}


/* Heapify Down */
void heapifyDown(MinHeap *heap, int i, int *comparisons)
{
    while (1)
    {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap->size)
        {
            (*comparisons)++;

            if (heap->arr[left].value <
                heap->arr[smallest].value)
            {
                smallest = left;
            }
        }

        if (right < heap->size)
        {
            (*comparisons)++;

            if (heap->arr[right].value <
                heap->arr[smallest].value)
            {
                smallest = right;
            }
        }

        if (smallest == i)
        {
            break;
        }

        swap(&heap->arr[i], &heap->arr[smallest]);
        i = smallest;
    }
}


/* Insert an element into Min Heap */
void insertHeap(MinHeap *heap, HeapNode node)
{
    int i = heap->size;

    heap->arr[i] = node;
    heap->size++;

    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (heap->arr[parent].value <=
            heap->arr[i].value)
        {
            break;
        }

        swap(&heap->arr[parent], &heap->arr[i]);

        i = parent;
    }
}


/* Remove minimum element */
HeapNode removeMin(MinHeap *heap, int *comparisons)
{
    HeapNode minNode = heap->arr[0];

    heap->size--;

    if (heap->size > 0)
    {
        heap->arr[0] = heap->arr[heap->size];

        heapifyDown(heap, 0, comparisons);
    }

    return minNode;
}


/* Display heap */
void printHeap(MinHeap *heap)
{
    printf("[ ");

    for (int i = 0; i < heap->size; i++)
    {
        printf("%d ", heap->arr[i].value);
    }

    printf("]");
}


/* K-Way Merge using Min Heap */
void kWayMerge(int lists[K][SIZE])
{
    MinHeap heap;

    heap.size = 0;

    int comparisons = 0;
    int output[TOTAL];
    int count = 0;

    /* Insert first element from every list */
    for (int i = 0; i < K; i++)
    {
        HeapNode node;

        node.value = lists[i][0];
        node.list = i;
        node.index = 0;

        insertHeap(&heap, node);
    }

    printf("\n====================================\n");
    printf(" K-WAY MERGE USING MIN HEAP\n");
    printf("====================================\n");

    printf("Initial Heap: ");
    printHeap(&heap);
    printf("\n\n");

    while (heap.size > 0)
    {
        HeapNode minNode;

        minNode = removeMin(&heap, &comparisons);

        output[count] = minNode.value;
        count++;

        /* Insert next element from same list */
        if (minNode.index + 1 < SIZE)
        {
            HeapNode nextNode;

            nextNode.list = minNode.list;
            nextNode.index = minNode.index + 1;

            nextNode.value =
                lists[minNode.list][nextNode.index];

            insertHeap(&heap, nextNode);
        }

        printf("Step %2d : Deleted %d\tHeap = ",
               count, minNode.value);

        printHeap(&heap);

        printf("\n");
    }

    printf("\nFinal K-Way Output:\n");

    for (int i = 0; i < TOTAL; i++)
    {
        printf("%d ", output[i]);
    }

    printf("\n");

    printf("Heap Comparisons = %d\n", comparisons);
}


/* Merge two sorted arrays */
int mergeTwo(
    int a[],
    int n1,
    int b[],
    int n2,
    int result[],
    int *comparisons)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n1 && j < n2)
    {
        (*comparisons)++;

        if (a[i] <= b[j])
        {
            result[k] = a[i];
            i++;
        }
        else
        {
            result[k] = b[j];
            j++;
        }

        k++;
    }

    /* Copy remaining elements */
    while (i < n1)
    {
        result[k] = a[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        result[k] = b[j];
        j++;
        k++;
    }

    return k;
}


/* Pairwise Merge */
void pairwiseMerge(int lists[K][SIZE])
{
    int firstMerge[SIZE * 2];
    int finalResult[TOTAL];

    int comparisons1 = 0;
    int comparisons2 = 0;

    int n1;
    int n2;

    printf("\n====================================\n");
    printf(" PAIRWISE MERGE\n");
    printf("====================================\n");

    /* Merge L1 and L2 */
    n1 = mergeTwo(
        lists[0],
        SIZE,
        lists[1],
        SIZE,
        firstMerge,
        &comparisons1
    );

    printf("\nAfter merging L1 and L2:\n");

    for (int i = 0; i < n1; i++)
    {
        printf("%d ", firstMerge[i]);
    }

    printf("\nComparisons = %d\n", comparisons1);


    /* Merge result with L3 */
    n2 = mergeTwo(
        firstMerge,
        n1,
        lists[2],
        SIZE,
        finalResult,
        &comparisons2
    );

    printf("\nAfter merging result with L3:\n");

    for (int i = 0; i < n2; i++)
    {
        printf("%d ", finalResult[i]);
    }

    printf("\nComparisons = %d\n", comparisons2);

    printf("\nFinal Pairwise Output:\n");

    for (int i = 0; i < n2; i++)
    {
        printf("%d ", finalResult[i]);
    }

    printf("\n");

    printf("\nTotal Pairwise Comparisons = %d\n",
           comparisons1 + comparisons2);
}


/* Main Function */
int main()
{
    int lists[K][SIZE] =
    {
        {10, 30, 50, 70},
        {20, 40, 60, 80},
        {15, 35, 55, 75}
    };

    printf("====================================\n");
    printf(" INPUT SORTED TRANSACTION LISTS\n");
    printf("====================================\n");

    printf("L1 : 10 30 50 70\n");
    printf("L2 : 20 40 60 80\n");
    printf("L3 : 15 35 55 75\n");

    /* K-Way Merge */
    kWayMerge(lists);

    /* Pairwise Merge */
    pairwiseMerge(lists);

    return 0;
}
