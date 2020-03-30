#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
    while (true)
    {
        setlocale(LC_ALL, "ukr");
        cout << "Показати данi - натиснiть 1" << endl;
        cout << "Записати данi - натиснiть 2" << endl;
        cout << "Вихiд - натиснiть 3" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            string name;
            int number;
            int prise;
            int tCost;
            ifstream infile;
            infile.open("File.txt");
            if (!infile)
            {
                cout << "Не можна вiдкрити файл" << endl;
                return -1;
            }
            cout << setw(9) << "Назва" << setw(13) << "Кiлькiсть" << setw(6) << "Цiна" << setw(8) << "Сума" << endl;
            while (!infile.eof())
            {
                infile >> name;
                infile >> number;
                infile >> prise;
                infile >> tCost;
                if (!infile.eof())
                {
                    cout.width(9);
                    cout << name;
                    cout.width(9);
                    cout << number;
                    cout.width(9);
                    cout << prise;
                    cout.width(9);
                    cout << tCost;
                    cout << endl;
                }
            }
            infile.close();
        }
        if (choice == 2)
        {

            string name;
            int number;
            int cost;
            int tcost;
            cout << "Назва: ";
            cin >> name;
            cout << "Кiлькiсть: ";
            cin >> number;
            cout << "Цiна: ";
            cin >> cost;
            tcost = number * cost;
            fstream outfile("File.txt", ios::app);
            if (!outfile)
            {
                cout << "Не можна вiдкрити файл" << endl;
                return -1;
            }
            outfile.setf(ios::left);
            outfile.width(9);
            outfile << name << ' ';
            outfile.width(9);
            outfile << number << ' ';
            outfile.width(9);
            outfile << cost << ' ';
            outfile.width(9);
            outfile << tcost << endl;
            outfile.close();
        }

        if (choice == 3)
        {
            break;
        }
    }
    system("pause");
}
