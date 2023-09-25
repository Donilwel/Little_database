#include <iostream>
#include <map>
#include "set"
#include <algorithm>
#include <fstream>
    using namespace std;
    int main(){
        map<string, int> ages;
        int n; int y  = 0;
        string first;
        ofstream fout("out.txt");
        int second;
        cout << "Введите количество людей которые вы хотите записать: ";
        cin >> n;
        for(int i  = 0; i < n; ++i){ y++; cout << y << ". Name: "; cin >> first; cout << y << ". " << first << " Age: "; cin >> second;
                ages.emplace(first, second);
        }
        cout << "Результаты в файле out.txt. " << '\n';
        fout << "Людям кому меньше 18: " << '\n';
        int index  = 0;
        for_each(ages.begin(), ages.end(), [&fout, &index](pair<string, int> arg) {
            if(arg.second < 18)
            {
                index++;
                fout << index << ". " << arg.first << " Предположительный год рождения: " << 2023 - arg.second << endl;
            }
        });
        int index1  = 0;
        fout << '\n' << "Люди кто совершеннолетние: " << '\n';
        for_each(ages.begin(), ages.end(), [&fout, &index1](pair<string, int> arg) {
            if(arg.second >= 18)
            {
                index1++;
                fout << index1 << ". " << arg.first << " Предположительный год рождения: " << 2023 - arg.second << endl;
            }
        });
        fout.close();
}

