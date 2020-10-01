

#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
int size;

void Insert(int arr[], int hfn, int size)
{
    int ele, n = 0;

    cout << "Enter the element to store " << endl;
    cin >> ele;

    int ind = ele % hfn;

    while (arr[ind] != INT_MIN)
    {
        if (arr[ind] == INT_MAX)
        {
            break;
        }
        n++;
        ind = (ind + 1) % hfn;
        if (n == size)
        {
            break;
        }
    }

    if (n == size)
    {
        cout << "Hash table is full" << endl;
    }
    else
    {
        cout << "Inserted" << endl;
        arr[ind] = ele;
    }
}

void Delete(int arr[], int hfn, int size)
{
    int ele, n = 0, ind;

    cout << "Element to delete" << endl;
    cin >> ele;

    ind = ele % hfn;

    while (n++ != size)
    {
        if (arr[ind] == ele)
        {
            cout << "Element deleted" << endl;
            arr[ind] = INT_MAX;
            break;
        }
        else if (arr[ind] == INT_MIN)
        {
            cout << "Element does not exist" << endl;
            break;
        }
        else
        {
            ind = (ind + 1) % hfn;
        }
    }

    if (n == size)
    {
        cout << "Element not found" << endl;
    }
}

void Searching(int arr[], int hfn, int size)
{
    int ele, n = 0, ind = 0;

    cout << "Element to find : " << endl;
    cin >> ele;

    ind = ele % hfn;

    while (n++ != size)
    {
        if (arr[ind] == ele)
        {
            cout << "Element founded" << endl;
            break;
        }
        else if (arr[ind] == INT_MIN)
        {
            cout << "Element does not exist" << endl;
            break;
        }
        else
        {
            ind = ind % hfn;
        }
    }

    if (n == size)
    {
        cout << "Element does not exist " << endl;
    }
}

void Display(int arr[], int hfn, int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    fastio;
    int size, hfn, choice;

    cout << "size of hash function : ";
    cin >> size;

    cout << "hash function : ";
    cin >> hfn;

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = INT_MIN;
    }

    do
    {
        cout << "Enter your choice";
        cout << "1 -> Insert \n 2 -> Delete \n 3 -> Searching \n 4 -> display \n 0 ->Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            Insert(arr, hfn, size);
            break;
        case 2:
            Delete(arr, hfn, size);
            break;
        case 3:
            Searching(arr, hfn, size);
            break;
        case 4:
            Display(arr, hfn, size);
            break;

        default:
            cout << "Enter the correct option" << endl;
            break;
        }
    } while (choice);

    return 0;
}
