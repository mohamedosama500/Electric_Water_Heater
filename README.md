# Electric_Water_Heater
simulation using PICSimlab:
- Implementation of drivers like I2C, External E2PROM and ADC in PIC microcontroller. 
- Adjusting the desired temperature by controlling it through the heater and the cooler in the PICSimLab. 
- Used tools and drivers: I2C, External E2PROM, ADC, 7-Segment, Relay, switches, MPLAB and PICSimLab.   

Specifications: 

1)The “Heating Element” should be turned OFF, if the current water temperature is greater than the set temperature by 5 degrees. 

2)The “Cooling Element” should be turned ON, if the current water temperature is greater than the set temperature by 5 degrees. 

3)If the electric water heater is turned OFF then ON, the stored set temperature should be retrieved from the “External E2PROM”. 

4)A single “Up” button press increase the set temperature by 5 degrees. 

5)A single “Down” button press decrease the set temperature by 5 degrees. 

6)If the “Heating Element” is ON, the “Heating Element Led” should blink  every 1 second. 

7)If the “Cooling Element” is ON, the “Heating Element Led” should be ON.
