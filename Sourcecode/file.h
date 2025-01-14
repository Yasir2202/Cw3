#pragma once
#include <string>
#include <vector>

class File {
private:
    std::string name;
    int size;
    std::vector<char> content;
public:
    File(const std::string& name);
    int getSize() const;
    std::vector<char> read() const;
    void write(const std::vector<char>& data);
    void deleteContent();
    std::string getName() const;
};
