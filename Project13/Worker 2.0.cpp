#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

class Worker {
public:
    Worker() {
        cout << "������� ��� ���������: ";
        cin >> firstName;
        cout << "������� ������� ���������: ";
        cin >> lastName;
        cout << "������� ���� ��������� (� �����): ";
        cin >> experience;
        cout << "������� ������� �������� ���������: ";
        cin >> hourlyWage;
        cout << "������� ���������� ������������ �����: ";
        cin >> hoursWorked;
    }

    double calculateSalary() {
        return hourlyWage * hoursWorked;
    }

    double calculateBonus() {
        if (experience <= 1) {
            return 0;
        }
        else if (experience <= 3) {
            return calculateSalary() * 0.05;
        }
        else if (experience <= 5) {
            return calculateSalary() * 0.08;
        }
        else {
            return calculateSalary() * 0.15;
        }
    }

    void printInformation() {
        cout << "���������� � ���������:" << endl;
        cout << "���: " << firstName << endl;
        cout << "�������: " << lastName << endl;
        cout << "����: " << experience << " ����/���" << endl;
        cout << "������� ��������: " << hourlyWage << " ���." << endl;
        cout << "������������ ����: " << hoursWorked << endl;
        cout << "��������: " << calculateSalary() << " ���." << endl;
        cout << "������: " << calculateBonus() << " ���." << endl;
    }


    void saveToFile(const string& filename) {
        ofstream outfile;
        outfile.open(filename, ios::app);
        if (!outfile.is_open()) {
            cout << "������ �������� �����!" << endl;
        }
        else {
            outfile << firstName << " " << lastName << " "
                << experience << " " << hourlyWage << " " << hoursWorked << " "
                << calculateSalary() << " " << calculateBonus() << endl;
            outfile.close();
        }
    }

private:
    string firstName;
    string lastName;
    int experience;
    double hourlyWage;
    int hoursWorked;
};


void printWorkerInfoFromFile(const string& filename) {
    ifstream infile;
    infile.open(filename);
    if (!infile.is_open()) {
        cout << "������ �������� �����!" << endl;
    }
    else {
        string line;
        while (getline(infile, line)) {
            cout << line;
        }
        infile.close();
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Worker employee1;
    Worker employee2;
    Worker employee3;


    employee1.saveToFile("workers.txt");
    employee2.saveToFile("workers.txt");
    employee3.saveToFile("workers.txt");


    cout << "���������� �� ����� workers.txt:" << endl;
    printWorkerInfoFromFile("workers.txt");

    return 0;
}
