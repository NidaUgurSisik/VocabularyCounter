#include <iostream>
#include <string>
using namespace std;
int main()
{
    int i = 0, repeat[1000];
    string list[1000], temp, list2[1000];
    while (cin >> temp)
    {
        list[i] = temp;
        for (int j = 0; j < temp.length(); j++)
        {
            if (list[i][j] <= 'Z' && list[i][j] >= 'A')
                list[i][j] = list[i][j] - 'A' + 'a';
            else
                continue;
        }
        i++;
    }
    for (int k = 0; k < i; k++)
    {
        for (int l = 0; l < i; l++)
        {
            if (list[k] >= list[l])
                continue;
            else
            {
                temp = list[k];
                list[k] = list[l];
                list[l] = temp;
            }
        }
    }
    int check = 1, size = 0;
    for (int b = 0; b < i; b++)
    {
        if (list[b] == list[b + 1])
        {
            check++;
        }
        else if (list[b] != list[b + 1])
        {
            list2[size] = list[b];
            repeat[size] = check;
            check = 1;
            size++;
        }
    }
    cout << "Vocabulary Size = " << size << endl;
    for (int k = 0; k <= size - 1; k++)
        cout << list2[k] << " " << repeat[k] << endl;
}