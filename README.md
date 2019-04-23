# Library TDA744X
<h3>Digitally Audio Processor</h3>
<ul>
   <li><a href="https://www.st.com/resource/en/datasheet/tda7440.pdf" >TDA7440</a> OK</li>
   <li><a href="https://4donline.ihs.com/images/VipMasterIC/IC/SGST/SGSTS23994/SGSTS23994-1.pdf?hkey=EF798316E3902B6ED9A73243A3159BB0">  TDA7442</a> OK </li>
   <li><a href="http://rtellason.com/chipdata/tda7443.pdf">TDA7443</a></li>
</ul>

<h3>Download Library !! </h3>
<h4>(Right Mouse Button + Open Link In New Tab)</h4>
<ul>
  <li><a href=https://github.com/MasZakky/SendTrans">Library SendTrans</a></li>
  <li><a href=https://github.com/MasZakky/TDA743X"  >Library TDA743X</a></li>
  <li><a href=https://github.com/MasZakky/TDA744X"  >Library TDA744X</a></li>
  <li><a href=https://github.com/MasZakky/PT231X"   >Library PT231X</a></li>
</ul>

<h5>Example Param</h5>

    #include "TDA743X.h"
    TDA7440 uPA;  
    //TDA7442 uPA;
    //TDA7443 uPA;
    
    void setup(){ 
      Wire.begin();
      uPA.InstalWire(&Wire);
      Serial.begin(9600); 
      
      if(uPA.InstalWire(&Wire) != Process_OK) Serial.println("Process_ERROR");
      else Serial.println("Process_OK");
      
      if(uPA.begin() =! Process_OK) Serial.print("Process_ERROR");
      else Serial.println("Process_OK");
      
    } // void setup
    
    void loop(){
    // Do something?
    } 


<h3> Main </h3>
<h4><a href="https://github.com/MasZakky/SendTrans" target="_blank"> Command </a>: </h4>
      
    1. int8_t InstalWire(TwoWire *val);
         Default => NULL
         Syntax:
         - InstalWire(&Wire);
         - InstalWire(&Wire1);
         - InstalWire(&Wire2);
         
    // additional
    2. int8_t setMultiPlexer(int8_t val,int8_t val2);
                       Value     ,IC MuliPlexer
         Default => Not_UseSwitch & Use_TCA9548A 
         Value   => Not_UseSwitch or Yes_UseSwitch
         IC      => Use_TCA9548A
    
    3. int8_t setAddressMultiPlexer(byte Address,byte val1,byte val2,byte val3,byte val4);
                                 Value       ,A0       ,A1       ,A2       ,A3 or 0
         Default     => _AddressTCA9548A & A0 = 0 & A1 = 0 & A2 = 0 & A3 = 0                           
         Value       => Address IC MuliPlexer
         pinAddr     => A0,A1,A2,A3/0
    
    4. int8_t setChannel(int8_t val);
                      Channel
         Default => 0
         Channel => 0 ~ 7
    

<h3>TDA7440 </h3>
<h4> Command : </h4>

    1.  int8_t begin();

    2.  int8_t UseValue(int8_t val); 
          Default => Use_POSITIVE 
          Value   => Use_POSITIVE or Use_NEGATIVE 

    3.  int8_t Input(int8_t val); 
          Default  => 1
          TDA7438 maks Input => 3       (3 Stereo)
          TDA7439 maks Input => 4 (FIX) (4 Stereo)
          
    4.  int8_t Gain(int8_t val);
          Default => 15 (30dB)
          Value   => 0 ~ 15 => 0dB ~ 30dB (2dB Step);
    
    5.  int8_t Volume(int8_t val);
          Default => 0 (0dB)
          UserValue == Use_POSITIVE => Volume 0 ~ 47  => 0dB ~ -47dB (1dB Step)
          UserValue == Use_NEGATIVE => Volume -47 ~ 0 => -47dB ~ 0dB (1dB Step)
    
    6.  int8_t Bass(int8_t val);
          Default => 7 (14dB)
          Value   => -7 ~ 7 => -14dB ~ 14dB (2dB Step)
    
    7.  int8_t Treble(int8_t val);
          Default => 7 (14dB)
          Value   => -7 ~ 7 => -14dB ~ 14dB (2dB Step)
  
    8.  int8_t Balance(int8_t val);
    9.  int8_t Balance(int8_t val,int8_t val2);   
                       Value     ,Channel 
          Default => 0dB  
          UserValue == Use_POSITIVE => Balance 0 ~ 79  => 0dB ~ -79dB (1dB Step)
          UserValue == Use_NEGATIVE => Balance -79 ~ 0 => -79dB ~ 0dB (1dB Step)
          Channel => ATT_LR or ATT_RR

    
    10. int8_t Mute(int8_t val);              
    11. int8_t Mute(int8_t val,int8_t val2);  
                    Value     ,Channel    
    12. int8_t DisableMute();                 
    13. int8_t EnableMute();
          Default => MUTE_OFF
          Value   => MUTE_OFF or MUTE_ON 
          Channel => ATT_LR or ATT_RR 

