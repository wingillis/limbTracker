// include libraries up here

// global variables

// pin positions of mux controllers
int muxByte1 = 0;
int muxByte2 = 0;
int muxByte3 = 0;
int muxInputSelect = 0;
// use byteRead(muxInputSelect, [part of byte]) for output

#define WINDOW_SIZE 10
int index_position = 0;

#define SERIAL
// there are up to 10 accelerometers (some may be replaced with spi or i2c)
// this means up to 30 analog inputs. Teensy supports up to 21
int lowerLeftLegInputs[] = {A0, A1, A2}; // (x, y, z)
int lowerRightLegInputs[] = {A3, A4, A5};
int upperLeftLegInputs[] = {A6, A7, A8};
int upperRightLegInputs[] = {A9, A10, A11};
int lowerLeftArmInputs[] = {A12, A13, A14};
int lowerRightArmInputs[] = {A15, A16, A17};
// both left and right upper arm will be used with a digital input device

accelerometer lowerRightArm;
accelerometer lowerLeftArm;
accelerometer lowerLeftLeg;
accelerometer lowerRightLeg;
accelerometer upperRightLeg;
accelerometer upperLeftLeg;

long timer1 = 0;

void setup()
{
    analogReadResolution(12);
    pinMode(muxByte1, OUTPUT);
    pinMode(muxByte2, OUTPUT);
    pinMode(muxByte3, OUTPUT);
    #ifdef SERIAL
        Serial.begin(115200);
    #endif

}

void loop() {
    // read in the values of each accelerometer
    timer1 = millis();
    readAnalogInputs(lowerRightLeg, lowerRightLegInputs);
    averageInputs(lowerRightLeg, index_position);
    readAnalogInputs(lowerLeftLeg, lowerLeftLegInputs);
    averageInputs(lowerLeftLeg, index_position);
    readAnalogInputs(lowerRightArm, lowerRightArmInputs);
    averageInputs(lowerRightArm, index_position);
    readAnalogInputs(lowerLeftArm, lowerLeftArmInputs);
    averageInputs(lowerLeftArm, index_position);
    readAnalogInputs(upperLeftLeg, upperLeftLegInputs);
    averageInputs(upperLeftLeg, index_position);
    readAnalogInputs(upperRightLeg, upperRightLegInputs);
    averageInputs(upperRightLeg, index_position);

    #ifdef SERIAL
        sendTimeInformation(timer1, millis(), "Reading 6 analog accelerometers");
        sendInformationToSerial();
    #endif



    index_position++;
    if(index_position >= WINDOW_SIZE) index_position = 0;
}