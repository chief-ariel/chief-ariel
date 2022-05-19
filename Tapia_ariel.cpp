#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int rows = 5, col = 6;
string path[rows][col];

void calcosts() {
   static int weight[rows][col] = {{3,4,1,2,8,6},
                                            {6,1,8,2,7,4},
                                            {5,9,3,9,9,5},
                                            {8,4,1,3,2,6},
                                            {3,7,2,8,6,4}};
   static int cost [rows][col]; //cost remains same everytime its called

   // copy the leftest column of the weight matrix to the cost matrix then initialize
    for(int i = 0; i < rows; i++){
      cost[i][0] = weight[i][0];
      path[i][0] = to_string(i);
    }

   // For each remaining column,
      // Calculate the cost of each square in the column ,
      // and store the correct number in the cost matrix and the correct string in the path matrix.
   for(int i = 1; i < col; i++){
       for(int j = 0; j < rows; j++){

       //options for moving cheapest
       int up = cost[(j-1 + rows)%rows][i-1];  //next col (bottom up) J - 1
    int left = cost[j][i-1]; //
       int down = cost[(j+1)%rows][i-1];
        int minCost = min(min(up,down), left); // find minimum between up and down then minimum between that result and left to find overall min

       //if else depending on cheapest move then copy move to path matrix
      if(minCost==up)
        path[j][i] = path[(j-1 + rows) % rows][i-1] + to_string(j);


      else if(minCost==left)
         path[j][i] = path[j][i-1] + to_string(j);


      else
        path[j][i] = path[(j+1)%rows][i-1] + to_string(j);


      cost[j][i] = weight[j][i] + minCost;
     }
   }



   int minRow = 0;
   // Check which square in the rightmost column has the lowest cost.  Store the row number of that square in minRow
   for(int i = 0; i < rows; i++)
      if(cost[minRow][col-1] > cost[i][col-1])
        minRow = i;



  cout << "The length of the shortest path is " << cost[minRow][col-1];
  cout << ".\nThe rows of the path from left to right are " << path[minRow][col-1] << ".";
}

int main() {
   calcosts();

   return 0;
}