<h3>TDA7442</h3>
<h4>Command</h4>

    1.  int8_t begin();

    2.  int8_t UseValue(int8_t val);
          Default => Use_POSITIVE
          Value   => Use_POSITIVE or Use_NEGATIVE
         
    3.  int8_t Input(int8_t val);
          Value   => 1 ~ 4 

    4.  int8_t Volume(int8_t val);
          UserValue == Use_POSITIVE => Volume 0 ~ 63  (0.5dB Step)
          UserValue == Use_NEGATIVE => Volume -63 ~ 0 (0.5dB Step)

    5.  int8_t Bass(int8_t val);
          Value   => -7 ~ 7  => -14 dB ~ 14 dB (2dB Step)
         
    6.  int8_t Treble(int8_t val);  //Treble
          Value   => -7 ~ 7  => -14 dB ~ 14 dB (2dB Step)
       
    7.  int8_t Balance(int8_t val);
    8.  int8_t Balance(int8_t val,int8_t val2);
                      Value     ,Channel
          UserValue == Use_POSITIVE => Balance 0 ~ 79 
          UserValue == Use_NEGATIVE => Balance -79 ~ 0
          Channel => ATT_LR or ATT_RR
 
    9.  int8_t PhaseResistor(int8_t val);
          Value => 0 ~ 3 

    10. int8_t EffectControl(int8_t val);
          Value => -21 ~ -6 (1 Step)
    
    11. int8_t SurroundMode(int8_t val);  
    12. int8_t Surround_SIMULATED();
    13. int8_t Surround_MUSIC();
    14. int8_t Surround_OFF();
          Value => Surr_SIMULATED,Surr_MUSIC, or Surr_OFF

    15. int8_t Mute(int8_t val);
    16. int8_t Mute(int8_t val,int8_t val2);
                    Value     ,Channel
    17. int8_t DisableMute();
    18. int8_t EnableMute();
          Value   => MUTE_OFF or MUTE_ON
          Channel => ATT_LR or ATT_RR
                    
<h4>Notice</h4>
<pre><h5> 
    if  defined(__AVR_AT90Mega169__)  or defined(__AVR_ATmega169__)   or
        defined(__AVR_AT90Mega165__)  or defined(__AVR_ATmega165__)   or
        defined(__AVR_ATmega325__)    or defined(__AVR_ATmega3250__)  or
        defined(__AVR_ATmega645__)    or defined(__AVR_ATmega6450__)  or
        defined(__AVR_ATmega329__)    or defined(__AVR_ATmega3290__)  or
        defined(__AVR_ATmega649__)    or defined(__AVR_ATmega6490__)  or
        defined(__AVR_ATtiny25__)     or defined(__AVR_ATtiny45__)    or defined(__AVR_ATtiny85__) or
        defined(__AVR_AT90Tiny26__)   or defined(__AVR_ATtiny26__)    or
        defined(__AVR_ATtiny84__)     or defined(__AVR_ATtiny44__)    or
        defined(__AVR_AT90Tiny2313__) or defined(__AVR_ATtiny2313__)
            Automatic disable "InstalWire" and "Wire" will be replaced with "TinyWireM" 
            Download<a href="https://github.com/adafruit/TinyWireM" target="_blank"> TinyWireM library </a>
        
        
        
</h5></pre>
