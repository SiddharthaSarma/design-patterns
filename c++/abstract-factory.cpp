#include <iostream>

class Button {
public:
    virtual void render() = 0;
    virtual ~Button() {
        std::cout << "Original button destructor" << std::endl;
    };
};

class Checkbox {
public:
    virtual void render() = 0;
    virtual ~Checkbox() {
        std::cout << "Original checkbox destructor" << std::endl;
    }
};

class WindowsButton: public Button {
public:
    void render() override {
        std::cout << "Render windows button" << std::endl;
    }
    ~WindowsButton() override {
        std::cout << "Windows button destroyed" << std::endl;
    }
};

class WindowsCheckbox: public Checkbox {
public:
    void render() override {
        std::cout << "Render windows checkbox" << std::endl;
    }
    ~WindowsCheckbox() override {
        std::cout << "Windows checkbox destroyed" << std::endl;
    }
};

class MacButton: public Button {
public:
    void render() override {
        std::cout << "Render Mac button" << std::endl;
    }
    ~MacButton() override {
        std::cout << "Mac button destroyed" << std::endl;
    }
};

class MacCheckbox: public Checkbox {
public:
    void render() override {
        std::cout << "Render Mac checkbox" << std::endl;
    }
    ~MacCheckbox() override {
        std::cout << "Mac checkbox destroyed" << std::endl;
    }
};

class GUIFactory {
public:
    virtual Button* createButton() = 0;
    virtual Checkbox* createCheckbox() = 0;
};

class WindowsGUIFactory: public GUIFactory {
public:
    Button* createButton() override {
        return new WindowsButton();
    }
    Checkbox* createCheckbox() override {
        return new WindowsCheckbox();
    }
};

class MacGUIFactory: public GUIFactory {
public:
    Button* createButton() override {
        return new MacButton();
    }
    Checkbox* createCheckbox() override {
        return new MacCheckbox();
    }
};

int main() {
    GUIFactory* pWindowsGuiFactory = new WindowsGUIFactory();
    Button* pWindowsBtn = pWindowsGuiFactory->createButton();
    Checkbox* pWindowsCheckbox = pWindowsGuiFactory->createCheckbox();
    pWindowsBtn->render();
    pWindowsCheckbox->render();

    delete pWindowsCheckbox;
    delete pWindowsBtn;

    GUIFactory* pMacGuiFactory = new MacGUIFactory();
    Button* pMacButton = pMacGuiFactory->createButton();
    Checkbox* pMacCheckbox = pMacGuiFactory->createCheckbox();
    pMacButton->render();
    pMacCheckbox->render();

    delete pMacCheckbox;
    delete pMacButton;

    delete pMacGuiFactory;
    delete pWindowsGuiFactory;
}
