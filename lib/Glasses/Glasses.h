#ifndef Glasses_h
#define Glasses_h

#include "Arduino.h"
#include "FastLED.h"

#if defined(ARDUINO_AVR_UNO)// Arduino Uno
    #define PIN_L     A1
    #define PIN_R     A0
    #define RANDOM_PIN_SEED A3
#elif defined(ATTINY85)// Attny85
    #define PIN_L     A0
    #define PIN_R     A1
    #define RANDOM_PIN_SEED A3
#endif

#define NUM_OF_PIXELS 36

class Glasses{
    
    private:
        byte _numOfLeds;
        CRGB _rightEye[NUM_OF_PIXELS];
        CRGB _leftEye[NUM_OF_PIXELS];
    
    public:
        byte NUMOFPIXELS = NUM_OF_PIXELS;

        Glasses() {
            random16_add_entropy(analogRead(RANDOM_PIN_SEED));
            FastLED.addLeds<NEOPIXEL, PIN_R>(_rightEye, NUM_OF_PIXELS);
            FastLED.addLeds<NEOPIXEL, PIN_L>(_leftEye, NUM_OF_PIXELS);

        }

        bool exists(byte row, byte column) {
            /*
             * returns true : The LED exists
             *         false: the LED doesn't exist
            */
            switch (row) {
                case 0:
                    switch (column) {
                        case 0:
                        case 1:
                        case 2:
                        case 3:
                        case 4:
                        case 5:
                        case 6:
                            break;
                        default:
                            return false;
                    }
                    break;
                case 1:
                    switch (column) {
                        case 1:
                        case 2:
                        case 3:
                        case 4:
                        case 5:
                        case 6:
                        case 7:
                            break;
                        default:
                            return false;
                    }
                    break;
                case 2:
                    switch (column) {
                        case 0:
                        case 1:
                        case 3:
                        case 4:
                        case 5:
                        case 6:
                        case 7:
                            break;
                        default:
                            return false;
                    }
                    break;
                case 3:
                    switch (column) {
                        case 1:
                        case 3:
                        case 4:
                        case 5:
                            break;
                        default:
                            return false;
                    }
                    break;
                case 4:
                    switch (column) {
                        case 1:
                        case 3:
                        case 4:
                        case 5:
                        case 6:
                        case 7:
                            break;
                        default:
                            return false;
                    }
                    break;
                case 5:
                    switch (column) {
                        case 3:
                        case 4:
                        case 5:
                        case 6:
                        case 7:
                            break;
                        default:
                            return false;
                    }
                    break;
                default:
                    return false;
            }
            return true;
        }

