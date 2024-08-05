#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int guessed;
    int random;
    srand(time(0));
    random = rand()%101;
    cout <<  random << endl;
    
    for (int i = 0; i < 5; ++i){
        cin >> guessed;
        if(guessed != random && i < 4){
            if(guessed > random ){ 
                cout << "Guess lower" << endl ;
            }else{
                cout << "Guess higher" << endl ;
            }
        }else if(guessed != random && i == 4){
            cout << "You lose" << endl ;
        }else if(guessed == random){
            cout << "You win" << endl;
            break;
        }
    }

}
