
void DoSomething() {

}

void SimpleFunction() {
    int *myArray = new int[128];

    try {
        DoSomething();
    }
    catch (...) {
        delete [] myArray;
        throw;
    }

    delete [] myArray;

}
