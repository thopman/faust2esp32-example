# faust2esp32-example
faust-esp32 example using esp-idf 4.3

oddly enough i had to edit one line in the faust generated code to get it to compile. 

in the i2s_config i had to change the following line from:

.sample_rate = uint32_t(fSampleRate),

to

.sample_rate = fSampleRate,

the typecast was originally needed but apparently not anymore. 
