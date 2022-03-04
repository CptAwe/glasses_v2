#ifndef Glasses_h
#define Glasses_h

#include "Arduino.h"
#include "FastLED.h"

#if defined(ARDUINO_AVR_UNO)// Arduino Uno
    #define PIN_L     A1
    #define PIN_R     A0
#elif defined(ATTINY85)// Attny85
    #define PIN_L     A0
    #define PIN_R     A1
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

            FastLED.addLeds<NEOPIXEL, PIN_R>(_rightEye, NUM_OF_PIXELS);
            FastLED.addLeds<NEOPIXEL, PIN_L>(_leftEye, NUM_OF_PIXELS);

        }

        bool rightEye(byte row, byte column, CHSV colour){
            /*
             * returns true : it was ok
             *         false: the LED doesn't exist
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
                        case 2:
                            _rightEye[33] = colour;
                            break;
                        case 3:
                            _rightEye[32] = colour;
                            break;
                        case 4:
                            _rightEye[31] = colour;
                            break;
                        case 5:
                            _rightEye[30] = colour;
                            break;
                        case 6:
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
                        case 2:
                            _rightEye[25] = colour;
                            break;
                        case 3:
                            _rightEye[34] = colour;
                            break;
                        case 4:
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
             * returns true: it was ok
             *         false: the LED doesn't exist
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
                        case 2:
                            _leftEye[31] = colour;
                            break;
                        case 3:
                            _leftEye[32] = colour;
                            break;
                        case 4:
                            _leftEye[33] = colour;
                            break;
                        case 5:
                            _leftEye[24] = colour;
                            break;
                        case 6:
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
                        case 2:
                            _leftEye[29] = colour;
                            break;
                        case 3:
                            _leftEye[35] = colour;
                            break;
                        case 4:
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

        void show() {
            FastLED.show();
        }

        void clear() {
            fill_solid(_rightEye, NUM_OF_PIXELS, CRGB(0,0,0));
            fill_solid(_leftEye, NUM_OF_PIXELS, CRGB(0,0,0));
            FastLED.show();
        }
        
};


#endif