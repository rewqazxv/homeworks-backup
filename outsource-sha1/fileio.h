#ifndef DIR_H
#define DIR_H

#include <vector>
#include <string>

using std::vector;
using std::string;

const string sha1sum_file = "SHA1SUMS";

string get_sha1sum_file(const string &dir);

vector<std::string> get_files(const string &dir, const string &exclude = sha1sum_file);

string read_all(const string &file);

#endif // DIR_H
