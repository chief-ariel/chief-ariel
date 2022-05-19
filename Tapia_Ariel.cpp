#include <iostream>



using namespace std;

bool ok(int q[], int c) {
    int hlpr[8][5]={
        {-1}, // square 0
        {0,-1}, // square 1
        {0,-1}, // square 2
        {0,1,2,-1},// square 3
        {0,1,3,-1}, // square 4
        { 1,4,-1},// square 5
        {2,3,4,-1},// square 6
        {3,4,5,6,-1} // square 7


    };

    for (int i=0;i<c;i++){
        if(q[c]==q[i]) return false;

    };

    for (int i = 0; hlpr[c][i]!=-1 ; i++){ // loop until helper array inside of q[c] reaches -1 checking adjacents of square c
        if(abs(q[c] - q[hlpr[c][i]]) == 1) return false;//if whatever is inside of q[c] has an adjacent of either +1 or -1
        }
        return true; //if none of the others were true then it is so valid
}

void print(int q[],int c) {
   static int solutions = 1;

   cout << "Solutions #" << solutions << ":" << endl;
   cout << " " << " " << q[0] << q[1] << endl;
   cout << " " << q[2] << q[3] << q[4] << q[5] << endl;
   cout << " " << " " << q[6] << q[7] << endl;

   cout << endl;
   solutions++;
}

void backtrack(int q[], int &c){//idk why it works only with address of c and not c itself
    c--;
   if (c < 0) exit(1); //once loop stops program exits
   q[c]++;
   if (q[c] == 9) backtrack(q, c); // stops backtracked column from going over 8
 }







int main() {
   int q[8] = {1,1,1,1,1,1,1,1};
   int c = 1;



   while (c > -1)
   {
         if (c == 8)//found a solution
         {
          print(q,c); //print and backtrack
          backtrack(q, c);
         }
 if (q[c] == 9) backtrack(q, c); //if q[c] goes over 8 it will get backtracked
     if (ok(q, c) == true)
     {

       c++;//increment c
       if (c < 9) q[c] = 1; /// reset c
     }


     else q[c]++; // if number isnt valid increment row
   }
 }




