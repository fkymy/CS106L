#include <vector>
#include <fstream>

class GroceryList {
public:
    GroceryList(const std::string& filename);
    // other member functions
    std::string getItemAt(size_t index) const;

private:
    std::vector<std::string> data;
};

GroceryList::GroceryList(const std::string& filename) {
    std::ifstream input(filename.c_str());

    data.insert(data.begin(), std::istream_iterator<std::string>(input),
                std::istream_iterator<std::string>());
}

std::string GroceryList::getItemAt(size_t index) const {
    return data[index];
}
