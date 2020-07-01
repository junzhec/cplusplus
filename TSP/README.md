This project solves the problem of Travelling Salesman.

The program first ask user how many cities to be considered. Then it will generate a matrix that contains city name and distance between each city.

For example, the matrix may looks like following:

![alt text](https://github.com/junzhec/cplusplus/blob/master/TSP/genMat.png?raw=true)

Then the program will ask user for the starter city and display path and shortest distance:

![alt text](https://github.com/junzhec/cplusplus/blob/master/TSP/result.png?raw=true)

The program uses greedy algorithm that after knowing the starter city, the program will look for its nearest unvisited neighbor. the program will recursively look for unvisited nearest neighbor until all the cities are covered.
