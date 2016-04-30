#include <TinyScreen.h>
#include <RTCZero.h>

#define DISPLAY_DELAY 5 * 1000 // In Milliseconds
#define TIME_X 0
#define TIME_Y 25

class OWatchClock {
public:
    OWatchClock(TinyScreen*);
    void setTime(char*);
    void setColor(uint8_t);
    uint8_t getColor(void);
    void setDate(char*);
    void displayTime();
private:
    RTCZero rtc;
    TinyScreen *screen;
    uint8_t color;
    unsigned long lastUpdate;
};
