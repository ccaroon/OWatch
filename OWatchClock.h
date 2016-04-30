#include <TinyScreen.h>
#include <RTCZero.h>

#define DISPLAY_DELAY 5 * 1000 // In Milliseconds
#define TIME_Y 25

class OWatchClock {
public:
    OWatchClock(TinyScreen*);
    void setTime(char*);
    void setColor(uint8_t);
    uint8_t getColor(void);
    void setDate(char*);
    void displayTime(bool);
    void displayDate(bool);

private:
    RTCZero rtc;
    TinyScreen *screen;
    uint8_t color;
    unsigned long lastUpdate;

    uint8_t monthNameToNum(char *);
};
