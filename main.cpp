#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Reading {
    int hour;
    double temperature;
};

int main()
{
    vector<Reading> temps ; // Хранилище данных
    string iname;
    int hour ;
    double temperature;
    double avg_temp = 0;
    int median_temp;
    cout << "Enter name of input file: " ;
    cin >> iname;
    ifstream ist{iname}; // ist читает данные из файла iname


    while (ist >> hour >> temperature) {
        avg_temp += temperature;
        temps.push_back(Reading{hour, temperature});
    }

    int sizeVector = temps.size();

for (int i=0; i < temps.size(); ++i)
    {
        cout << i << " " << temps[i].hour << " "<< temps[i].temperature << '\n';

    }
    cout << "Number of temperatures: " << sizeVector << endl;

    avg_temp /= sizeVector;
    cout << "Average value: " << avg_temp << endl;
     for(int i = 0; i < sizeVector; i++)
     {
         double tempValue = 0;
         for(int j = 0; j < sizeVector; j++)
         {
             if(temps[j+1].temperature < temps[j].temperature)
             {
                 tempValue = temps[j+1].temperature;
                 temps[j+1].temperature = temps[j].temperature;
                 temps[j].temperature = tempValue;
             }
         }
     }
   median_temp = sizeVector/2;
   median_temp = (temps[median_temp].temperature + temps[median_temp + 1].temperature)/2;
   cout << "Mediana of temperature: " << median_temp;
}
