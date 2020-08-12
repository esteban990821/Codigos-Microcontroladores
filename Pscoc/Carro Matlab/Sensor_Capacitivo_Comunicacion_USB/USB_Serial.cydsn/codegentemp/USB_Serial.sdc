# THIS FILE IS AUTOMATICALLY GENERATED
# Project: D:\Users\ESTEBAN\Desktop\Materias\Codigos\Pscoc\Carro Matlab\Sensor_Capacitivo_Comunicacion_USB\USB_Serial.cydsn\USB_Serial.cyprj
# Date: Sun, 12 May 2019 02:54:35 GMT
#set_units -time ns
create_clock -name {ADC_2_theACLK(routed)} -period 625 -waveform {0 312.5} [list [get_pins {ClockBlock/dclk_0}]]
create_clock -name {ADC_1_theACLK(routed)} -period 625 -waveform {0 312.5} [list [get_pins {ClockBlock/dclk_1}]]
create_clock -name {CyILO} -period 10000 -waveform {0 5000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 15.625 -waveform {0 7.8125} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 15.625 -waveform {0 7.8125} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_generated_clock -name {ADC_2_theACLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 41 81} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {ADC_1_theACLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 41 81} [list [get_pins {ClockBlock/dclk_glb_1}]]


# Component constraints for D:\Users\ESTEBAN\Desktop\Materias\Codigos\Pscoc\Carro Matlab\Sensor_Capacitivo_Comunicacion_USB\USB_Serial.cydsn\TopDesign\TopDesign.cysch
# Project: D:\Users\ESTEBAN\Desktop\Materias\Codigos\Pscoc\Carro Matlab\Sensor_Capacitivo_Comunicacion_USB\USB_Serial.cydsn\USB_Serial.cyprj
# Date: Sun, 12 May 2019 02:54:31 GMT
