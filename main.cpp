#include <fastgpioomega2.h>

#define HIGH 1
#define LOW 0

int start(int pin, int repeat, int pause);
void pulse(FastGpioOmega2 *gpioObj, int pin, int pause);

int main(int argc, char **argv)
{
    int repeat = 15;
    printf("Pulsing for the %d times\n", repeat);

    start(1, repeat, 100000);

    printf("Finished pulsing %d times\n", repeat);
}

int start(int pin, int repeat, int pause)
{
    FastGpioOmega2 *gpio = new FastGpioOmega2();
    gpio->SetDirection(pin, 1);

    for (int i = 0; i < repeat; i++)
    {
        printf("Pulsed for the %dth time\n", i + 1);
        pulse(gpio, pin, pause);
    }
	
    delete gpoi;
}

void pulse(FastGpioOmega2 *gpio, int pin, int pause)
{
    gpio->Set(pin, HIGH);
    usleep(pause);
    gpio->Set(pin, LOW);
    usleep(pause);
}
