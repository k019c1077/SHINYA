#define LED_PIN 14
#define PIN_SW 4
#define Delaytime 10
int Brightness = 0;

int prev = 0;
int in; // 現在のswの状態
int led;
void setup()
{
    pinMode(LED_PIN, OUTPUT);
    pinMode(PIN_SW, INPUT_PULLUP);
    ledcSetup(0, 490, 8);
    ledcAttachPin(14, 0);
    Serial.begin(115200);
}
void loop()
{

    in = get_sw(prev); // swの状態を読みinに代入

    if (prev != in)
    {}
        prev = in;
        if (in == HIGH)
        {
            while (Brightness < 256)
            {
                ledcWrite(0, Brightness);
                Brightness += 10;
                delay(Delaytime);
            }
            Brightness = 255;
            ledcWrite(0, Brightness);
        }
        else
        {
            while (Brightness > 0)
            {
                ledcWrite(0, Brightness);
                Brightness -= 10;
                delay(Delaytime);
            }
            Brightness = 0;
            ledcWrite(0, Brightness);
        }
    }
    delay(100);
}
int get_sw(int sw_out)
{
    int in1, in2;

    in1 = digitalRead(PIN_SW); // GPIO14から入力 GPIO14はPullUpしてある
    delay(100);                // 要調整
    in2 = digitalRead(PIN_SW);

    if (in1 == in2)
    {
        sw_out = in2;
    }
    return (sw_out);
}
