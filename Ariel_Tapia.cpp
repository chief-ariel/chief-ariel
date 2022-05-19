#include <iostream>

using namespace std;
bool okay (int q[]){ // so valid

    for(int c=7;c>0;c--){ // loopin backwards


          for ( int i = 0; i < c ; i++){
            // loops through the 1-d array up to current column
          if(q[i] == q[c] || (c-i)== abs(q[c]- q[i])) return false;// if the row numbers are equal they are on the same row and if the absolute difference of rows and columns are equal theres a diagonal conflict
          }


    }






}
void print (int q[],int solutions){

     for(int i= 0; i< 8; i++){
            cout << endl;
            for(int j = 0; j < 8; j++){
                if (q[j]==i)
                    cout << "1";
                else
        cout << "0";


}
    }

cout << "solutions: " << solutions << endl;






}

int main()
{                    // c = column
    int q [8] = {0}; int c = 9; int solutions = 0; // (q [0,1,2,3,4,5,6,7) = the columns

    for (int i0 = 0;i0<8;i0++)
        for (int i1 = 0;i1<8;i1++)

          for (int i2 = 0;i2<8;i2++)

            for (int i3 = 0;i3<8;i3++)

              for (int i4 = 0;i4<8;i4++)

                for (int i5 = 0;i5<8;i5++)

                  for (int i6 = 0;i6<8;i6++)

                    for (int i7 = 0;i7<8;i7++)
                        {q[0]=i0;

                        q[1]=i1;

                        q[2]=i2;

                        q[3]=i3;

                        q[4]=i4;

                        q[5]=i5;

                        q[6]=i6;

                        q[7]=i7;

                        if(okay(q) == true)
                            print(q,++solutions);

                        }



















}
