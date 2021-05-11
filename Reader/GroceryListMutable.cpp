#include <vector>
#include <fstream>

class GroceryList {
public:
    GroceryList(const std::string& filename);
    // other member functions
    std::string getItemAt(size_t index) const;

private:
    mutable std::vector<std::string> data;
    mutable std::ifstream sourceStream;
};

GroceryList::GroceryList(const std::string& filename) {
    sourceStream.open(filename.c_str());
}

std::string GroceryList::getItemAt(size_t index) const {
    while (index >= data.size()) {
        std::string line;
        std::getline(sourceStream, line);
        data.push_back(line);
    }
    return data[index];
}
