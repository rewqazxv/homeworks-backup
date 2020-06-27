#include "fileio.h"

#include <fstream>
#include <filesystem>
using namespace std;
using namespace std::filesystem;

vector<std::string> get_files(const string &dir, const string &exclude) {
    vector<std::string> res;
    for (const auto &i : recursive_directory_iterator(dir))
        if (!i.is_directory() && path(i.path().string()).filename() != exclude)
            res.push_back(i.path().string());
    return res;
}

string get_sha1sum_file(const string &dir) {
    return (path(dir) / path(sha1sum_file)).string();
}

string read_all(const std::string &path) {
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<char> buffer(size);
    if (file.read(buffer.data(), size)) {
        return string(buffer.begin(), buffer.end());
    }
    throw 0;
}
