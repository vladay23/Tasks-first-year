#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>

using namespace std;

int main(){
    int hidden, guess, i=0, end=1, games;
    vector<pair<int, int>> res;
    pair<int, int>input;
    ofstream out("result.txt");
    cout<<" Игра Угадай число"<<endl;
    cout<<" Укажите количество игр: "<<endl; cin>>games;
    cout<<" Загадано число от 1 до 100."<<endl;
    if (out.is_open()){
        for (int j=1; j<=games; j++){
            i=0;
            end=1;
            srand(time(NULL));
            hidden=rand()%100;
            cout<<" Номер игры: "<<j<<endl;
            cout<<" Введите загаданное число: ";
            while(end){
                i++;
                cin>>guess;
                input={i, guess};
                res.push_back(input);
                if(guess==hidden){
                    cout<<" Вы выиграли!"<<endl;
                    cout<<" Вы отгадали число с "<<i<<"-ой попытки!"<<endl;
                    end=0;
                }
                else if(guess>hidden) cout<<" Нет, введённое Вами число, больше задуманного."<<endl;
                else cout<<" Нет, введённое Вами число, меньше задуманного."<<endl;
            }
        for (const auto& input :res)
            out<<" Номер попытки: "<<input.first<<" Введенное число: "<<input.second<<endl;
        out<<" Загаданное число: "<<hidden<<endl;
       }   
    }
    out.close();
    return 0;
}
