#include <iostream>
#include <memory>

class Product {
public:
    virtual void display() const = 0;
    virtual ~Product() {
        std::cout << "Product destructor" << std::endl;
    };
};

class ConcreteProductA: public Product {
public:
    void display() const override {
        std:: cout << "display concrete product A" << std::endl;
    }
    ~ConcreteProductA() override {
        std::cout << "concrete product a destructor" << std::endl;
    }
};

class ConcreteProductB: public Product {
public:
    void display() const override {
        std::cout << "display concrete product B" << std::endl;
    }
    ~ConcreteProductB() override {
        std::cout << "concrete product a destructor" << std::endl;
    }
};

class Creator {
public:
    [[nodiscard]] virtual  std::unique_ptr<Product> createProduct() const = 0;
    virtual ~Creator() {
        std::cout << "Creator destructor" << std::endl;
    }
};

class ConcreteCreatorA: public Creator {
public:
    [[nodiscard]] std::unique_ptr<Product> createProduct() const override {
        return std::make_unique<ConcreteProductA>();
    }
    ~ConcreteCreatorA() override {
        std::cout << "concrete creator destructor A" << std::endl;
    }
};

class ConcreteCreatorB : public Creator {
public:
    [[nodiscard]] std::unique_ptr<Product> createProduct() const override {
        return std::make_unique<ConcreteProductB>();
    }
    ~ConcreteCreatorB() override {
        std::cout << "concrete creator destructor B" << std::endl;
    }
};

int main() {
    // Client code uses the Factory Method pattern
    std::unique_ptr<Creator> creatorA = std::make_unique<ConcreteCreatorA>();
    std::unique_ptr<Product> productA = creatorA->createProduct();
    productA->display();

    std::unique_ptr<Creator> creatorB = std::make_unique<ConcreteCreatorB>();
    std::unique_ptr<Product> productB = creatorB->createProduct();
    productB->display();
    return 0;
}
