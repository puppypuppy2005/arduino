#include <Arduino.h>

//关于IRRemote的代码示例
#include <IRremote.h>
IRrecv irrecv(2);  //定义接收引脚为2

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); //启动红外接收
}

void loop() {
  if (irrecv.decode()) {
    ; //将解码结果赋值给results
    Serial.println(irrecv.decodedIRData.command); //打印红外编码
    Serial.println(irrecv.decodedIRData.extra); //打印红外编码的位数
    irrecv.resume(); //继续接收下一个编码
    //打印irrecv的类型
    
  }
  delay(500);
  
  // put your main code here, to run repeatedly:
}

