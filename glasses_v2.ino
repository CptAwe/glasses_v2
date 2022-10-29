#include "Glasses/Glasses.h"

#define BRIGHTNESS 1

Glasses glasses;

void setup() {
    // Serial.begin(9600);
    glasses.clear();
}

void drawraindrop(byte row, byte column, byte which_eye, CHSV colour, byte * bright) {
    /*
     * Light 3 LEDs on the same column, of the same colour, but each of different brightness:
     * which_eye :  1 - right
     *              2 - left
     *  anything else - both
    */
    // right eye
    if (which_eye == 1) {

        glasses.rightEye(
            row,
            column,
            colour.setHSV(colour.hue, colour.sat, bright[2])
        );
        // Light the tail
        row -= 1;
        glasses.rightEye(
            row,
            column,
            colour.setHSV(colour.hue, colour.sat, bright[1])
        );
        row -= 1;
        glasses.rightEye(
            row,
            column,
            colour.setHSV(colour.hue, colour.sat, bright[0])
        );
    }


    // Left eye
    if (which_eye == 2) {

        glasses.leftEye(
            row,
            column,
            colour.setHSV(colour.hue, colour.sat, bright[2])
        );
        // Light the tail
        row -= 1;
        glasses.leftEye(
            row,
            column,
            colour.setHSV(colour.hue, colour.sat, bright[1])
        );
        row -= 1;
        glasses.leftEye(
            row,
            column,
            colour.setHSV(colour.hue, colour.sat, bright[0])
        );
    }

}

void makeItRain(byte which_eye, CHSV colour){
    /*
     * Light 3 LEDs on the same column, of the same colour, but of different brightness:
     * which_eye :  1 - right
     *              2 - left
     *  anything else - both
    */
    int frameDelay = 150;
    byte bright[] = {1, 20, 50};

    byte num_of_drops = 6;
 
    byte raindropsRight[num_of_drops][2] = {// remember only the lowest point
        {}, {}, {}, {}, {}, {}
    };
    byte raindropsLeft[num_of_drops][2] = {// remember only the lowest point
        {}, {}, {}, {}, {}, {}
    };

    // generate pairs of coordinates for the right eye
    for (byte pair=0; pair<num_of_drops; pair++) {
        byte random_row;
        byte random_column;
        while (true) {
            byte * point = glasses.generatePoint();
            random_row = point[0];
            random_column = point[1];
            if (random_row >= 0) {break;}
        }
        raindropsRight[pair][0] = random_row;
        raindropsRight[pair][1] = random_column;
    }

    // generate pairs of coordinates for the left eye
    for (byte pair=0; pair<num_of_drops; pair++) {
        byte random_row;
        byte random_column;
        while (true) {
            byte * point = glasses.generatePoint();
            random_row = point[0];
            random_column = point[1];
            if (random_row >= 0) {break;}
        }
        raindropsLeft[pair][0] = random_row;
        raindropsLeft[pair][1] = random_column;
    }

    while(true) {

        delay(frameDelay);
        // glasses.clear();

        if (which_eye != 2) {// right eye
            // draw each drop
            glasses.clearRightEye();
            for (byte pair=0; pair<num_of_drops; pair++) {
                drawraindrop(raindropsRight[pair][0], raindropsRight[pair][1], 1, colour, bright);
                glasses.show();
            }
            // lower them
            for (byte pair=0; pair<num_of_drops; pair++) {
                raindropsRight[pair][0]++;
            }
            // if any of them is lowered too much then generate new coordinates
            for (byte pair=0; pair<num_of_drops; pair++) {
                if (raindropsRight[pair][0] >= 7) {
                    // the lowest point has dropped below the eye. Recreate the raindrop
                    byte random_column;
                    byte random_row;
                    while (true) {
                        byte * point = glasses.generatePoint();
                        random_row = point[0];
                        random_column = point[1];
                        if (random_row >= 0) {break;}
                    }
                    raindropsRight[pair][0] = random_row;
                    raindropsRight[pair][1] = random_column;
                }
            }
        }

        if (which_eye != 1) {// left eye
            // draw each drop
            glasses.clearLeftEye();
            for (byte pair=0; pair<num_of_drops; pair++) {
                drawraindrop(raindropsLeft[pair][0], raindropsLeft[pair][1], 2, colour, bright);
                glasses.show();
            }
            // lower them
            for (byte pair=0; pair<num_of_drops; pair++) {
                raindropsLeft[pair][0]++;
            }
            // if any of them is lowered too much then generate new coordinates
            for (byte pair=0; pair<num_of_drops; pair++) {
                if (raindropsLeft[pair][0] >= 7) {
                    // the lowest point has dropped below the eye. Recreate the raindrop
                    byte random_column;
                    byte random_row;
                    while (true) {
                        byte * point = glasses.generatePoint();
                        random_row = point[0];
                        random_column = point[1];
                        if (random_row >= 0) {break;}
                    }
                    raindropsLeft[pair][0] = random_row;
                    raindropsLeft[pair][1] = random_column;
                }
            }
        }
    }
    
}

void loop() {

    CHSV green = CHSV(100, 255, 100);
    makeItRain(0, green);

}
