#include <Arduino.h>
#include <Glasses.h>

#define BRIGHTNESS 1

Glasses glasses;

void setup() {
    glasses.clear();
}

void loop() {
    for (byte column=0; column<=7; column++) {
        for (byte row=0; row<=5; row++) {
            byte statusRight = glasses.rightEye(row, column, CHSV(0, 0, BRIGHTNESS));
            byte statusLeft = glasses.leftEye(row, column, CHSV(0, 0, BRIGHTNESS));
            if (statusRight and statusLeft) {
                glasses.show();
                delay(500);
                glasses.clear();
            }
        }
    }


    // for (byte row=0; row<=5; row++) {
    //     for (byte column=0; column<=7; column++) {
    //         byte statusRight = glasses.rightEye(row, column, CHSV(0, 0, BRIGHTNESS));
    //         byte statusLeft = glasses.leftEye(row, column, CHSV(0, 0, BRIGHTNESS));
    //         if (statusRight and statusLeft) {
    //             glasses.show();
    //             delay(500);
    //             glasses.clear();
    //         }
    //     }
    // }
}

