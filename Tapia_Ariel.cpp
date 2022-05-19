#include <iostream>
#include <cmath>
using namespace std;

bool okay(int q[], int c, int n) {
    for (int i = 0; i < c; i++)// loops through the 1-d array up to current column


        if ((q[c]/n - q[i]/n) == abs(q[c]%n - q[i]%n)) // if col difference == row difference, bishop c and i are diagonal to each other
             // row # = q[...] % n
            // col # = q[...] / n
         return false;
   return true;
}

int kBishops(int n, int k) {

    int* q = new int[k];// allocate memory for the array based on k (num of bishops)

    // place bishop at firstbox
    q[0] = 0;

    int c = 0, solutions = 0;


    while (c >= 0) {
        c++;// increment column


        if (c == k) {  // if end of board is reached increment solution counter and backtrack

          solutions++;
          c--;
        }
        else

            q[c] = q[c-1]; // decrement row to avoid duplicate solutions

        while (c >= 0) {

         q[c]++; // increment row

            if (q[c] == n*n) // if you reach the end of the last column
                // backtrack
                c--;


                else if (okay(q, c, n)) break;// ok function for bishops
        }
    }


    delete [] q;// delete array so memory returns
    return solutions;
}

int main() {

    int n, k;// n is size of one column (n*n = board size); K is number of bishops





    while (true) { // infinite loop for inputs

      cout << "Enter value of n: ";
      cin >> n;

      if (n == -1) // if user inputs -1 break.
         break;

      cout << "Enter number of bishops k: ";


      cin >> k;


      cout << "number of solutions: " << kBishops(n, k) << "\n"; // calls kBishop method to get solutions
    }
  return 0;
}
