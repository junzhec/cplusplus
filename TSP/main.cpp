#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

int main () {
	int size;
    cout << "Please enter number of city: " << endl;
    cin >> size;
    cout << "Total number of cities is: " << size << endl;
    
    string my_array[size][size];

    my_array[0][0] = "x";

    int x = 97;
    char c;
    

    for (int k=1; k != size; k++)
    {
        c = static_cast<char>(x);
        x++;
        my_array[k][0] = c;
        my_array[0][k] = c;
    }

    for (int i=1; i != size; i++) {
        my_array[i][i] = "x";
        for (int j=i+1; j != size; j++) {

            int v2 = rand() % 40 + 10;
            my_array[i][j] = std::to_string(v2);
            my_array[j][i] = std::to_string(v2);
            
        }
    }

    for (int i=0; i != size; i++) {
        for (int j=0; j != size; j++) {
            cout << my_array[i][j] << "\t";
        }
        cout << endl;
    }
    std::string start;
    cout << "Please enter the start city: " << endl;
    cin >> start;
    cout << "The start city is: " << start << endl;

    int shortest;
    
    int matchIndex;
    string path(start + " -> ");

    int totalD = 0;
    vector<string> visited;
    
    visited.push_back(start);

    for (int i=1; i != size; i++){
        if (start.compare(my_array[i][0]) == 0)
        {
            matchIndex = i;
        }
    }

    int j = 0;

    for (int lopVar = 1; lopVar < (size-1); lopVar++)
    {


    if (matchIndex == 1)
    {
        j = 2;
    }
    else{
        j = 1;
    }

    int localMin = 999;
    int MinIndex = j;

    while (j < size)
    {
        
        if (my_array[matchIndex][j].compare("x") == 0)
        {
        }
        else{
            if (std::stoi(my_array[matchIndex][j]) < localMin)
            {
                if(!(std::find(visited.begin(), visited.end(), my_array[0][j]) != visited.end()))
                {
                    localMin = std::stoi(my_array[matchIndex][j]);
                    MinIndex = j;
                }
                
            }
        }
        j++;
    }

    totalD = totalD + localMin;
    path = path + my_array[0][MinIndex] + " -> ";
    visited.push_back(my_array[0][MinIndex]);
    matchIndex = MinIndex;
}

    

    cout << "Path: " << path << start << endl;
    cout << "Total Distance: " << totalD << endl;
}