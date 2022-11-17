#include<vector>
#include<algorithm>
#include<fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    int jobs;
    fstream file;

    cout << "Enter number of print jobs: ";

    cin >> jobs;
    while (cin.fail()||jobs < 0)
    {
        string x;
        cout << "Error, enter in correct data: ";
        if (cin.fail())
        {
            cin.clear();
            cin >> x;
        }
        
        cin >> jobs;
    }

    vector<pair<int, int>> print;

    file.open("output.txt", ios::out);

    for (int i = 1; i <= jobs; i++) {

        int num_pages;

        cout << "Enter number of pages to print in print job " << i << ":";

        cin >> num_pages;
        while (cin.fail()||num_pages < 0)
        {
            string z;
            cout << "Error, enter in correct data: ";
            if (cin.fail())
            {
                cin.clear();
                cin >> z;
            }

            cin >> num_pages;
        }

        print.emplace_back(i,  num_pages);

    }

    file << "Job Number\t" << "Pages\n";

    for (int i = 0; i < jobs; i++) {

        file << "    " << print[i].first << "             " << print[i].second << '\n';

    }

    file << "\nPrint Order\n" << "Print Job Number    Original Job Number    Pages    Position Change\n";

    sort(print.begin(), print.end(), [](auto p1, auto p2) {

        return p1.second < p2.second;

        });

    int largest_for = INT_MIN, largest_back = INT_MAX, total_change = 0;

    vector<int> lar_for, lar_back;

    for (int i = 0; i < jobs; i++) {

        int change = (print[i].first) - (i + 1);

        total_change += abs(change);

        if (change > largest_for) {

            lar_for.clear();

            lar_for.push_back(print[i].first);

            largest_for = change;

        }
        else if (change == largest_for) {

            lar_for.push_back(print[i].first);

        }

        if (change < largest_back) {

            lar_back.clear();

            lar_back.push_back(print[i].first);

            largest_back = change;

        }
        else if (change == largest_back) {

            lar_back.push_back(print[i].first);

        }

        file << "    " << i + 1 << "                        " << print[i].first << "                " << print[i].second << setw(13) << change << '\n';

    }

    file << '\n';

    file << "Largest Move Forward: " << largest_for << " positions     ";

    for (int i = 0; i < lar_for.size(); i++) {

        if (i < lar_for.size() - 1)

            file << "Print Job " << lar_for[i] << ',';

        else

            file << "Print Job " << lar_for[i];

    }

    file << '\n';

    file << "Largest Move Backward: " << largest_for << " positions     ";

    for (int i = 0; i < lar_back.size(); i++) {

        if (i < lar_back.size() - 1)

            file << "Print Job " << lar_back[i] << ',';

        else

            file << "Print Job " << lar_back[i];

    }

    file << '\n';

    float avg = (float)total_change / jobs;

    file << "Average Position Change: " << avg;


    return 0;
}























