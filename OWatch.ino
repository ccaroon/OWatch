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
}

void loop() {
    // uint8_t buttonPressed = 0;

    // buttonPressed = display.getButtons(TSButtonUpperLeft);
    // buttonPressed = display.getButtons();
    // if (buttonPressed > 0) {
    //     if (clock.getColor() == TS_8b_Green) {
    //         clock.setColor(TS_8b_White);
    //     } else {
    //         clock.setColor(TS_8b_Green);
    //     }
    // }

    // display.setCursor(1,1);
    // display.setFont(liberationSans_12ptFontInfo);

    // display.print(__DATE__);

    // uint8_t h,m,s;
    // h = bob.getHours();
    // m = bob.getMinutes();
    // s = bob.getSeconds();
    // char craig[9];
    // sprintf(craig, "%02d:%02d:%02d", h,m,s);
    // display.print(craig);

    // display.print(buttonPressed);
    clock->displayTime();
    // delay(500);
}
