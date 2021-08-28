void stop()
{
    analogWrite(IN1, 0);
    analogWrite(IN2, 0);
    analogWrite(IN3, 0);
    analogWrite(IN4, 0);
}

void straight(int input)
{
    analogWrite(IN1, input);
    analogWrite(IN2, 0);
    analogWrite(IN3, input);
    analogWrite(IN4, 0);
}

void back(int input)
{
    analogWrite(IN1, 0);
    analogWrite(IN2, input);
    analogWrite(IN3, 0);
    analogWrite(IN4, input);
}

void left(int input)
{
    analogWrite(IN1, input);
    analogWrite(IN2, 0);
    analogWrite(IN3, input/4);
    analogWrite(IN4, 0);
}

void right(int input)
{
    analogWrite(IN1, input/4);
    analogWrite(IN2, 0);
    analogWrite(IN3, input);
    analogWrite(IN4, 0);
}
