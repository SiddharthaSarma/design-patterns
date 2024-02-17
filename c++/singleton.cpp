#include <iostream>

class Singleton {
private:
    static Singleton* instance;
    Singleton() = default;
    int connections = 0;
public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void SomeMethod() {
        std::cout << "working here " << std::endl;
        std::cout << connections << std::endl;
    }
};

Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* singletonObj = Singleton::getInstance();
    singletonObj->SomeMethod();
    return 0;
}
