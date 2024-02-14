#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <mraa.h>
#define ANALOG_PIN 73 // Assuming the analog pin is A0

void error(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

float analogToTemperature(int analogValue) {
    float Vo = (float)analogValue;
    float R1 = 10000.0; // Value of R1 on board
    float logR2, R2, T, K;
    float c1 = 0.001129148, c2 = 0.000234125, c3 = 0.0000000876741;

    // Corrected calculation for R2
    R2 = R1 * (1023.0 / Vo - 1.0);
    logR2 = log(R2);
    K = 1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2);
    T = K - 232.15; // Convert Kelvin to Celsius

    return T;
}

int readAnalogValue(mraa_aio_context analogPin) {
    return mraa_aio_read(analogPin);
}

int main() {
    mraa_result_t result;
    mraa_aio_context analogPin;

    // Initialize MRAA
    mraa_init();

    // Initialize analog pin
    analogPin = mraa_aio_init(ANALOG_PIN);
    if (analogPin == NULL) {
        error("Failed to initialize analog pin");
    }

    while (1) {
        int analogValue = readAnalogValue(analogPin);
        float temperature = analogToTemperature(analogValue);
        printf("Analog Value: %d, Temperature: %.2f\n", analogValue, temperature);

        // Adjust the sleep duration based on your sensor's update rate
        sleep(1); // Sleep for 1 second between readings
    }

    // Close analog pin
    result = mraa_aio_close(analogPin);
    if (result != MRAA_SUCCESS) {
        error("Failed to close analog pin");
    }

    // Deinitialize MRAA
    mraa_deinit();

    return 0;
}

