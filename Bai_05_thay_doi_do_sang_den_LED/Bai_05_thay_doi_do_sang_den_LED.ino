int led = 6;
int brightness = 0;
int fadeAmount = 5; //the amout of every light changes

void setup(){
    //pinMode den led la OUTPUT
    pinMode(led, OUTPUT);
}

void loop() {
    //xuat ra gia tri do sang den LED
    analogWrite(led, brightness);

    //thay doi gia tri la den LED
    brightness = brightness + fadeAmount;

    //If brightness == 0 or 255, brightness will be positive or negative
    if (brightness == 0 || brightness == 255) {
        fadeAmount = -fadeAmount;
    }

    //wait for 30ms to see changes
    delay(30); 
}

