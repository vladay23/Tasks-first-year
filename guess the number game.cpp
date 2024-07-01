#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>

using namespace std;

int main()
{
    int hidden, guess, i=0, end=1, games;
    vector<pair<int, int>> res;
    pair<int, int>input;
    ofstream out("result.txt");
    cout<<" Guess the Number game"<<endl;
    cout<<" Specify the number of games: "<<endl; cin>>games;
    cout<<" The number from 1 to 100 is hidden."<<endl;
    if (out.is_open()){
        for (int j=1; j<=games; j++){
            i=0;
            end=1;
            srand(time(NULL));
            hidden=rand()%100;
            cout<<" The sequence number of the game: "<<j<<endl;
            cout<<" Enter the desired number: ";
            while(end){
                i++;
                cin>>guess;
                input={i, guess};
                res.push_back(input);
                if(guess==hidden){
                    cout<<" You've won!"<<endl;
                    cout<<" You guessed the number with "<<i<<" attempts!"<<endl;
                    end=0;
                }
                else if(guess>hidden) cout<<" No, the number you entered is bigger than what you intended.."<<endl;
                else cout<<" No, the number you entered is less than what you intended."<<endl;
            }
        for (const auto& input :res)
            out<<" Attempt number: "<<input.first<<". The entered number: "<<input.second<<endl;
        out<<" The hidden number: "<<hidden<<endl;
       }   
    }
    out.close();
    return 0;
}
