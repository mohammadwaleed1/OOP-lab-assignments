#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    ofstream outFile("data.txt");

    outFile << "1 Alice manager 3\n";
    outFile << "2 Bob developer 1\n";
    outFile << "3 Charlie manager 2\n";
    outFile << "4 David intern 1\n";
    outFile << "5 Eve manager 1\n";
    outFile.close();

    ifstream inFile("data.txt");

    string line;
    vector<string> filteredData;

    while (getline(inFile, line))
    {
        stringstream ss(line);
        int id, years;
        string name, designation;
        ss >> id >> name >> designation >> years;

        if (designation == "manager" && years >= 2)
        {
            filteredData.push_back(line);
        }
    }
    inFile.close();

    cout << "\n[a] Managers with >= 2 years of service:\n";
    for (const string &entry : filteredData)
    {
        cout << entry << endl;
    }

    outFile.open("data.txt");
    for (const string &entry : filteredData)
    {
        outFile << entry << endl;
    }
    outFile.close();

    inFile.open("data.txt");
    vector<string> updatedData;
    while (getline(inFile, line))
    {
        stringstream ss(line);
        int id, years;
        string name, designation;
        ss >> id >> name >> designation >> years;
        id += 10;
        years += 1;
        stringstream newLine;
        newLine << id << " " << name << " " << designation << " " << years;
        updatedData.push_back(newLine.str());
    }
    inFile.close();

    outFile.open("data.txt");
    for (const string &entry : updatedData)
    {
        outFile << entry << endl;
    }
    outFile.close();

    cout << "\n[c] Updated Data (IDs +10, Years +1):\n";
    for (const string &entry : updatedData)
    {
        cout << entry << endl;
    }

    return 0;
}
