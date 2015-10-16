const int pingPin = 7;
const int threshold = 24000;

void setup() {
  Serial.begin(57600);
}

void loop() {
  int cm ;
  
  cm = UsonicMeasurRead(pingPin) ;   // センサーから距離を調べる
  
  if (Serial.available() > 0) {
    Serial.write(cm >> 8);
    Serial.write(cm & 255);
  }

  Serial.read();

  delay(100);
}


// 超音波センサーから距離を得る処理
// pin=センサーに接続しているピン番号
// 距離をｃｍで返す(検出できない場合は０を返す)
int UsonicMeasurRead(int pin) {
  long t ;
  int ans ;

  // 超音波センサーに5usのパルスを出力する
  pinMode(pin, OUTPUT) ;             // ピンを出力モードにする
  digitalWrite(pin, LOW) ;
  delayMicroseconds(2) ;
  digitalWrite(pin, HIGH) ;
  delayMicroseconds(5) ;
  digitalWrite(pin, LOW) ;

  // センサーからの反射パルスを受信する
  pinMode(pin, INPUT) ;              // ピンを入力モードにする
  t = pulseIn(pin, HIGH) ;           // パルス幅の時間を測る
  if (t < threshold) {                   // ３ｍ以上の距離は計算しない
    ans = (t / 29) / 2 ;          // 往復なので２で割る
  } else ans = 0 ;

  return ans ;
}
