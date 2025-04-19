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
