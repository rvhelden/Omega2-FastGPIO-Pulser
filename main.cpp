#include "main.h"
#include <fastgpioomega2.h>

void pulse(FastGpioOmega2 *gpioObj, int pinNum, int highMicros, int lowMicros)
{
    gpioObj->Set(pinNum, 1);
    usleep(highMicros);
    gpioObj->Set(pinNum, 0);
    usleep(lowMicros);
}

int pulseGpio(FastGpioOmega2 *gpioObj, int pinNum, int repeats, int upTime, int downTime)
{
	gpioObj->SetDirection(pinNum, 1);

    for (int i = 0; i < repeats; i++)
    {
        printf("Pulsed for the %dth time\n", i + 1);
        pulse(gpioObj, pinNum, upTime, downTime);
    }
}

int main(int argc, char **argv)
{
    int times = 15;
    printf("Pulsing for the %d times\n", times);

    FastGpioOmega2 *fast = new FastGpioOmega2();
    pulseGpio(fast, 1, times, 50000, 50000);

    printf("Finished pulsing %d times\n", times);
}