// Nếu đọc cảm biến hồng ngoại ra 1 -> có line
// Nếu đọc cảm biến hồng ngoại ra 0 -> không line
// 2^3 = 8 trường hợp
// Nếu cảm biến giữa là 1, cảm biến trái phải là 0 -> đi thằng                   1
// Nếu cả ba cảm biến đều cho 0  -> lệch line  -> lùi                            1
// Nếu cả ba cảm biến đều cho 1 -> lùi để kiểm tra lại                           1
// Nếu hai cảm biến trái phải là 1, cảm biến giữa là 0 -> lùi check lại          1
// Nếu cảm biến trái và giữa là 1, cảm biến phải là 0 -> rẽ trái                 1
// Nếu cảm biến phải và giữa là 1, cảm biến trái là 0 -> rẽ phải                 1
// Nếu cảm biến phải là 1, cảm biến giữa và cảm biến trái là 0 -> rẽ phải        1
// Nếu cảm biến trái là 1, cảm biến giữa và cảm biến phải là 0 -> rẽ phải        1
//-----------------------------------------------------------------------------------
//                                                                         Sum = 8
// ----------------------------------------------------------------------------------
//KHAI BÁO HỒNG NGOẠI
const int IRL = 8;
const int IRC = 7;
const int IRR = 4;
//-----------------------------------------------------------------------------------
//KHAI BÁO CHÂN ĐIỀU KHIỂN ĐỘNG CƠ
const int IN1 = 5;
const int IN2 = 6;
const int IN3 = 9;
const int IN4 = 10;
//-----------------------------------------------------------------------------------
//KHAI BÁO ĐỌC CÁC CHÂN IR
int read_IRL;
int read_IRC;
int read_IRR;
//-----------------------------------------------------------------------------------
int start = 0;
//-----------------------------------------------------------------------------------
const int LED = 13;
//-----------------------------------------------------------------------------------
int speed = 60;
int time_wait_long = 300;
int time_wait_short = 200;
//-----------------------------------------------------------------------------------
void setup()
{
    pinMode(IRL, INPUT);
    pinMode(IRC, INPUT);
    pinMode(IRR, INPUT);

    pinMode(LED, OUTPUT);
}

void loop()
{  
    if (start == 0)
    {
        stop();
        delay(2000);
        start = 1;
    }

    digitalWrite(LED, HIGH);

    read_IRL = digitalRead(IRL);
    read_IRC = digitalRead(IRC);
    read_IRR = digitalRead(IRR);

    if(read_IRL == 1 && read_IRC == 1 && read_IRR==1)
    {
        back(speed);
    }

    if(read_IRL == 1 && read_IRC == 1 && read_IRR==0)      
    {
        left(speed);
        delay(time_wait_long);
    }

    if(read_IRL == 0 && read_IRC == 1 && read_IRR==1)
    {
        right(speed);
        delay(time_wait_long);
    }

    if(read_IRL == 0 && read_IRC == 1 && read_IRR==0)
    {
        straight(speed);
    }

    if(read_IRL == 1 && read_IRC == 0 && read_IRR==1)
    {
        back(speed);
    }

    if(read_IRL == 0 && read_IRC == 0 && read_IRR==1)
    {
        right(speed);
        delay(time_wait_short);
    }

    if(read_IRL == 1 && read_IRC == 0 && read_IRR==0)
    {
        left(speed);
        delay(time_wait_short);
    }

    if (read_IRL == 0 && read_IRC == 0 && read_IRR==0)
    {
        back(speed);
    }
}
