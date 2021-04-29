
[![Compile-Linux](https://github.com/256653/LnT_EmbeddedC/actions/workflows/compile.yml/badge.svg)](https://github.com/256653/LnT_EmbeddedC/actions/workflows/compile.yml)
[![Cppcheck](https://github.com/256653/LnT_EmbeddedC/actions/workflows/code.yml/badge.svg)](https://github.com/256653/LnT_EmbeddedC/actions/workflows/code.yml)

# SEAT HEATING MECHANISM
1. The user enters the car and occupies the seat.
2. He/She turns on the heat sensor.
3. If both of the above condition are met, then the LED will turn ON.
4. The user has to adjust the temperature.
5. The temperature value will be diplayed on the screen.
6. The seat will be cooled accordingly.

# SIMULATION RESULTS

## Activity 1

If the user seated on the seat, he has to turn on the heat button, only then the LED should turn ON.

| Logic State | LED Status |
| ----- | ----- |
| 0 0 | OFF |
| 0 1 | OFF |
| 1 0 | OFF |
| 1 1 | ON |

## Activity 2

**To take input from temperature sensor and to indicate changes at a particular temparture.**

Since temperature sensor is not availaible in simul ide, potentiometer is used and the voltages are calculated for particular range.

|Voltage(V)|Analog Value|Status|
|----|----|----|
|0.0-1.0|0-200|B1 LED ON|
|1.2-2.4|210-500|B2 LED ON|
|2.5-3.6|510-700|B3 LED ON|
|3.8-5.0|710-1024|B4 LED ON|

### Simulation Results

## Activity 3

**To generate PWM at different analog values**

|ADC Value(Temp Sensor)|Output PWM|
|----|----|
|0-200|20%|
|210-500|40%|
|510-700|70%|
|710-1024|95%|

### Simulation Results

## Activity 4

**To send the temperature value to Serial monitor**