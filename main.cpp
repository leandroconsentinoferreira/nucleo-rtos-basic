#include "mbed.h"


Serial pc(USBTX, USBRX);

void print_char()
{
    int a = rand();
    pc.printf("A = %d \n", a);
    //fflush(stdout);
}

Thread thread;

DigitalOut led1(LED1);

void print_thread()
{
    while (true) {
        wait(1);
        int b = rand();
        pc.printf("B = %d \n", b);
        print_char();
    }
}

int main()
{
    srand (time(NULL));
    pc.printf("RTOS basic example \n");
    // fflush(stdout);
    thread.start(print_thread);

    while (true) {
        led1 = !led1;
        wait(0.5);
    }
}
