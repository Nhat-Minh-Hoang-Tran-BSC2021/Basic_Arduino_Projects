// dùng const đặt trước khi khai báo biến sẽ coi biến này là một hằng số
// Bạn có thể đọc được giá trị biến hoặc thực hiện các phép tính toán
// Nhưng không thay đổi được giá trị của hằng số này
const int buttonPin = 11; // Hằng số buttonPin mang giá trị là chân digital được nối với button
const int ledPin = 2; // Hằng số ledPin mang giá trị là chân digital được nối với led

//Các biến này có thể thay đổi được
int buttonPushCounter = 0; // Số lần button được nhấn
int buttonState = 0; // trạng thái hiện tại của button
int lastButtonState = 0; // trạng thái trước đó của button

void setup(){
    pinMode(buttonPin, INPUT);
    pinMode(ledPin, OUTPUT);

    Serial.begin(9600);
}

void loop(){
    buttonState = digitalRead(buttonPin);
    if (buttonState != lastButtonState){
        if (buttonState == HIGH){
            //Nếu trạng thái bây giờ là button đang được nhấn
            //thì hiển nhiên trước đó là button chưa được nhấn
            //chúng ta sẽ tăng số lần nhấn button lên 1
            buttonPushCounter++;
            Serial.println("Dang nhan");
            Serial.print("So lan nhan la: ");
            Serial.println("buttonStateCounter: ");
        }

        else{
            //Nếu trạng thái bây giờ là button được thả
            //thì hiển nhiên trước đó là button được nhấn (điều khiện trên)
            //Chúng ta sẽ thông báo là button đang được thả và không làm gì cả
            Serial.println("off");
        }
    }

    //lưu lại trạng thái button cho lần kiểm tra tiếp theo
    lastButtonState = buttonState;

    //Đã đếm được số lần nhấn buttom, bây giờ sẽ là phần sau bao nhiêu
    //lần thì button sẽ làm đèn sáng
    //Trong ngôn ngữ lập trình Arduino, chúng ta có thêm một phép toán mới
    //đó là phép toán chia lấy dư (moudlo %)
    //Áp dụng:
    //Chẳng hạn, bạn làm button này cứ sau 4 lần nhấn sẽ làm đèn sáng vì bạn làm như sau:
    //Mới upload code thì đèn sáng do buttonPushCounter = 0. 0% 4 = 0
    //Sau đó cứ mỗi lần nhấn nút thì buttonPushCounter được tăng lên
    //1 % 4 = 1 => tắt
    //2 % 4 = 2 => tắt
    //3 % 4 = 3 => tắt
    //4 % 4 = 0 => tắt
    //5 % 4 = 1 => tắt
    //...
    if (buttonPushCounter % 4 == 0){
        digitalWrite(ledPin, HIGH);
        Serial.println("Da bat den");
    }
    
    else {
        digitalWrite(ledPin, LOW);
    }
}

