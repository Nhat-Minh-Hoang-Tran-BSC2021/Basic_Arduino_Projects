/*
 * Dieu khien 8 LED bang IC HC595
 */
int latchPin = 8;
int clockPin = 12;
int dataPin = 11;

byte ledStatus;
void setup(){
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
}

void loop(){
    //Thao tac tren BitMath
    //Sáng tuần tự
    ledStatus = 0; //mặc định là không có đèn nào sáng hết (0b00000000)
    for (int i =0; i <8; i++){
        ledStatus = (ledStatus << 1) | 1; //Đẩy toàn bộ các bit sang bên trái 1 bit và cộng 1 vào bit có giá trị là 1 ở bit 0

        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, MSBFIRST, ledStatus);
        digitalWrite(latchPin, HIGH); // Các led sẽ sáng với trạng thái vừa được cập nhật

        delay(500);
    }

    //Tắt tuần tự
    for (int i =0; i < 8; i++){
        ledStatus <<= 1; //Đẩy các bit sang bên trái 1 bit

        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, MSBFIRST, ledStatus);
        digitalWrite(latchPin, HIGH);

        delay (500);
    }
}

