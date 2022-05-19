#include <iostream>
#include <cmath>


using namespace std;

void Print(int q[]){
    static int solution = 0;
    solution++;
    for(int i= 0; i< 8; i++){
            cout << endl;
            for(int j = 0; j < 8; j++){
                if (q[j]==i)
                    cout << "1";
                else
        cout << "0";



}
    }
    cout << "solutions: " << solution;

}
bool okay (int q[],int c){ // so valid


          for ( int i = 0; i < c ; i++){ // loops through the 1-d array up to current column
          if(q[i] == q[c] || (c-i)== abs(q[c]- q[i])) // if the row numbers are equal they are on the same row and if the absolute difference of rows and columns are equal theres a diagonal conflict (giga brain asf)
           return false;
          }


            return true;







}
void backtrack(  int q[],int &c){
    c--;
    if(c ==-1){
        exit(1);
    }
    q[c]++;
    if(q[c]==8) backtrack(q,c);





}


int main()
{                    // c = column
    int q [8] = {0};int c = 1; // (q [0,1,2,3,4,5,6,7) = the columns
                //  q[0] = 0 because thats where we start putting the queen on the upper left square
    q [0] = 0;

while(c != -1){

        if (c==8){
        Print(q);
        backtrack(q,c);
                }


      if(q[c] == 8 ){

    backtrack(q,c);

        }

      if(okay (q, c)== true){
                c++;
                if (c < 9) q[c] = 0;


      }
      else q[c]++;









    }
}
