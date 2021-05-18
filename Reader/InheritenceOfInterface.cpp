#include <string>
#include <queue>
using namespace std;

class Document
{
public:
    virtual int* convertToPixelArray() const = 0;
    virtual int getPriority() const = 0;
    virtual string getDocumentName() const = 0;

private:
};

class TextDocument: public Document
{
public:
    virtual int* convertToPixelArray() const;
    virtual int getPriority() const;
    virtual string getDocumentName() const;

    void setText(const string& text);
    void setFont(const string& font);
    void setSize(int size);

private:
};

class GenericBatchPrinter {
public:
    void enqueueDocument(Document* d);
    void printAllDocuments();

private:
    queue<Document*> documents;
};

void GenericBatchPrinter::enqueueDocument(Document* doc)
{
    documents.push(doc); // Recall STL queue uses push instead of enqueue }
}

void GenericBatchPrinter::printAllDocuments()
{
    while(!documents.empty())
    {
        Document* nextDocument = documents.front();
        documents.pop(); // Recall STL queue requires explicit pop operation
        // sendToPrinter(nextDocument->convertToPixelArray());
        // delete nextDocument; // Assume it was allocated with new }
    }
}

int main() {
    // runtime polymorphism
    TextDocument* myDocument = new TextDocument;
    myDocument->convertToPixelArray();

    Document* doc = new TextDocument;
    doc->convertToPixelArray();

    Document wrong;
}
