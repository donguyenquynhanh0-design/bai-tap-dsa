#include <iostream>
using namespace std;

int main()
{
    int n, i, dem = 0;

    cout << "Nhap n: ";
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            dem++;
        }
    }

    if (dem == 2)
        cout << n << " la so nguyen to";
    else
        cout << n << " khong phai la so nguyen to";

    return 0;
}

