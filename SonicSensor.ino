#define pingPin  7       // センサー接続のピン番号

const int threshold = 12000;

//  電源起動時とリセットの時だけのみ処理される関数(初期化と設定処理)
void setup() {
  Serial.begin(57600) ;   // 57600bpsでシリアル通信のポートを開きます
}
//  繰り返し実行される処理の関数(メインの処理)
void loop() {
     int cm ;
     int mm ;
     int result;
     
     cm = UsonicMeasurRead(pingPin) ;   // センサーから距離を調べる
     result = map(cm, 0, threshold, 0, 255);
     Serial.write(result);
     
     if(mm <= 20){
      mm = 0;
     }else if(mm > 20 && mm <= 40){
      mm = 1;
     }else if(mm > 40 && mm <= 60){
      mm = 2;
     }else if(mm > 60 && mm <= 80){
      mm = 3;
     }else if(mm > 80 && mm <= 100){
      mm = 4;
     }else if(mm > 100 && mm <= 120){
      mm = 5;
     }else if(mm > 120 && mm <= 140){
      mm = 6;
     }else if(mm > 140 && mm <= 160){
      mm = 7;
     }else if(mm > 160 && mm <= 180){
      mm = 8;
     }else if(mm > 180 && mm <= 200){
      mm = 9;
     }
     
     //Serial.print(mm);

     delay(100) ;                      // 0.02s後に繰り返す
}
// 超音波センサーから距離を得る処理
// pin=センサーに接続しているピン番号
// 距離をｃｍで返す(検出できない場合は０を返す)
int UsonicMeasurRead(int pin)
{
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
