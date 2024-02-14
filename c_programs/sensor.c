#include <stdio.h>
#include <unistd.h>
#include <mraa.h>

#define ANALOG_PIN_NUMBER 6  // Replace with the actual GPIO pin for analog sensor

void error(const char *msg) {
    perror(msg);
    exit(1);
}

mraa_aio_context analogPin;

void initializeAnalogPin() {
    analogPin = mraa_aio_init(ANALOG_PIN_NUMBER);
    if (analogPin == NULL) {
        error("Error initializing analog pin");
    }
}

void cleanupAnalogPin() {
    mraa_aio_close(analogPin);
}

int readAnalogValue() {
    return mraa_aio_read(analogPin);
}

float convertToTemperature(int rawValue) {
    // You need to calibrate this conversion based on the characteristics of your specific temperature sensor
    // This is just an example conversion, you may need to refer to the sensor's datasheet for accurate conversion
    float voltage = (float)rawValue / 1024.0 * 5.0;  // Convert raw value to voltage
    float temperature = (voltage - 0.5) * 100.0;  // Convert voltage to temperature in Celsius

    return temperature;
}

int main() {
    mraa_init();

    initializeAnalogPin();

    while (1) {
        int analogValue = readAnalogValue();
        float temperature = convertToTemperature(analogValue);

        printf("Temperature: %.2f°C\n", temperature);

        // Adjust the sleep duration based on your sensor's update rate
        sleep(1);  // Sleep for 1 second between readings
    }

    cleanupAnalogPin();

    mraa_deinit();

    return 0;
}

