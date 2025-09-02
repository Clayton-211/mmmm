#include <iostream>
using namespace std;

#define INF 999

void printMatrix(int size, int matrix[][10]) { 
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] == INF)
                cout << "INF\t";
            else
                cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void floydWarshall(int size, int graph[][10]) {  
    
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            matrix[i][j] = graph[i][j];
    
    
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }
    
    
    printMatrix(size, matrix);
}

int main() {
    int no_of_vertices;
    
    cout << "Enter number of vertices: ";
    cin >> no_of_vertices;

    int MyGraph[10][10];  
    
    cout << "\nEnter graph elements (use " << INF << " for infinity):\n";
    for (int i = 0; i < no_of_vertices; i++) {
        for (int j = 0; j < no_of_vertices; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> MyGraph[i][j];
        }
    }

   
    cout << "\nYour graph elements:\n";
    for (int i = 0; i < no_of_vertices; i++) {
        for (int j = 0; j < no_of_vertices; j++) {
            cout << MyGraph[i][j] << "\t";
        }
        cout << endl;
    }

    floydWarshall(no_of_vertices, MyGraph);

    return 0;
}


























