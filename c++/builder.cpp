#include <iostream>
#include <string>

class Computer {
public:
    void setCPU(const std::string &cpu) {
        cpu_ = cpu;
    }

    void setRAM(const std::string &ram) {
        ram_ = ram;
    }

    void setStorage(const std::string &storage) {
        storage_ = storage;
    }

    void showInfo() {
        std::cout << "Computer configuration" << std::endl;
        std::cout << "CPU: " << cpu_ << std::endl;
        std::cout << "RAM: " << ram_ << std::endl;
        std::cout << "Storage:" << storage_ << std::endl;
    }

private:
    std::string cpu_;
    std::string ram_;
    std::string storage_;
};

class ComputerBuilder {
public:
    virtual void buildCPU() = 0;

    virtual void buildRAM() = 0;

    virtual void buildStorage() = 0;

    [[nodiscard]] virtual Computer getResult() const = 0;
};

class GamingComputerBuilder : public ComputerBuilder {
public:
    void buildCPU() override {
        computer_.setCPU("High-end Gaming CPU");
    }

    void buildRAM() override {
        computer_.setRAM("16GB Gaming RAM");
    }

    void buildStorage() override {
        computer_.setStorage("1TB SSD");
    }

    [[nodiscard]] Computer getResult() const override {
        return computer_;
    }

private:
    Computer computer_;
};


// Concrete Builder for Office Computer
class OfficeComputerBuilder : public ComputerBuilder {
public:
    void buildCPU() override {
        computer_.setCPU("Standard Office CPU");
    }

    void buildRAM() override {
        computer_.setRAM("8GB Office RAM");
    }

    void buildStorage() override {
        computer_.setStorage("500GB HDD");
    }

    [[nodiscard]] Computer getResult() const override {
        return computer_;
    }

private:
    Computer computer_;
};

// Director class
class ComputerDirector {
public:
    Computer buildComputer(ComputerBuilder &builder) {
        builder.buildCPU();
        builder.buildRAM();
        builder.buildStorage();
        return builder.getResult();
    }
};

int main() {
    ComputerDirector computerDirectorObj;

    GamingComputerBuilder gamingComputerBuilderObj;
    Computer gamingComputer = computerDirectorObj.buildComputer(gamingComputerBuilderObj);
    gamingComputer.showInfo();

    OfficeComputerBuilder officeComputerBuilderObj;
    Computer officeComputer = computerDirectorObj.buildComputer(officeComputerBuilderObj);
    officeComputer.showInfo();

    return 0;
}
