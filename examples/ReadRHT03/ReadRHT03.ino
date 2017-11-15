#include <Maxdetect_RHT03.h>

double humidity = 0;
double temperature = 0;

int sensorPin = D0;
Maxdetect_RHT03 sensor(sensorPin);

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    delay(2000);
    sensor.update();
    temperature = sensor.getTemperature();//获取温度
    humidity = sensor.getHumidity();
    Serial.println("t/rh");
    Serial.println(temperature);
    Serial.println(humidity);
}