        bool rightEye(byte row, byte column, CHSV colour){
            /*
             * returns true : The LED exists and a colour was assigned
             *         false: The LED doesn't exist
            */
            switch (row) {
                case 0:
                    switch (column) {
                        case 0:
                            _rightEye[7] = colour;
                            break;
                        case 1:
                            _rightEye[6] = colour;
                            break;
                        case 2:
                            _rightEye[5] = colour;
                            break;
                        case 3:
                            _rightEye[4] = colour;
                            break;
                        case 4:
                            _rightEye[3] = colour;
                            break;
                        case 5:
                            _rightEye[2] = colour;
                            break;
                        case 6:
                            _rightEye[1] = colour;
                            break;
                        default:
                            return false;
                    }
                    break;
                case 1:
                    switch (column) {
                        case 1:
                            _rightEye[23] = colour;
                            break;
                        case 2:
                            _rightEye[22] = colour;
                            break;
                        case 3:
                            _rightEye[21] = colour;
                            break;
                        case 4:
                            _rightEye[20] = colour;
                            break;
                        case 5:
                            _rightEye[19] = colour;
                            break;
                        case 6:
                            _rightEye[18] = colour;
                            break;
                        case 7:
                            _rightEye[0] = colour;
                            break;
                        default:
                            return false;
                    }
                    break;
                case 2:
                    switch (column) {
                        case 0:
                            _rightEye[8] = colour;
                            break;
                        case 1:
                            _rightEye[24] = colour;
                            break;
                        case 3:
                            _rightEye[33] = colour;
                            break;
                        case 4:
                            _rightEye[32] = colour;
                            break;
                        case 5:
                            _rightEye[31] = colour;
                            break;
                        case 6:
                            _rightEye[30] = colour;
                            break;
                        case 7:
                            _rightEye[17] = colour;
                            break;
                        default:
                            return false;
                    }
                    break;
                case 3:
                    switch (column) {
                        case 1:
                            _rightEye[9] = colour;
                            break;
                        case 3:
                            _rightEye[25] = colour;
                            break;
                        case 4:
                            _rightEye[34] = colour;
                            break;
                        case 5:
                            _rightEye[35] = colour;
                            break;
                        default:
                            return false;
                    }
                    break;
                case 4:
                    switch (column) {
                        case 1:
                            _rightEye[10] = colour;
                            break;
                        case 3:
                            _rightEye[26] = colour;
                            break;
                        case 4:
                            _rightEye[27] = colour;
                            break;
                        case 5:
                            _rightEye[28] = colour;
                            break;
                        case 6:
                            _rightEye[29] = colour;
                            break;
                        case 7:
                            _rightEye[16] = colour;
                            break;
                        default:
                            return false;
                    }
                    break;
                case 5:
                    switch (column) {
                        case 3:
                            _rightEye[11] = colour;
                            break;
                        case 4:
                            _rightEye[12] = colour;
                            break;
                        case 5:
                            _rightEye[13] = colour;
                            break;
                        case 6:
                            _rightEye[14] = colour;
                            break;
                        case 7:
                            _rightEye[15] = colour;
                            break;
                        default:
                            return false;
                    }
                    break;
                default:
                    return false;
            }
            return true;
        }

        
        bool leftEye(byte row, byte column, CHSV colour){
            /*
             * returns true : The LED exists and a colour was assigned
             *         false: The LED doesn't exist
            */
            switch (row) {
                case 0:
                    switch (column) {
                        case 0:
                            _leftEye[0] = colour;
                            break;
                        case 1:
                            _leftEye[1] = colour;
                            break;
                        case 2:
                            _leftEye[2] = colour;
                            break;
                        case 3:
                            _leftEye[3] = colour;
                            break;
                        case 4:
                            _leftEye[4] = colour;
                            break;
                        case 5:
                            _leftEye[5] = colour;
                            break;
                        case 6:
                            _leftEye[6] = colour;
                            break;
                        default:
                            return false;
                    }
                    break;
                case 1:
                    switch (column) {
                        case 1:
                            _leftEye[18] = colour;
                            break;
                        case 2:
                            _leftEye[19] = colour;
                            break;
                        case 3:
                            _leftEye[20] = colour;
                            break;
                        case 4:
                            _leftEye[21] = colour;
                            break;
                        case 5:
                            _leftEye[22] = colour;
                            break;
                        case 6:
                            _leftEye[23] = colour;
                            break;
                        case 7:
                            _leftEye[7] = colour;
                            break;
                        default:
                            return false;
                    }
                    break;
                case 2:
                    switch (column) {
                        case 0:
                            _leftEye[17] = colour;
                            break;
                        case 1:
                            _leftEye[30] = colour;
                            break;
                        case 3:
                            _leftEye[31] = colour;
                            break;
                        case 4:
                            _leftEye[32] = colour;
                            break;
                        case 5:
                            _leftEye[33] = colour;
                            break;
                        case 6:
                            _leftEye[24] = colour;
                            break;
                        case 7:
                            _leftEye[8] = colour;
                            break;
                        default:
                            return false;
                    }
                    break;
                case 3:
                    switch (column) {
                        case 1:
                            _leftEye[16] = colour;
                            break;
                        case 3:
                            _leftEye[29] = colour;
                            break;
                        case 4:
                            _leftEye[35] = colour;
                            break;
                        case 5:
                            _leftEye[34] = colour;
                            break;
                        default:
                            return false;
                    }
                    break;
                case 4:
                    switch (column) {
                        case 1:
                            _leftEye[15] = colour;
                            break;
                        case 3:
                            _leftEye[28] = colour;
                            break;
                        case 4:
                            _leftEye[27] = colour;
                            break;
                        case 5:
                            _leftEye[26] = colour;
                            break;
                        case 6:
                            _leftEye[25] = colour;
                            break;
                        case 7:
                            _leftEye[9] = colour;
                            break;
                        default:
                            return false;
                    }
                    break;
                case 5:
                    switch (column) {
                        case 3:
                            _leftEye[14] = colour;
                            break;
                        case 4:
                            _leftEye[13] = colour;
                            break;
                        case 5:
                            _leftEye[12] = colour;
                            break;
                        case 6:
                            _leftEye[11] = colour;
                            break;
                        case 7:
                            _leftEye[10] = colour;
                            break;
                        default:
                            return false;
                    }
                    break;
                default:
                    return false;
            }
            return true;
        }

        byte * generatePoint() {
            /*
             * Generate the row and column of a point at random
            */
            byte random_column;
            byte random_row;
            static byte point[2];
            while (true) {
                random_column = random16(7);
                random_row = random16(5);
                if (Glasses::exists(random_row, random_column)) {
                    break;
                }
                random_column = random16(7);
                random_row = random16(5);
            }
            point[0] = random_row;
            point[1] = random_column;

            return point;

        }

        void randomLED(CHSV colour, byte which_eye) {
            /*
            * Light a random LED of a particular colour
            * which_eye :  1 - right
            *              2 - left
            *  anything else - both
            */
           bool status = false;
            if (which_eye != 1) {
                while (true) {
                    byte random_column = random16(7);
                    byte random_row = random16(5);

                    status = Glasses::leftEye(random_row, random_column, colour);
                    if (status) {break;}
                }
            }
            if (which_eye != 2) {
                while (true) {
                    byte random_column = random16(7);
                    byte random_row = random16(5);

                    status = Glasses::rightEye(random_row, random_column, colour);
                    if (status) {break;}
                }
            }
        }
        
        void show() {
            FastLED.show();
        }

        void clearRightEye() {
            fill_solid(_rightEye, NUM_OF_PIXELS, CRGB(0,0,0));
            FastLED.show();
        }

        void clearLeftEye() {
            fill_solid(_leftEye, NUM_OF_PIXELS, CRGB(0,0,0));
            FastLED.show();
        }

        void clear() {
            Glasses::clearRightEye();
            Glasses::clearLeftEye();
        }
        
};


#endif