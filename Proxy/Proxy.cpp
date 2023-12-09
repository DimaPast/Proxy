
#include <iostream>
#include <string>
#include <Windows.h>

class RealSubject {
public:
    void request() const {
        std::cout << "RealSubject: ������ ��������� ��'����." << std::endl;
    }
};

class Proxy {
private:
    mutable RealSubject* realSubject;
    std::string address;

public:
    Proxy(const std::string& addr) : address(addr), realSubject(nullptr) {}

    void request() const {
        if (realSubject == nullptr) {
            realSubject = new RealSubject();
        }

        std::cout << "Proxy: ������ ���������� ��'���� �� ����� " << address << "." << std::endl;
        realSubject->request();
    }

    ~Proxy() {
        delete realSubject;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Proxy* proxy = new Proxy("http://remote-service.com");
    proxy->request();

    delete proxy;

    return 0;
}
