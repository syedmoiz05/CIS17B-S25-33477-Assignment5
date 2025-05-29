#include <iostream>
#include <string>
#include <array>
#include <typeinfo>

using namespace std;

// generic int package
template<typename T>
class Package {
private:
    T item;
public:
    Package(T i) : item(i) {}
    void label() {
        cout << "Generic package containing: " << typeid(T).name() << "\n";
    }
};

template<>
class Package<string> {
private:
    string item;
public:
    Package(string i) : item(i) {}
    void label() {
        cout << "Book package: \"" << item << "\"\n";
    }
};

template<typename T>
class Package<T*> {
private:
    T* item;
public:
    Package(T* i) : item(i) {}
    void label() {
        cout << "Fragile package for pointer to type: " << typeid(T).name() << "\n";
    }
};

template<typename T, int Size>
class Box {
private:
    array<T, Size> items;
    int count = 0;
public:
    bool addItem(const T& item) {
        if (count < Size) {
            items[count++] = item;
            cout << "Added item to box: \"" << item << "\"\n";
            return true;
        }
        return false;
    }
    void printItems() const {
        cout << "Box contents:\n";
        for (int i = 0; i < count; ++i) {
            cout << " - " << items[i] << "\n";
        }
    }
};

template<typename T>
void shipItem(const T& item) {
    cout << "Shipping item of type: " << typeid(T).name() << "\n";
}

template<>
void shipItem(const double& item) {
    cout << "Shipping temperature-controlled item: " << item << "°C\n";
}

int main() {
    // generic int package
    Package<int> intPkg(100);
    intPkg.label();

    // book package via variable
    string title = "Learn C++ in 2 seconds!";
    Package<string> bookPkg(title);
    bookPkg.label();

    // fragile packag
    double* pTemp = new double(36.6);
    Package<double*> fragDyn(pTemp);
    fragDyn.label();

    // fill box with a loop
    Box<string, 3> box2;
    array<string, 3> shelf = {
        "DSA in 1 second",
        "Refactoring code",
        "Trees"
    };
    for (const auto& s : shelf) {
        if (!box2.addItem(s)) {
            cout << "Box is full, can't add \"" << s << "\"\n";
        }
    }
    box2.printItems();

    // clean up
    shipItem(100);
    shipItem(title);
    shipItem(*pTemp);

    delete pTemp;
    return 0;
}
