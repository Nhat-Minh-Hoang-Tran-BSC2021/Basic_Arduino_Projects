/*
 * Chương trình này lần lượt đọc ngõ vào nối tiếp và sử dụng nó để thiết lập các chân cho thanh ghi dịch 74HC595
 * 74HC595 kết nối với chân 2, 3 và 4 của Arduino như được trình bày chi tiết bên dưới
 * LED gắn liền với mỗi đầu ra của thanh ghi dịch
 */

const int latchPin = 8;
const int clockPin = 12;
const int dataPin = 10;

void setup()
{
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    Serial.begin(9600);
    Serial.println("reset");
}

void loop()
{
    if (Serial.available() > 0)
    {
        //Ký tự ASCII '0' tới '9' là
        //Giá trị được thể hiện từ 48 tới 59
        //Nếu người dùng nhập số từ 0 tới 9 theo ASCII,
        //Chúng ta có thể trừ cho 48 để có giá trị thật
        int bitToSet = Serial.read() - 48;

        //Ghi vào thanh ghi dịch chuyển với bit đặt chính xác cao
        registerWrite(bitToSet, HIGH);
    }
}

//Phương thức này gửi các bit đến thanh ghi dịch chuyển:
void registerWrite(int whichPin, int whichState)
{
    byte bitsToSend = 0; //Các bit muốn gửi đi

    digitalWrite(latchPin, LOW);

    //Bật bit cao nhất tiếp theo trong bitsToSend
    bitWrite(bitsToSend, whichPin, whichState);

    //Dịch các bit ra:
    shiftOut(dataPin, clockPin, MSBFIRST, bitsToSend);

    digitalWrite(latchPin, HIGH);    
}

