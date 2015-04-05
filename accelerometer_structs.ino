struct accelerometer
{
    int x;
    int y;
    int z;
    float xwindow[WINDOW_SIZE];
    float ywindow[WINDOW_SIZE];
    float zwindow[WINDOW_SIZE];
    float xavg;
    float yavg;
    float zavg;
};

void readAnalogInputs(struct accelerometer acc, int analogIns[]){
    /// assumes a length 3 analog array
    acc.x = analogRead(analogIns[0]);
    acc.y = analogRead(analogIns[1]);
    acc.z = analogRead(analogIns[2]);
}

void averageInputs(struct accelerometer acc, int index_position) {
    acc.xwindow[index_position] = acc.x/WINDOW_SIZE;
    acc.ywindow[index_position] = acc.y/WINDOW_SIZE;
    acc.zwindow[index_position] = acc.z/WINDOW_SIZE;
    acc.xavg = sumArray(acc.xwindow, WINDOW_SIZE);
    acc.yavg = sumArray(acc.ywindow, WINDOW_SIZE);
    acc.zavg = sumArray(acc.zwindow, WINDOW_SIZE);
}

float sumArray(float array[], int length) {
    float s = 0;
    for (i=0; i<length; i++) {
        s = s + array[i];
    }
    return s;
}

void readFromMux() {
    // set mux analog pin values, the read the analog output

    // should I have a delay?
}

void sendInformationToSerial() {
    // currently this function only gives the x, y, z int values
    // of the accelerometers
    Serial.println("Values from lower right leg");
    Serial.println(formatResponse(lowerRightLeg));
    Serial.println();
    Serial.println("Values from lower left leg");
    Serial.println(formatResponse(lowerLeftLeg));
    Serial.println();
    Serial.println("Values from upper right leg");
    Serial.println(formatResponse(upperRightLeg));
    Serial.println();
    Serial.println("Values from upper left leg");
    Serial.println(formatResponse(upperLeftLeg));
    Serial.println();
    Serial.println("Values from lower right arm");
    Serial.println(formatResponse(lowerRightArm));
    Serial.println();
    Serial.println("Values from lower left arm");
    Serial.println(formatResponse(lowerLeftArm));
    Serial.println();


}

String formatResponse(struct accelerometer acc) {
    return sprintf("x: %d,\ty: %d,\tz: %d", acc.x, acc.y, acc.z);
}