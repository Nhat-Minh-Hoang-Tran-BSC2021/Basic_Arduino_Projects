int inputPin = 2;       // chọn ngõ tín hiệu vào cho PIR
int pirState = LOW;     // Bắt đầu với không có báo động
int val = 0;
int pinSpeaker = 10;    //chọn chân cho chuông khi có đột nhập
const int trig = 8;     // chân trig của HC-SR04
const int echo = 7;     // chân echo của HC-SR04
 
void setup()
{
  pinMode(inputPin, INPUT);
  pinMode(pinSpeaker, OUTPUT);
  pinMode(trig,OUTPUT);   // chân trig sẽ phát tín hiệu
  pinMode(echo,INPUT);    // chân echo sẽ nhận tín hiệu
  Serial.begin(9600);
}
 
void loop()
{
  val = digitalRead(inputPin);    // đọc giá trị đầu vào.
  if (val == HIGH)                // nếu giá trị ở mức cao.(1)
  {
    unsigned long duration; // biến đo thời gian
    int distance;           // biến lưu khoảng cách
    
    /* Phát xung từ chân trig */
    digitalWrite(trig,0);   // tắt chân trig
    delayMicroseconds(2);
    digitalWrite(trig,1);   // phát xung từ chân trig
    delayMicroseconds(5);   // xung có độ dài 5 microSeconds
    digitalWrite(trig,0);   // tắt chân trig
    
    /* Tính toán thời gian */
    // Đo độ rộng xung HIGH ở chân echo. 
    duration = pulseIn(echo,HIGH);  
    // Tính khoảng cách đến vật.
    distance = int(duration/2/29.412);
    
    /* In kết quả ra Serial Monitor */
    Serial.print(distance);
    Serial.println("cm");

    digitalWrite(pinSpeaker, HIGH);
    
    delay(200);
 
    if (pirState == LOW)
    {
      Serial.println("Motion detected!");
      pirState = HIGH;
    }
  }
  else
  {
    digitalWrite(pinSpeaker, LOW);
    
    delay(300);
    if (pirState == HIGH)
    {
      Serial.println("Motion ended!");
      pirState = LOW;
    }
  }
}
 

