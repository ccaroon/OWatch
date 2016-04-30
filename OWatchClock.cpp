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
    char month[4];
    int m,d,y;

    sscanf(dateStr, "%s %02d %04d", &month, &d, &y);

    if (y >= 2000) {
        y -= 2000;
    } else {
        y -= 1900;
    }
    // TODO: Month is a string. Map to a number
    m = this->monthNameToNum(month);
    this->rtc.setDate(d,m,y);
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

void OWatchClock::displayTime(bool forceUpdate) {
    char currTime[6];

    if (forceUpdate || (millis() - this->lastUpdate) >= DISPLAY_DELAY) {
        this->lastUpdate = millis();

        uint8_t hours = this->rtc.getHours();
        if (hours > 12) {
            hours -= 12;
        }
        uint8_t minutes = this->rtc.getMinutes();
        // uint8_t seconds = rtc.getSeconds();

        sprintf(currTime, "%d:%02d", hours, minutes);

        this->screen->setFont(liberationSans_22ptFontInfo);

        // this->screen->setCursor(TIME_X, TIME_Y);
        // this->screen->fontColor(TS_8b_Black, TS_8b_Black);
        // this->screen->print(currTime);
        this->screen->clearScreen();

        uint8_t width = this->screen->getPrintWidth(currTime);
        uint8_t xPos = (TinyScreen::xMax / 2) - (width/2);
        this->screen->setCursor(xPos, TIME_Y);
        this->screen->fontColor(this->color, TS_8b_Black);
        this->screen->print(currTime);
    }
}

void OWatchClock::displayDate(bool forceUpdate) {
    char currDate[9];

    if (forceUpdate || (millis() - this->lastUpdate) >= DISPLAY_DELAY) {
        this->lastUpdate = millis();

        uint8_t day = this->rtc.getDay();
        uint8_t month = this->rtc.getMonth();
        uint8_t year = rtc.getYear();

        sprintf(currDate, "%d/%02d/%02d", month, day, year);

        this->screen->setFont(liberationSans_16ptFontInfo);

        this->screen->clearScreen();

        uint8_t width = this->screen->getPrintWidth(currDate);
        uint8_t xPos = (TinyScreen::xMax / 2) - (width/2);
        this->screen->setCursor(xPos, TIME_Y);
        this->screen->fontColor(this->color, TS_8b_Black);
        this->screen->print(currDate);
    }
}

uint8_t OWatchClock::monthNameToNum(char *name) {
    uint8_t monthNum = 0;

    if (strcmp(name, "Jan") == 0) {
        monthNum = 1;
    } else if (strcmp(name, "Feb") == 0) {
        monthNum = 2;
    } else if (strcmp(name, "Mar") == 0) {
        monthNum = 3;
    } else if (strcmp(name, "Apr") == 0) {
        monthNum = 4;
    } else if (strcmp(name, "May") == 0) {
        monthNum = 5;
    } else if (strcmp(name, "Jun") == 0) {
        monthNum = 6;
    } else if (strcmp(name, "Jul") == 0) {
        monthNum = 7;
    } else if (strcmp(name, "Aug") == 0) {
        monthNum = 8;
    } else if (strcmp(name, "Sep") == 0) {
        monthNum = 9;
    } else if (strcmp(name, "Oct") == 0) {
        monthNum = 10;
    } else if (strcmp(name, "Nov") == 0) {
        monthNum = 11;
    } else if (strcmp(name, "Dec") == 0) {
        monthNum = 12;
    }

    return monthNum;
}
