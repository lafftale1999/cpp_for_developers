#include <iostream>


// Video
// Sound
// Temperature

class VideoInterface {
public:
    virtual void streamVideo() = 0;
};

class SoundInterface {
public:
    virtual void streamSound() = 0;
};

class TemperatureInterface {
public:
    virtual double getTemperature() = 0;
};

class IP_Camera : public VideoInterface, public SoundInterface {
public:
    void streamVideo() override {
        std::cout << "Video is showing" << std::endl;
    }

    void streamSound() override {
        std::cout << "Sound is on" << std::endl;
    }
};

class HD_Camera : public VideoInterface {

};

int main(void) {

    // list VideoInterface*
    // getVideo("32F");
    // 

    return 0;
}