#include <iostream>
#include <vector>

class Widget {
public:
    virtual ~Widget() {}
    virtual void draw() = 0;
    virtual void handleEvent(int eventId) = 0;
};

class Button : public Widget {
public:
    void draw() override {
        // draw button rectangle, text, etc.
    }
    void handleEvent(int eventId) override {
        // check for clicks
    }
};

class TextBox : public Widget {
public:
    void draw() override {
        // draw text box and caret
    }
    void handleEvent(int eventId) override {
        // handle key input
    }
};

int main(void) {
    std::vector<Widget*> widgets = { new Button(), new TextBox() };

    for (auto* w : widgets) {
        w->draw();
    }

    return 0;
}

