#include <iostream>
#include <vector>

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
        std::cout << " IP_Camera Video is showing" << std::endl;
    }

    void streamSound() override {
        std::cout << "Sound is on" << std::endl;
    }
};

class HD_Camera : public VideoInterface {
public:
    void streamVideo() override {
        std::cout << "HD_Camera Video is showing" << std::endl;
    }
};

class AdvancedCamera : public VideoInterface, public SoundInterface, public TemperatureInterface {
public:
    void streamVideo() override {
        std::cout << "AdvancedCamera Video is showing" << std::endl;
    }

    void streamSound() override {
        std::cout << "Sound is on" << std::endl;
    }

    double getTemperature() override {
        return 28.2f;
    }
};

int main(void) {

    std::vector<VideoInterface*> video;

    video.push_back(new IP_Camera());
    video.push_back(new HD_Camera());
    video.push_back(new AdvancedCamera());

    for (auto stream : video) {
        stream->streamVideo();
    }

    return 0;
}