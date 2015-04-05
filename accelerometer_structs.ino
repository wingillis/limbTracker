struct accelerometer
{
    int x;
    int y;
    int z;
    float xwindow[WINDOW_SIZE];
    float ywindow[WINDOW_SIZE];
    float zwindow[WINDOW_SIZE];
    int xavg;
    int yavg;
    int zavg;
};

void readAnalogInputs(struct accelerometer acc, int analogIns[]){
    /// assumes a length 3 analog array
    acc.x = analogRead(analogIns[0]);
    acc.y = analogRead(analogIns[1]);
    acc.z = analogRead(analogIns[2]);
}

