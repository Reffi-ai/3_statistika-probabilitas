#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;

double mean(const vector<int>& data) {
    double sum = 0;
    for (int val : data) sum += val;
    return sum / data.size();
}

double median(vector<int>& data) {
    sort(data.begin(), data.end());
    int n = data.size();
    if (n % 2 == 0)
        return (data[n/2 - 1] + data[n/2]) / 2.0;
    else
        return data[n/2];
}

int modus(const vector<int>& data) {
    map<int, int> freq;
    for (int val : data) freq[val]++;
    int mode = data[0], maxFreq = 0;
    for (auto& p : freq) {
        if (p.second > maxFreq) {
            maxFreq = p.second;
            mode = p.first;
        }
    }
    return mode;
}

double kuartil(vector<int>& data, double q) {
    sort(data.begin(), data.end());
    double pos = q * (data.size() + 1);
    int idx = (int)pos;
    double frac = pos - idx;

    if (idx <= 0) return data.front();
    if (idx >= data.size()) return data.back();

    return data[idx - 1] + frac * (data[idx] - data[idx - 1]);
}

int main() {
    int n;
    cout << "Masukkan jumlah data: ";
    if (!(cin >> n)) {
        cout << "Input tidak valid! Program dihentikan." << endl;
        system("pause");
        return 0;
    }

    if (n <= 2) {
        cout << "Jumlah data harus lebih dari 2!" << endl;
        system("pause");
        return 0;
    }

    cin.ignore(); // membersihkan sisa newline dari cin sebelumnya
    cout << "Masukkan " << n << " data (pisahkan dengan spasi): ";
    string line;
    getline(cin, line);

    stringstream ss(line);
    vector<int> data;
    int value;
    while (ss >> value) {
        data.push_back(value);
    }

    // Cek apakah jumlah data sesuai n
    if ((int)data.size() != n) {
        cout << "Input tidak valid! Jumlah data tidak sesuai." << endl;
        system("pause");
        return 0;
    }

    cout << "\nHasil Perhitungan:\n";
    cout << "Mean   : " << mean(data) << endl;
    cout << "Median : " << median(data) << endl;
    cout << "Modus  : " << modus(data) << endl;
    cout << "Kuartil 1 (Q1): " << kuartil(data, 0.25) << endl;
    cout << "Kuartil 2 (Q2/Median): " << kuartil(data, 0.50) << endl;
    cout << "Kuartil 3 (Q3): " << kuartil(data, 0.75) << endl;

    system("pause"); // menunggu sebelum keluar
    return 0;
}