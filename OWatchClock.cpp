#include "OWatchClock.h"

OWatchClock::OWatchClock(TinyScreen *ts) {
    this->screen = ts;
    this->color = TS_8b_White;

    this->lastUpdate = 0;

    this->rtc.begin();
}

// Sets the date to the date specified by dateStr
// dateStr in the format "Mmm DD YYYY" ex "Apr 30 2016"
void OWatchClock::setDate(char *dateStr) {
    int d,m,y;

    sscanf(dateStr, "%s %02d %04d", &d, &m, &y);
    // TODO: Month is a string. Map to a number
    // this->rtc.setDate(h,m,s);
}

// Sets the time to the time specified by timeStr
// timeStr in the format "HH:MM::SS"
void OWatchClock::setTime(char *timeStr) {
    int h,m,s;

    sscanf(timeStr, "%02d:%02d:%02d", &h, &m, &s);
    this->rtc.setTime(h,m,s);
}

uint8_t OWatchClock::getColor() {
    return this->color;
}
void OWatchClock::setColor(uint8_t newColor) {
    this->color = newColor;
}

void OWatchClock::displayTime() {
    char currTime[9];

    if ((millis() - this->lastUpdate) >= DISPLAY_DELAY) {
        this->lastUpdate = millis();

        uint8_t hours = this->rtc.getHours();
        uint8_t minutes = this->rtc.getMinutes();
        uint8_t seconds = rtc.getSeconds();

        sprintf(currTime, "%02d:%02d:%02d", hours, minutes, seconds);

        this->screen->setFont(liberationSans_22ptFontInfo);

        // this->screen->setCursor(TIME_X, TIME_Y);
        // this->screen->fontColor(TS_8b_Black, TS_8b_Black);
        // this->screen->print(currTime);
        this->screen->clearScreen();

        this->screen->setCursor(TIME_X, TIME_Y);
        this->screen->fontColor(this->color, TS_8b_Black);
        this->screen->print(currTime);
    }
}
