#include <iostream>
#include <map>
#include <vector>
#include <algorithm> //  pt sortarea functiei

using namespace std;


// functia de comparare a utilitatii pentru a trece la modulul sort ()
bool sortByVal(const pair<string, int>& a,
    const pair<string, int>& b)
{
    return (a.second < b.second);
}

int main()
{
    // creeaza un map
    map<string, int> mymap = {
        {"coconut", 10}, {"apple", 5}, {"peach", 30}, {"mango", 8}
    };

    cout << "The map, sorted by keys, is: " << endl;
    map<string, int> ::iterator it;
    for (it = mymap.begin(); it != mymap.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }
    cout << endl;

    // creeaza o pereche de vectori liberi
    vector<pair<string, int>> vec;

    // copiati perechi cheie-valoare de pe map la vector
    map<string, int> ::iterator it2;
    for (it2 = mymap.begin(); it2 != mymap.end(); it2++)
    {
        vec.push_back(make_pair(it2->first, it2->second));
    }


    // sorteaza vectorul marind ordinea celei de-a doua valori a perechii sale
    sort(vec.begin(), vec.end(), sortByVal);

    // print vector
    cout << "The map, sorted by value is: " << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i].first << ": " << vec[i].second << endl;
    }
    return 0;
}