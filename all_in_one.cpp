#include<bits/stdc++.h>
using namespace std;
int option;
int bubble_sort()
{
    cout << "\t\t\t\t\t\tWelcome to bubblesort\n";
    int i,n, j,temp,pass=0;
    cout << "How many element you want to Input :";
    cin >> n;
    int a[n];
    cout << " Enter elements :";
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout <<"Input list ...\n";
    for(i = 0; i<n; i++)
    {
        cout <<a[i]<<"\t";
    }
    cout<<endl;
    for(i = 0; i<n; i++)
    {
        for(j = i+1; j<n; j++)
        {
            if(a[j] < a[i])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        pass++;
    }
    cout <<"Sorted Element List ...\n";
    for(i = 0; i<n; i++)
    {
        cout <<a[i]<<"\t";
    }
}
void selection_sort()
{
    cout << "\t\t\t\t\t\tWelcome to selection sort\n";
    int i,j,n,loc,temp,min;
    cout << "Enter the number of elements:";
    cin>>n;
    int a[n];
    cout <<"\nEnter the elements\n";

    for(i=0; i<n; i++)
    {
        cin >> a[i];
    }

    for(i=0; i<n-1; i++)
    {
        min=a[i];
        loc=i;
        for(j=i+1; j<n; j++)
        {
            if(min>a[j])
            {
                min=a[j];
                loc=j;
            }
        }

        temp=a[i];
        a[i]=a[loc];
        a[loc]=temp;
    }

    cout << "\nSorted list is as follows\n";
    for(i=0; i<n; i++)
    {
        cout << a[i] << "\t";
    }
}
void insertion_sort()
{
    cout << "\t\t\t\t\t\tWelcome to insertion sort\n";
    int i,j,n,temp;
    cout<<"Enter the number of elements:";
    cin>>n;
    int a[n];
    cout<<"\nEnter the elements\n";

    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }

    for(i=1; i<=n-1; i++)
    {
        temp=a[i];
        j=i-1;

        while((temp<a[j])&&(j>=0))
        {
            a[j+1]=a[j];
            j=j-1;
        }

        a[j+1]=temp;
    }

    cout<<"\nSorted list is as follows\n";
    for(i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
}
void heapify(int arr[], int n, int root)
{
    int largest = root;
    int l = 2*root + 1;
    int r = 2*root + 2;


    if (l < n && arr[l] > arr[largest])
        largest = l;


    if (r < n && arr[r] > arr[largest])
        largest = r;


    if (largest != root)
    {

        swap(arr[root], arr[largest]);


        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n)
{
    cout << "\t\t\t\t\t\tWelcome to heapsort\n";
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}
void heap_sort()
{
    int n,i;
    cout << "How many elements you want to insert :";
    cin >> n;
    int arr[n];
    cout << "enter the elements: ";
    for (int i=0; i<n; ++i)
        cin >> arr[i];
    cout<<"Input array\n"<<endl;
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";

    heapSort(arr, n);

    cout << "\nSorted array\n"<<endl;
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
}
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;


    int L[n1], R[n2];


    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;

    int j = 0;

    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int l,int r)
{
    if(l>=r)
    {
        return;
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}


void merge_sort()
{
    cout << "\t\t\t\t\t\tWelcome merge sort\n";
    int n;
    cout << "How many elements you want to insert :";
    cin >> n;
    int arr[n];
    cout << "Enter the elements :";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";

}
int getMax(int array[], int size)
{
    int max = array[1];
    for(int i = 2; i <= size; i++)
    {
        if(array[i] > max)
            max = array[i];
    }
    return max;
}
void countSort(int *array, int size)
{
    int output[size+1];
    int max = getMax(array, size);
    int count[max+1];
    for(int i = 0; i <= max; i++)
        count[i] = 0;
    for(int i = 1; i <= size; i++)
        count[array[i]]++;
    for(int i = 1; i <= max; i++)
        count[i] += count[i-1];
    for(int i = size; i >= 1; i--)
    {
        output[count[array[i]]] = array[i];
        count[array[i]] -= 1;
    }
    for(int i = 1; i<=size; i++)
    {
        array[i] = output[i];
    }
}
void counting_sort()
{
    cout << "\t\t\t\t\t\tWelcome to counting sort\n";
    int n;
    cout << "Enter how many numbers you want to insert: ";
    cin >> n;
    int arr[n+1];
    cout << "Enter the numbers: ";
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    countSort(arr, n);
    cout << "Sorted list: ";

    for(int i = 1; i <= n; i++)
        cout << arr[i] << " ";
}
int binarySearch(int a[], int first, int last, int search_num)
{
    int middle;
    if(last >= first)
    {
        middle = (first + last)/2;

        if(a[middle] == search_num)
        {
            return middle+1;
        }


        else if(a[middle] < search_num)
        {
            return binarySearch(a,middle+1,last,search_num);
        }

        else
        {
            return binarySearch(a,first,middle-1,search_num);
        }

    }
}
void binary_search()
{
    cout << "\t\t\t\t\t\tWelcome to binary search\n";
    int n;
    cout << "How many number you want to insert : ";
    cin >> n;
    int num[n];
    cout << "Enter the numbers: ";
    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    int search_num, loc=-1;

    cout<<"Enter the number that you want to search: ";
    cin>>search_num;

    loc = binarySearch(num, 0, 6, search_num);

    if(loc != -1)
    {
        cout<<search_num<<" found in the array at the location: "<<loc;
    }
    else
    {
        cout<<"Element not found";
    }

}
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
int queuee[100], n = 100, front = - 1, rear = - 1;
void Insert()
{
    int val;
    if (rear == n - 1)
        cout<<"Queue Overflow"<<endl;
    else
    {
        if (front == - 1)
            front = 0;
        cout<<"Insert the element in queue : "<<endl;
        cin>>val;
        rear++;
        queuee[rear] = val;
    }
}
void Delete()
{
    if (front == - 1 || front > rear)
    {
        cout<<"Queue Underflow ";
        return ;
    }
    else
    {
        cout<<"Element deleted from queue is : "<< queuee[front] <<endl;
        front++;;
    }
}
void Display()
{
    if (front == - 1)
        cout<<"Queue is empty"<<endl;
    else
    {
        cout<<"Queue elements are : ";
        for (int i = front; i <= rear; i++)
            cout<<queuee[i]<<" ";
        cout<<endl;
    }
}
void queue_operation()
{
    cout << "\t\t\t\t\t\tWelcome to queue operration\n";
    int choice;
    cout<<"1) Insert element to queue"<<endl;
    cout<<"2) Delete element from queue"<<endl;
    cout<<"3) Display all the elements of queue"<<endl;
    cout<<"4) Exit"<<endl;
    do
    {
        cout<<"Enter your choice : "<<endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            Insert();
            break;
        case 2:
            Delete();
            break;
        case 3:
            Display();
            break;
        case 4:
            cout<<"Exit"<<endl;
            break;
        default:
            cout<<"Invalid choice"<<endl;
        }
    }
    while(choice!=4);
}

void linear_search()
{
    cout << "\t\t\t\t\t\tWelcome to linear search\n";
    int n;
    cout << "How many item you want to insert :";
    cin >> n;
    int arr[n];
    cout << "Enter the elements : ";
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cout << "Input the element you want to search: ";
    cin >> x;

    int index = search(arr, n, x);
    if (index == -1)
        cout << "Element is not present in the array";
    else
        cout << "Element found at position " << index;
}
int stackk[100], num=100, top=-1;
void push(int val)
{
    if(top >= n-1)
        cout<<"Stack Overflow"<<endl;
    else
    {
        top++;
        stackk[top]=val;
    }
}
void pop()
{
    if(top <= -1)
        cout << "Stack Underflow" << endl;
    else
    {
        cout << "The popped element is " << stackk[top] <<endl;
        top--;
    }
}
void display_1()
{
    if(top>=0)
    {
        cout<<"Stack elements are:";
        for(int i=top; i>=0; i--)
            cout<<stackk[i]<<" ";
        cout<<endl;
    }
    else
    {
        cout<<"Stack is empty";
    }

}
void stack_operation()
{
    cout << "\t\t\t\t\t\tWelcome to stack operation\n";
    int choice, val;
    cout<<"1) Push in stack"<<endl;
    cout<<"2) Pop from stack"<<endl;
    cout<<"3) Display stack"<<endl;
    cout<<"4) Exit"<<endl;
    do
    {
        cout<<"\nEnter choice: "<<endl;
        cin >> choice;
        switch(choice)
        {
        case 1:
        {
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val;
            push(val);
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display_1();
            break;
        }
        case 4:
        {
            cout<<"Exit"<<endl;
            break;
        }
        default:
        {
            cout<<"Invalid Choice"<<endl;
        }
        }
    }
    while(choice!=4);
}

main()
{
main_menu:
    cout <<"                                                 Name: Rahat Kabir Dharubo\n";
    cout <<"                                                         Batch: 53\n";
    cout <<"                                                         Roll: 49\n";
    cout <<"                                     Project on all algorithm in one program using udf\n";
    int choice;
    while(1)
    {
        cout << "\n................................................Please Select Your Option..............................................." << endl;
        cout << "................................................     1. Bubble Sort      ..............................................." << endl;
        cout << "................................................   2. Selection Sort     ..............................................." << endl;
        cout << "................................................   3. Insertion Sort     ..............................................." << endl;
        cout << "................................................      4. Heap Sort       ..............................................." << endl;
        cout << "................................................     5. Merge Sort       ..............................................." << endl;
        cout << "................................................   6. Counting Sort      ..............................................." << endl;
        cout << "................................................   7. Binary Search      ..............................................." << endl;
        cout << "................................................   8. Linear Search      ..............................................." << endl;
        cout << "................................................         9.Queue         ..............................................." << endl;
        cout << "................................................        10.Stack         ..............................................." << endl;


        cout << "................................................    Enter your Choice    ..............................................." << endl;
        cin >> choice;
        switch(choice)
        {
        case 1 :

            bubble_sort();
            cout << "\ndo you want to back in the main menu\n\t 1.yes \t2.NO\n";
            cin >> option;
            if (option == 1)
            {
                system("CLS");
                goto main_menu;

            }
            break;
        case 2 :

            selection_sort();
            cout << "\ndo you want to back in the main menu\n\t 1.yes \t2.NO\n";
            cin >> option;
            if (option == 1)
            {
                system("CLS");
                goto main_menu;

            }
            break;
        case 3 :

            insertion_sort();
                cout << "\ndo you want to back in the main menu\n\t 1.yes \t2.NO\n";
            cin >> option;
            if (option == 1)
            {
                system("CLS");
                goto main_menu;

            }
            break;
        case 4 :

            heap_sort();
              cout << "\ndo you want to back in the main menu\n\t 1.yes \t2.NO\n";
            cin >> option;
            if (option == 1)
            {
                system("CLS");
                goto main_menu;

            }
            break;
        case 5 :

            merge_sort();
            cout << "\ndo you want to back in the main menu\n\t 1.yes \t2.NO\n";
            cin >> option;
            if (option == 1)
            {
                system("CLS");
                goto main_menu;

            }
            break;
        case 6 :

            counting_sort();
            cout << "\ndo you want to back in the main menu\n\t 1.yes \t2.NO\n";
            cin >> option;
            if (option == 1)
            {
                system("CLS");
                goto main_menu;

            }
            break;
        case 7:

            binary_search();
            cout << "\ndo you want to back in the main menu\n\t 1.yes \t2.NO\n";
            cin >> option;
            if (option == 1)
            {
                system("CLS");
                goto main_menu;

            }
            break;
        case 8:

            linear_search();
             cout << "\ndo you want to back in the main menu\n\t 1.yes \t2.NO\n";
            cin >> option;
            if (option == 1)
            {
                system("CLS");
                goto main_menu;

            }
            break;
        case 9:

            queue_operation();
              cout << "\ndo you want to back in the main menu\n\t 1.yes \t2.NO\n";
            cin >> option;
            if (option == 1)
            {
                system("CLS");
                goto main_menu;

            }
            break;
        case 10:

            stack_operation();
            cout << "\ndo you want to back in the main menu\n\t 1.yes \t2.NO\n";
            cin >> option;
            if (option == 1)
            {
                system("CLS");
                goto main_menu;

            }
            break;

        default:
            cout << "\nplease enter right option\n";
            goto main_menu;
        }
        cout << endl;
    }

}




