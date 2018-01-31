const int ledPin = 13;    // 아두이노 보드에 있는 led
int blinkRate = 0;

bool isGuideMessageDisplay = true;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if(isGuideMessageDisplay) {
    Serial.println("0부터 9 사이의 숫자를 입력해주세요.");
    isGuideMessageDisplay = false;
  }
  if(Serial.available()) {    
    //isGuideMessageDisplay = true;

    // #1. serial.read로 읽어옴. 하나 하나씩 읽어와서, 숫자인지 체크
    /*char ch = Serial.read();
    if(isDigit(ch)) {
      blinkRate = ch - '0';
      blinkRate = blinkRate * 100;
      Serial.print(ch);
      Serial.println(" (으)로 값을 설정하셨습니다.");
      Serial.println("==========================================");
    }*/

    // #2. Serial.parseInt() 이용
    int number = Serial.parseInt();
    blinkRate = number * 100;
    Serial.print(number);
    Serial.println(" (으)로 값을 설정하셨습니다.");
    Serial.println("==========================================");
    
    isGuideMessageDisplay = true;    
  }
  blink();
}

void blink() {
  digitalWrite(ledPin, HIGH);
  delay(blinkRate);
  digitalWrite(ledPin, LOW);
  delay(blinkRate);
}

