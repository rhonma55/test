#include "mbed.h"

DigitalOut myled(LED1);
DigitalIn mybutton(BUTTON1);
PwmOut pwmled(D3);
PwmOut myservo(D3);
DigitalOut teepuled (D2);

void FizzBuzz()
{
    int n = 1;
    while (1)
    {
        if(n%3 == 0 && n%5 == 0)
        {
            printf("fizzbuzz\n");
        }
        else if(n%3 == 0)
        {    
            printf("fizz\n");
        }
        else if(n%5 == 0)
        {
            printf("buzz\n");
        }
        else
        {
            printf("%d\n",n);
        }
        n ++; 
        ThisThread::sleep_for(1s);
    }
}

void printfkansu ()
{
    int n = 0;
    while (1)
    {
        printf("aaa""%d",n);
        fflush(stdout);
        n++;
        ThisThread::sleep_for(1s);
    }
}

void bbb ()
{
    ThisThread::sleep_for(6s);
    
}

void aaa ()
{
    ThisThread::sleep_for(6s);
    for(int rare=1; rare<=9; rare++)
    {
        for(int ru=1; ru<=9; ru++)
        {
            printf("%d\t",rare*ru);
            fflush(stdout);
        }
        printf("\n");
        fflush(stdout);
    }
}

void PWM()
{
    while(1)
    {
        for (float n=1;n>=0; n=n-0.1)
        {
            pwmled = n;
            printf("%f\n",n);
            ThisThread::sleep_for(1s);
        }
        ThisThread::sleep_for(3s);
    }
}

void SERVO()
{
    int  m = 500;
    while(1)
    {
        for(int n=600; n<2400; n=n+200)
        {
            myservo.pulsewidth_us(n);
            ThisThread::sleep_for(500ms);
        }
        for(int n=2400; n>600; n=n-200)
        {
            myservo.pulsewidth_us(n);
            ThisThread::sleep_for(500ms);
        }
    }
}

void code0 ()
{
    // printf("c0");
    teepuled = 1;
    wait_ns(300);
    teepuled = 0;
    wait_ns(950);
}
void code1 ()
{
    // printf("c1");
    teepuled = 1;
    wait_ns(800);
    teepuled = 0;
    wait_ns(450);
}
void resetcode ()
{
    // printf("re\n");
    teepuled = 0;
    wait_ns(5e4);
}

void ccc ()
{    
    for(int n=8; n>0; n--)
    {
        code1();
    }
    for(int n=16; n>0; n--)
    {
        code0();
    }
    resetcode();    
}

void printb(int value)
{
    char buffer[25];
    buffer[24] = '\0';

    for (int i=23; i>=0; i--) {
        buffer[i] = (value & 1) ? '1' : '0';
        value >>= 1;
    }

    printf("in : %s   ", buffer);
}

int main()
{
    while(1)
    {
    ccc();
    }
}