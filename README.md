# LDR Shutter Speed Tester
Shutter Speed Tester that uses a photodiode light-dependent resistor (LDR) to measure and evaluate the shutter speeds of cameras. It leverages an Arduino Uno for processing, providing accurate timing information and comparisons to predefined standard shutter speeds.

### Standard Shutter Speeds Used (not tested with higher speeds)
- 1/15
- 1/30
- 1/60
- 1/125
- 1/250
- 1/500
- 1/1000
### Components
- Arduino Uno
- Photodiode Light Dependent Resistor (LDR)
- Connecting wires
- Breadboard
- Optional: Capacitor (e.g., 0.1µF) to reduce noise in the signal.
- Optional: 10kΩ Fixed Resistor (or an adjustable resistor for tuning sensitivity)

TODO: Include a simple schematic of the circuit here.

### Install
- Clone this repository:
```bash
git clone https://github.com/bz888/LDR-shutter-speed-tester.git
```
### Sample Output
```
start 133618424
stop 133651800
duration micro: 33376
duration ms: 33.38
duration sec: 0.03338
shutter speed: 1/29.96
```
### Tuning the Circuit
Adjust the fixed resistor (R2) to control the sensitivity of the circuit:
Higher resistance increases sensitivity but may slow response time.
Lower resistance decreases sensitivity but improves speed.
