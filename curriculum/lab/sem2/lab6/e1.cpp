#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

string makeIP() {
    int a = rand() % 248;   // 0-247，覆盖 A-E 类
    int b = rand() % 256;
    int c = rand() % 256;
    int d = rand() % 256;

    stringstream ss;
    ss << a << "." << b << "." << c << "." << d;
    return ss.str();
}

string makeTimestamp(int index) {
    // 固定从 2026-06-01 00:00:00 开始，每条记录相隔 60 秒，保证升序
    int year = 2026;
    int month = 6;
    int day = 1;

    int totalSeconds = index * 60;

    int hour = totalSeconds / 3600;
    int minute = totalSeconds % 3600 / 60;
    int second = totalSeconds % 60;

    day += hour / 24;
    hour %= 24;

    stringstream ss;
    ss << year << "-"
       << setw(2) << setfill('0') << month << "-"
       << setw(2) << setfill('0') << day << " "
       << setw(2) << setfill('0') << hour << ":"
       << setw(2) << setfill('0') << minute << ":"
       << setw(2) << setfill('0') << second;

    return ss.str();
}

char classifyIP(const string& ip) {
    int first = stoi(ip.substr(0, ip.find('.')));

    if (first <= 127) return 'A';
    if (first <= 191) return 'B';
    if (first <= 223) return 'C';
    if (first <= 239) return 'D';
    if (first <= 247) return 'E';

    return 'X';
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    ofstream fout("record.txt");

    if (!fout) {
        cerr << "Cannot open record.txt for writing." << endl;
        return 1;
    }

    for (int i = 0; i < 100; ++i) {
        fout << makeIP() << " " << makeTimestamp(i) << endl;
    }

    fout.close();

    ifstream fin("record.txt");

    if (!fin) {
        cerr << "Cannot open record.txt for reading." << endl;
        return 1;
    }

    int countA = 0;
    int countB = 0;
    int countC = 0;
    int countD = 0;
    int countE = 0;

    string ip;
    string date;
    string timeStr;

    while (fin >> ip >> date >> timeStr) {
        char type = classifyIP(ip);

        switch (type) {
            case 'A': countA++; break;
            case 'B': countB++; break;
            case 'C': countC++; break;
            case 'D': countD++; break;
            case 'E': countE++; break;
        }
    }

    fin.close();

    cout << "Class A: " << countA << endl;
    cout << "Class B: " << countB << endl;
    cout << "Class C: " << countC << endl;
    cout << "Class D: " << countD << endl;
    cout << "Class E: " << countE << endl;

    return 0;
}