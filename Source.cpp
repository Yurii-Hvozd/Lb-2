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
        cout << "�������� ���i - ������i�� 1" << endl;
        cout << "�������� ���i - ������i�� 2" << endl;
        cout << "���i� - ������i�� 3" << endl;
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
                cout << "�� ����� �i������ ����" << endl;
                return -1;
            }
            cout << setw(9) << "�����" << setw(13) << "�i���i���" << setw(6) << "�i��" << setw(8) << "����" << endl;
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
            cout << "�����: ";
            cin >> name;
            cout << "�i���i���: ";
            cin >> number;
            cout << "�i��: ";
            cin >> cost;
            tcost = number * cost;
            fstream outfile("File.txt", ios::app);
            if (!outfile)
            {
                cout << "�� ����� �i������ ����" << endl;
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
