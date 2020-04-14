#include <set>
#include <algorithm>

using namespace std;

// Functie pentru a converti un map <cheie, valoare> intr-o multimap <valoare, cheie>
multimap<int, string> invert(map<string, int>& mymap)
{
	multimap<int, string> multiMap;

	map<string, int> ::iterator it;
	for (it = mymap.begin(); it != mymap.end(); it++)
	{
		multiMap.insert(make_pair(it->second, it->first));
	}

	return multiMap;
}

int main()
{
	// creez map
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

	// inversati mymap folosind functia invertita creata mai sus
	multimap<int, string> newmap = invert(mymap);

	// print the multimap
	cout << "The map, sorted by value is: " << endl;
	multimap<int, string> ::iterator iter;
	for (iter = newmap.begin(); iter != newmap.end(); iter++)
	{

		// imprimarea mai intai a doua valoare deoarece
		// ordinea (cheie, valoare) este inversata in multimap
		cout << iter->second << ": " << iter->first << endl;
	}

	return 0;
}