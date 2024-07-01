#include <iostream>
#include <vector>
#include <cfloat>
#include <math.h>
#include <algorithm>
#include <map>
#include <iterator>
#include <fstream>

using namespace std;

float distance_(pair<int, int> p1, pair<int, int> p2);
char nearestPointLetter_(map <char, pair<int, int>>& field, pair<int, int> query, char lastLetter);

float distance_(pair<int, int> p1, pair<int, int> p2) {
    return sqrt((p2.first-p1.first)*(p2.first-p1.first)+(p2.second-p1.second)*(p2.second-p1.second));
}

char nearestPointLetter_(map <char, pair<int, int>>& field, pair<int, int> query, char lastLetter) {
    float minDistance=FLT_MAX, distance, currentLetter; 
    pair<int, int> closestPoint; 
    char closestPointLetter;
    map <char, pair<int, int>> :: iterator it;
    for (it=field.begin(); it!=field.end(); it++) {
        distance=distance_(query, it->second);
        currentLetter=it->first;
        if (distance<=minDistance and lastLetter!=currentLetter) {
            minDistance=distance;
            closestPoint=it->second;
            closestPointLetter=it->first;
        }
    }
    
    return closestPointLetter;
}

int main() {
    map <char, pair<int, int>> field;
    map <char, pair<int, int>> :: iterator previous; 
    map <char, pair<int, int>> :: iterator it; 
    map <char, pair<int, int>> :: iterator nearPoint;
    int x, y, i;
    pair<int, int> nearestPoint;
    float minDistance=0.0;
    vector<char> res;
    char letter, nearestPointLetter;
    string input_;
    
    cout<<" Ввод координат точек будет через генератор случайных чисел? (yes/no) "<<endl; cin>>input_;
    
    if (input_=="no") {
        for (i=1; i<=26; i++) {
            cin>>letter; cin>>x>>y;
            field[letter]={x, y};
        }
    }
    else if (input_=="yes") {
        for (i=1; i<=26; i++) {
            cin>>letter;
            x=0+rand()%100; y=0+rand()%100;
            field[letter]={x, y};
            cout<<" "<<x<<" "<<y<<" "<<endl;
        }
    }
    
    it=field.begin();
    nearestPointLetter=it->first;
    res.push_back(it->first);
    
    for (it=field.begin(); field.size()!=1; it++) {
        char previousLetter=nearestPointLetter;
        
        previous=field.find(previousLetter);
        
        nearestPointLetter=nearestPointLetter_(field, previous->second, previousLetter);
        nearPoint=field.find(nearestPointLetter);
        nearestPoint=nearPoint->second;
        
        res.push_back(nearestPointLetter);
        
        minDistance+=distance_(previous->second, nearestPoint);
        
        field.erase(previous);
        for (it=field.begin(); it!=field.end(); it++) cout<<" ";
    }
    
    cout<<" Результат: "<<minDistance<<endl;
    ofstream out("points.txt");
    if (out.is_open()) {
        out<<"Точки :";
        for (i=0; i<=25; i++) {
            out<<" "<<res[i];
        }
    }
    out.close();
    
    return 0;
}
