#include <iostream>
#include <string>
using namespace std;

class MediaFile {
protected:
    string filePath;
    float fileSize;
public:
MediaFile(){
    filePath="";
    fileSize=0;
};
    MediaFile(string path, float size){ 
    filePath=path; 
    fileSize=size; 
}
    
    virtual void play() const {
        cout << "Playing: " << filePath << endl;
    }
    
    virtual void stop() const {
        cout << "Stopping: " << filePath << endl;
    }
    
    virtual void displayInfo() const {
        cout << "File: " << filePath << " | Size: " << fileSize << "MB" << endl;
    }
};
class VisualMedia : virtual public MediaFile {
protected:
    int resolutionX, resolutionY;
public:
    VisualMedia(string path, float size, int resX, int resY)
        : MediaFile(path, size), resolutionX(resX), resolutionY(resY) {}
    
    void displayResolution() const {
        cout << "Resolution: " << resolutionX << "x" << resolutionY << endl;
    }
};

class AudioMedia : virtual public MediaFile {
protected:
    int sampleRate;
public:
    AudioMedia(string path, float size, int rate)
        : MediaFile(path, size), sampleRate(rate) {}
    
    void displaySampleRate() const {
        cout << "Sample Rate: " << sampleRate << "Hz" << endl;
    }
};

class ImageFile : public VisualMedia {
public:
    ImageFile(string path, float size, int resX, int resY)
        :VisualMedia(path, size, resX, resY) {}
    
    void displayInfo1(){
        MediaFile::displayInfo();
        displayResolution();
    }
};

class AudioFile : public AudioMedia {
public:
    AudioFile(string path, float size, int rate)
        : AudioMedia(path, size, rate) {}
    
    void displayInfo2(){
        MediaFile::displayInfo();
        displaySampleRate();
    }
};

class VideoFile : public VisualMedia, public AudioMedia {
public:
    VideoFile(string path, float size, int resX, int resY, int rate)
        :VisualMedia(path, size, resX, resY), AudioMedia(path, size, rate) {}
    
    void displayInfo3(){
        MediaFile::displayInfo();
        displayResolution();
        displaySampleRate();
    }
};

int main() {
    ImageFile img("photo.jpg", 2.5, 1920, 1080);
    AudioFile aud("song.mp3", 5.0, 44100);
    VideoFile vid("movie.mp4", 700, 1920, 1080, 48000);
    
    cout << "\nDisplaying Image File Details:" << endl;
    img.displayInfo1();
    
    cout << "\nDisplaying Audio File Details:" << endl;
    aud.displayInfo2();
    
    cout << "\nDisplaying Video File Details:" << endl;
    vid.displayInfo3();
    
    cout << "\nPlaying Media Files:" << endl;
    img.play();
    aud.play();
    vid.play();
    img.stop();
    vid.stop();
    aud.stop();
    
    return 0;
}