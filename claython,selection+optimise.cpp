#include <iostream>
using namespace std;

void selection_sort(float percentage[], int n) 
{
    float temp;
    
    for (int i = 0; i < n - 1; i++) 
    {
        int swap = 0;
        int comparisons = 0;

        for (int j = 0; j < n - 1 - i; j++) 
        {
            comparisons++;
            if (percentage[j] > percentage[j + 1]) 
            {
                temp = percentage[j];
                percentage[j] = percentage[j + 1];
                percentage[j + 1] = temp;
                swap = 1;
            }
        }
        
        cout << "\nPass no. = " << i + 1 << endl;
        cout << "No. of comparisons = " << comparisons << endl;

        cout << "o/p " << i + 1 << ": ";
        for (int i = 0; i < n; i++) 
        {
            cout << percentage[i] << " ";
        }
        cout << endl;

        if (swap == 0)
            break;  
    }
}

int main() {
    int n;

    cout << "Enter number of students in first year: ";
    cin >> n;

    float percentage[n];  

    for (int i = 0; i < n; i++) {
        cout << "Enter percentage for student " << i + 1 << ": ";
        cin >> percentage[i];
    }

    selection_sort(percentage, n);

    cout << "\nPercentages in ascending order:\n";
    for (int i = 0; i < n; i++) {
        cout << percentage[i] << " ";
    }
    cout << endl;

    return 0;
}
