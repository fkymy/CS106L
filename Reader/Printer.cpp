#include <queue>
#include <string>
using namespace std;

class Printer
{
public:
    void setFont(const string& fontName, int size);
    void setColor(const string& color);
    void printDocument(const string& document);
};

class BatchPrinter: public Printer
{
public:
    void enqueueDocument(const string& document);
    void printAllDocuments();
private:
    queue<string> documents;
};

class GraphicsPrinter: public Printer
{
public:
    void printPicture(const Picture& picture);
private:

};

void InitializePrinter(Printer& p);

int main() {
    BatchPrinter myPrinter;

    InitializePrinter(myPrinter);
}
