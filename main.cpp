#include <fastgpioomega2.h>

#define HIGH 1
#define LOW 0

int pulseGpio(FastGpioOmega2 *gpio, int pin, int repeat, int pause);
void pulse(FastGpioOmega2 *gpioObj, int pin, int pause);

int main(int argc, char **argv)
{
    int repeat = 15;
    printf("Pulsing for the %d times\n", repeat);

    FastGpioOmega2 *gpio = new FastGpioOmega2();
    pulseGpio(gpio, 1, repeat, 100000);

    printf("Finished pulsing %d times\n", repeat);
}

int pulseGpio(FastGpioOmega2 *gpio, int pin, int repeat, int pause)
{
	gpio->SetDirection(pin, 1);

    for (int i = 0; i < repeat; i++)
    {
        printf("Pulsed for the %dth time\n", i + 1);
        pulse(gpio, pin, pause);
    }
}

void pulse(FastGpioOmega2 *gpioObj, int pin, int pause)
{
    gpioObj->Set(pin, HIGH);
    usleep(pause);
    gpioObj->Set(pin, LOW);
    usleep(pause);
}