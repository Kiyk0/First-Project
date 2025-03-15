#include <iostream>
#include <string>

using namespace std;

bool checker();
double series();
double parallel();

string circuit_description;
string draft;

int main() {
    double voltage,total_resistance;
    cout << "Please enter your circuit description" << endl;
    getline(cin,circuit_description);
    cout << "Voltage applied?" << endl;
    cin >> voltage;
    if (checker()) return 0;
    int count = 0;
    for (size_t i = 0; i < circuit_description.size(); i++) if (circuit_description[i] == 'e') count++;
    for (size_t i = 0; i <= count; i++)
    {
        int e = 0, S_P = 0;
        for (size_t i = 0; i < circuit_description.size(); i++) if (circuit_description[i] == 'e')
        {
            e = i;
            break;
        }
        S_P = e;
        while (1)
        {
            S_P--;
            if (circuit_description[S_P] == 'P' || circuit_description[S_P] == 'S' || e == 0) break;;
        }
        if (e == 0) draft = circuit_description;
        else draft = circuit_description.substr(S_P, e-S_P+1);
        if (circuit_description[S_P] == 'S') 
        {
            total_resistance = series();
            circuit_description = circuit_description.substr(0, S_P) + to_string(total_resistance) + circuit_description.substr(e+1,circuit_description.size());
        }
        else if (circuit_description[S_P] == 'P')
        {
            total_resistance = parallel();
            circuit_description = circuit_description.substr(0, S_P) + to_string(total_resistance) + circuit_description.substr(e+1,circuit_description.size());
        }
        if (circuit_description.substr(0,1) == "S" && i == count)
        {
            circuit_description = draft;
            total_resistance = series();
        }
        else if (circuit_description.substr(0,1) == "P" && i == count)
        {
            circuit_description = draft;
            total_resistance = parallel();
        }
    }
    cout << "Total Resistance = " << total_resistance << " Ohm" << endl;
    cout << "Current = " << voltage/total_resistance << " A" << endl;
}


double series() {
    int x = 0,y = 0;
    double resistance, sum = 0;
    while (1)
    {
        x = draft.find(" ",y)+1;
        resistance = stof(draft.substr(x,draft.length()));
        y = draft.find(" ",x)-1;
        sum = resistance + sum;
        if (y == draft.find("e")-2 || y == draft.find("E")-2) break;
    }
    return sum;
}


double parallel() {
    int x = 0,y = 0;
    double resistance, sum = 0;
    while (1)
    {
        x = draft.find(" ",y)+1;
        resistance = stof(draft.substr(x,draft.length()));
        y = draft.find(" ",x)-1;
        if (sum == 0) sum = resistance;
        else sum = (resistance * sum) / (resistance + sum);
        if (y == draft.find("e")-2 || y == draft.find("E")-2) break;
    }
    return sum;
}


bool checker() {
    for (int i=0;i < circuit_description.length()-1;i++) 
    {
		if (circuit_description[i] == 'S' || circuit_description[i] == 'P' ||
			circuit_description[i] == 'E' || circuit_description[i] == 'e' ||
			circuit_description[i] == '.' || circuit_description[i] == ' ' ||
			circuit_description[i] == '0' || circuit_description[i] == '1' ||
			circuit_description[i] == '2' || circuit_description[i] == '3' ||
			circuit_description[i] == '4' || circuit_description[i] == '5' ||
			circuit_description[i] == '6' || circuit_description[i] == '7' ||
			circuit_description[i] == '8' || circuit_description[i] == '9') continue;
		else cerr << "\aWrong Circuit Description" << endl;
        return 1;
	}
    return 0;
}