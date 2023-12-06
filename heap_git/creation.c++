#include <iostream>
#include <vector>
using namespace std;

class heap_for
{
public:
    int arr[100];
    int size;
    int length;

    heap_for()
    {
        arr[0] = -1;
        size = 0;
    }

    void inserting(int value)
    {
        size = size + 1;
        int index = size;
        arr[index] = value;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }

        length = size;
    }

    void heap_delete()
    {
        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i < size)
        {
            int left = 2 * i;
            int right = 2 * i + 1;

            if (left < size && arr[left] > arr[i])
            {
                swap(arr[left], arr[i]);
                i = left;
            }

            else if (right < size && arr[right] > arr[i])
            {
                swap(arr[right], arr[i]);
                i = right;
            }
            else
            {
                return;
            }
        }
    }

   

    void print()
    {
        cout << "heap representation " << endl;
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
    }

   
   
};





int main()
{
    heap_for heap;
    for (int i = 0; i < 7; i++)
    {
        cout << "enter "
             << " ";
        int a;
        cin >> a;
        cout << endl;
        heap.inserting(a);
    }
    heap.print();
    //    heap.head_delete();
    //    cout<<endl;

    
    return 0;
}