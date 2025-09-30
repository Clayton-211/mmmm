#include <iostream>
#include <cstring>
using namespace std;

struct record
{
    char name[10];
    int telephone_number;
};

int main()
{
    int size = 10;
    record HT[size];

   
    for (int i = 0; i < size; i++)
    {
        strcpy(HT[i].name, "none");
        HT[i].telephone_number = -1;
    }

    int n;
    cout << "Enter number of clients (max 10): ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char tname[10];
        int temp_number;

        cout << "\nEnter client name: ";
        cin >> tname;
        cout << "Enter telephone number: ";
        cin >> temp_number;

        
        int sum = 0, j = 0;
        while (tname[j] != '\0')
        {
            sum += tname[j];
            j++;
        }

        int index = sum % size;
        cout << "\nHash value for " << tname << " is: " << index;

        
        if (HT[index].telephone_number == -1)
        {
            strcpy(HT[index].name, tname);
            HT[index].telephone_number = temp_number;
        }
        else
        {
            int k;
            for (k = 1; k < size; k++)
            {
              int nindex = (index + k) % size;
             cout << "\nProbing at index " << nindex;
             cout << " (name=" << HT[nindex].name;
             cout << ", tel=" << HT[nindex].telephone_number << ")\n";

 


        if (HT[nindex].telephone_number == -1)
        {
            strcpy(HT[nindex].name, tname);
            HT[nindex].telephone_number = temp_number;
            break;
        }
    }
    if (k == size)
    {
        cout << "Hash table overflow! Could not insert " << tname << "\n";
    }
        }
    }

   
    cout << "\n\nHash Table:\n";
    for (int i = 0; i < size; i++)
    {
        cout << HT[i].name << " " << HT[i].telephone_number << endl;
    }

    return 0;
}
