#include <iostream>
using namespace std;

class Vect
{
  private:
    int arrSize;
    int *arrData;

  public:
    Vect(int n = 0);
    Vect(int arr[], int n);
    Vect(const Vect &v);
    ~Vect();
    int Size()
    {
        return arrSize;
    }
    int GetData(int i)
    {
        if (i < 0 || i >= arrSize)
        {
            cout << "out of boundary" << endl;
        }
        else
            return arrData[i];
    }
    void SetData(int i, int val)
    {
        if (i < 0 || i >= arrSize)
        {
            cout << "out of boundary" << endl;
        }
        else
            arrData[i] = val;
    }
    void PrintData()
    {
        if (arrSize > 0)
            cout << arrData[0];
        for (int i = 1; i < arrSize; i++)
        {
            cout << " " << arrData[i];
        }
        cout << endl;
    }
};

Vect::Vect(int n) : arrSize(n)
{
    arrData = new int[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        arrData[i] = 0;
    }
}

Vect::Vect(int arr[], int n) : arrSize(n)
{
    arrData = new int[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        arrData[i] = arr[i];
    }
}

Vect::Vect(const Vect &v) : arrSize(v.arrSize)
{
    arrData = new int[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        arrData[i] = v.arrData[i];
    }
}

Vect::~Vect()
{
    if (arrData)
    {
        delete[] arrData;
        arrSize = 0;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n;

    cin >> n;
    Vect v1(arr, 5), v2(n);
    v1.PrintData();
    v2.PrintData();

    int i, data;
    cin >> i >> data;
    v1.SetData(i, data);
    Vect v3(v1);
    v1.PrintData();
    v3.PrintData();

    return 0;
}