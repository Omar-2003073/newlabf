#include <string>
#include <iostream>

// GTest header (included only when compiling for tests)
#ifdef RUN_TESTS
#include <gtest/gtest.h>
#endif

// Window interface and implementations
class Window {
public:
    virtual std::string getType() const = 0;
    virtual ~Window() = default;
};

class LinuxWindow : public Window {
public:
    std::string getType() const override {
        return "LinuxWindow";
    }
};

class WindowsWindow : public Window {
public:
    std::string getType() const override {
        return "WindowsWindow";
    }
};

// Scrollbar interface and implementations
class Scrollbar {
public:
    virtual std::string getType() const = 0;
    virtual ~Scrollbar() = default;
};

class LinuxScrollbar : public Scrollbar {
public:
    std::string getType() const override {
        return "LinuxScrollbar";
    }
};

class WindowsScrollbar : public Scrollbar {
public:
    std::string getType() const override {
        return "WindowsScrollbar";
    }
};

// Main program (compiled when RUN_TESTS is not defined)
#ifndef RUN_TESTS
void createLinuxGUI() {
    Window* window = new LinuxWindow();
    Scrollbar* scrollbar = new LinuxScrollbar();
    std::cout << "Created " << window->getType() << " with " << scrollbar->getType() << std::endl;
    delete window;
    delete scrollbar;
}

void createWindowsGUI() {
    Window* window = new WindowsWindow();
    Scrollbar* scrollbar = new WindowsScrollbar();
    std::cout << "Created " << window->getType() << " with " << scrollbar->getType() << std::endl;
    delete window;
    delete scrollbar;
}

int main() {
    std::cout << "Creating Linux GUI:\n";
    createLinuxGUI();

    std::cout << "Creating Windows GUI:\n";
    createWindowsGUI();

    return 0;
}
#endif

// GTest cases (compiled when RUN_TESTS is defined)
#ifdef RUN_TESTS
TEST(GUITest, LinuxWindowAndScrollbar) {
    Window* window = new LinuxWindow();
    Scrollbar* scrollbar = new LinuxScrollbar();

    EXPECT_EQ(window->getType(), "LinuxWindow");
    EXPECT_EQ(scrollbar->getType(), "LinuxScrollbar");

    delete window;
    delete scrollbar;
}

TEST(GUITest, WindowsWindowAndScrollbar) {
    Window* window = new WindowsWindow();
    Scrollbar* scrollbar = new WindowsScrollbar();

    EXPECT_EQ(window->getType(), "WindowsWindow");
    EXPECT_EQ(scrollbar->getType(), "WindowsScrollbar");

    delete window;
    delete scrollbar;
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif