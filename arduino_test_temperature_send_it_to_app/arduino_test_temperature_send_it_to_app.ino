/*

 作用:使用arduino模拟口测量室内温度
 
*/
void setup() {
  Serial.begin(9600);         //使用9600速率进行串口通讯
   Serial.println("I have ready");        //
}

void loop() {

  int n = analogRead(A0);    //读取A0口的电压值

  float vol = n * (5.0 / 1023.0*100);   //使用浮点数存储温度数据，温度数据由电压值换算得到

  Serial.println(vol);                   //串口输出温度数据
  delay(2000);                           //等待2秒，控制刷新速度

  
  if(Serial.available() > 0)            //判断串口缓冲器是否有数据载入
  {
    int value;
    int ctrl=2;
  value = Serial.read();                      //读取串口数据
  analogWrite(ctrl,value);
  Serial.println("OK! You have sended a message!Your english is very bad!!!!");
  delay(10);
  }
}



