#include <TinyScreen.h>
#include "OWatchClock.h"

TinyScreen display = TinyScreen(TinyScreenPlus);
OWatchClock *clock;

void setup() {
    display.begin();
    display.setFlip(1);
    display.on();
    display.setFont(liberationSans_12ptFontInfo);
    display.setBrightness(8);

    clock = new OWatchClock(&display);
    clock->setTime(__TIME__);
    clock->setDate(__DATE__);
}

void loop() {
    uint8_t buttonPressed = 0;

    // buttonPressed = display.getButtons(TSButtonUpperLeft);
    buttonPressed = display.getButtons();
    if (buttonPressed > 0) {
        switch (buttonPressed) {
            case 1:
                clock->displayDate(true);
                break;
            case 2:
                clock->setColor(TS_8b_Blue);
                clock->displayTime(true);
                break;
            case 4:
                clock->setColor(TS_8b_Green);
                clock->displayTime(true);
                break;
            case 8:
                clock->setColor(TS_8b_Yellow);
                clock->displayTime(true);
                break;
        }
        delay(250);
    }

    // display.setCursor(1,1);
    // display.setFont(liberationSans_12ptFontInfo);
    // display.print(millis()/1000);

    // display.print(__DATE__);
    clock->displayTime(false);
}
