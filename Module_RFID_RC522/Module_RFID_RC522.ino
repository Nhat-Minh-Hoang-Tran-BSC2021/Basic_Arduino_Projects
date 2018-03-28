/*
* MOSI: Pin 11 / ICSP-4
* MISO: Pin 12 / ICSP-1
* SCK: Pin 13 / ISCP-3
* SS: Pin 10
* RST: Pin 9
*/
 
#include <Servo.h>
#include <SPI.h>
#include <RFID.h>
 
#define SS_PIN 10
#define RST_PIN 9
Servo myservo;
RFID rfid(SS_PIN, RST_PIN);
 
unsigned char reading_card[5]; // Mảng đọc mã card
unsigned char master[5] = { 134, 138, 22, 126, 100 }; // Mã Card phù hợp để mở cửa
unsigned char slave[5] = { 246, 253, 148, 53, 170 }; // Mã Card phù hợp để đóng cửa
 
unsigned char i, j;
 
void setup()
{
 
    myservo.attach(8);
    Serial.begin(9600);
    SPI.begin();
    rfid.init();
    myservo.write(30);
}
 
void loop()
{
    if (rfid.isCard()) {
        if (rfid.readCardSerial()) // Nếu có thẻ
        {
 
            for (i = 0; i < 5; i++) {
 
                reading_card[i] = rfid.serNum[i]; //Lưu mã thẻ đọc được vào mảng reading_card
            }
            Serial.println();
            //verification
            for (i = 0; i < 5; i++) {
                //So sáng từng phần tử của mảng reading_card với mảng master
                if (reading_card[i] != master[i]) //Nếu có 1 phần tử bất kỳ nào không phù hợp...thỳ thoát vòng lặp, lúc này ta nhận được giá trị của i
                {
                    break;
                }
            }
            // Tương tự với thẻ Slave
            for (j = 0; j < 5; j++) {
                if (reading_card[i] != slave[i]) {
                    break;
                }
            }
            if (i == 5) // Nếu các phần tử của màng reading_card phù hợp hết với mảng master thì lúc này i chạy đến 5
            {
                myservo.write(180); // đóng cửa
            }
            if (j == 5) {
                myservo.write(30); // mở cửa
            }
        }
        rfid.halt();
    }
}
