#include <iostream>
#include <vector>

using namespace std;

int main()
{ int disks,to,from,move=0, candidate;

    cout<< "Enter the number of disks to move : ";
    cin >> disks;

    vector <int> tower[3]; // array of 3 vectors that signify the towers




     //initialize the towers

    for(int i = disks+1; i > 0; i--){ // number of disks plus one, the extra one signifyies the tower itself
        tower[0].push_back(i);   // adds user inputted number of disks to first tower
    }
    tower[1].push_back(disks+1);
    tower[2].push_back(disks+1); // other towers just have "disks + 1" as the empty tower itself

    from = 0; //since were starting at 0 tower thats the "from" tower

    if((disks % 2) == 1) // depending on whether we have even or odd disks the to tower is either 1 or 2
        to = 1;
        else to = 2;


    candidate = 1; // next disk being moved


    while(tower[1].size() < disks + 1){ //while the "to" tower has less disks than the total number of disks we loop
    cout << "move number " << ++move<< ":  Transfer disk " << candidate << " from tower " << char(from + 65) << " to tower " <<char(to + 65) << endl;

    tower[to].push_back(tower[from].back());
    tower[from].pop_back();

     // get the next "from" tower -- it cant be the most recent "to" tower

     if(tower[(to + 1) % 3].back() < tower[(to + 2) % 3].back())
        from =(to + 1) % 3;
     else from =(to + 2) % 3;



     // get the next "to" tower --
    if((disks % 2) == 1){ // IF DISKS are odd
        if(tower[from].back() < tower[(from + 1) % 3].back())
          to =(from + 1) % 3;
        else to = (from + 2) % 3; // move to the right
    }

    else                                                       // IF DISKS are even
        if(tower[from].back() < tower[(from + 2) % 3].back())
            to =(from + 2) % 3;
        else to = (from + 1) % 3; // move to the left




    candidate = tower[from].back();

    }

}
