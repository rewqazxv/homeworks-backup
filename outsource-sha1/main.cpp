#define _HAS_STD_BYTE 0

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <map>
using namespace std;

#include "sha1.h"
#include "fileio.h"

#if defined(__unix__)
#include <unistd.h>
void sleep_ms(int ms) {
    usleep(ms * 1000);
}
#elif defined(_WIN32)
#include <windows.h>
static inline void sleep_ms(int ms) {
    Sleep(ms);
}
#endif

void clear_screen() {
#if defined(__unix__)
    system("clear");
#elif defined(_WIN32)
    system("cls");
#endif
}

void calc() {
    cout << "input dir path: ";
    string dirpath;
    getline(cin, dirpath);

    auto files = get_files(dirpath);
    ofstream fout{get_sha1sum_file(dirpath)};

    for (const auto &i : files) {
        string content = read_all(i);
        string entry = sha1(content) + "  " + i;
        cout << entry << endl;
        fout << entry << endl;
    }

    fout.close();
}

void check() {
    cout << "input dir path: ";
    string dirpath;
    getline(cin, dirpath);
    ifstream fin{get_sha1sum_file(dirpath)};
    if (!fin) {
        cout << "no " << sha1sum_file << " file found." << endl;
        return;
    }

    map<string, string> file_hash_table;
    string line;
    while (getline(fin, line)) {
        auto pos = line.find_first_of(' ');
        string file = line.substr(pos + 2);
        string hash = line.substr(0, pos);
        file_hash_table[file] = hash;
    }
    fin.close();

    auto files = get_files(dirpath);
    int cnt = 0;
    for (const auto &i : files) {
        string content = read_all(i);
        if (sha1(content) != file_hash_table[i]) {
            cout << "failed: " << i << endl;
            cnt++;
        }
    }
    cout << "check end, " << cnt << " files error." << endl;
}

void monitor() {
    cout << "input dir path: ";
    string dirpath;
    getline(cin, dirpath);

    auto files = get_files(dirpath);
    map<string, string> file_hash_table;
    for (const auto &i : files) {
        string content = read_all(i);
        string hash = sha1(content);
        file_hash_table[i] = hash;
    }
    cout << "initialized." << endl;

    for (;;) {
        sleep_ms(1 * 60 * 1000);
        auto files = get_files(dirpath);
        for (const auto &i : files) {
            string content = read_all(i);
            string hash = sha1(content);
            if (hash != file_hash_table[i]) {
                cout << "file changed: " << i << endl;
                file_hash_table[i] = hash;
            }
        }
    }
}

void ui() {
    string tip =
        "sha1 checksum\n"
        "---------------\n"
        "  1. calculate dir sha1\n"
        "  2. check dir sha1\n"
        "  3. Monitor dir change\n"
        "  4. exit\n";
    cout << tip << endl;
    cout << "> ";
    string line;
    getline(cin, line);
    int sel = stoi(line);
    switch(sel) {
    case 1:
        calc();
        break;
    case 2:
        check();
        break;
    case 3:
        monitor();
        break;
    case 4:
        exit(0);
        break;
    }
}

int main() {
    while (true) {
        clear_screen();
        ui();
        cout << "Press any key to continue...";
        getchar();
    }
}
