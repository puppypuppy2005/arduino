
#define BLINKER_WIFI
 
#include <Blinker.h>
 
char auth[] = "20feb71e9ab2";
//char ssid[] = "8-403";
char ssid[] = "happytonny";
char pswd[] = "1234567890";
 
// 新建组件对象
BlinkerButton Button1("btn-abc");
BlinkerNumber Number1("num-abc");
 
int counter = 0;
 
// 按下按键即会执行该函数
void button1_callback(const String & state) {
   // Serial.println("Button pressed");
    BLINKER_LOG("get button state: ", state);
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    
}
 
// 如果未绑定的组件被触发，则会执行其中内容
void dataRead(const String & data)
{
    BLINKER_LOG("Blinker readString: ", data);
    counter++;
    Number1.print(counter);
}
 
void setup() {
    // 初始化串口
    Serial.begin(115200);
 
    BLINKER_DEBUG.stream(Serial);
    
    // 初始化有LED的IO
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    // 初始化blinker
    Blinker.begin(auth, ssid, pswd);
    Blinker.attachData(dataRead);
    Button1.attach(button1_callback);
}
 
void loop() {
    Blinker.run();
}