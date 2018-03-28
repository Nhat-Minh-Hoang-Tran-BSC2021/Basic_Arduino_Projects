int led=10;
void setup() {
  pinMode (led,OUTPUT);
  Serial.begin(9600);  //Mở cổng Serial để giap tiếp | tham khảo Serial
}
 
void loop() {
  int value = analogRead(A0);   //đọc giá trị điện áp ở chân A0 
                                //(value luôn nằm trong khoảng 0-1023)
  Serial.println(value);        //xuất ra giá trị vừa đọc
  
  int voltage;
  voltage = map(value,0,1023,0,255);   //chuyển thang đo của value 
                                        //từ 0-1023 sang 0-5000 (mV)
  Serial.println(voltage);              //xuất ra điện áp (đơn vị là mV)
  
  Serial.println();     //xuống hàng
  delay(200);           //đợi 0.2 giây
  analogWrite(led, voltage);
}
