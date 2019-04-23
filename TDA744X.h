#ifndef _TDA744X_H_
#define _TDA744X_H_

#include "Arduino.h"
#include "SendTrans.h"

 #if defined(Surr_SIMULATED) || defined(Surr_MUSIC) || defined(Surr_MOVIE) || defined(Surr_OFF)
   #undef Surr_SIMULATED 
   #undef Surr_MUSIC     
   #undef Surr_OFF      
 #endif
   #define Surr_SIMULATED 0
   #define Surr_MUSIC     1
   #define Surr_OFF       2

 #if defined(ATT_LR)|| defined(ATT_RR) || defined(ATT_LF) || defined(ATT_RF)
   #undef ATT_LR
   #undef ATT_RR
   #undef ATT_LF
   #undef ATT_RF
  #endif
    #define ATT_LR 2
    #define ATT_RR 3
  
  #if defined(REAR_ACTIVE) || defined(REAR_OFF)
   #undef REAR_ACTIVE
   #undef REAR_OFF
  #endif
  
  #if defined(NATURALBASE_ACTIVE) || defined(NATURALBASE_OFF)
   #undef NATURALBASE_ACTIVE
   #undef NATURALBASE_OFF
  #endif

  #if defined(VOICECANCELLER_OFF) || defined(VOICECANCELLER_ON)
   #undef VOICECANCELLER_OFF
   #undef VOICECANCELLER_ON
  #endif
  
  #if defined(Out_3BAND) || defined(Out_SURR) || defined(Out_REAR) || defined(Out_FLAT)
   #undef Out_3BAND
   #undef Out_SURR
   #undef Out_REAR
   #undef Out_FLAT
   #undef Out_OFF
  #endif

  #if defined(RecOut_L) || defined(RecOut_R)
   #undef RecOut_L
   #undef RecOut_R
  #endif
  
  #if defined(Use_NEGATIVE) || defined(Use_POSITIVE)
    #undef Use_NEGATIVE 
    #undef Use_POSITIVE 
  #endif
    #define Use_NEGATIVE -1
    #define Use_POSITIVE 1

  #if defined(MUTE_OFF) || defined(MUTE_ON)
    #undef MUTE_OFF  
    #undef MUTE_ON 
  #endif
    #define MUTE_OFF  0
    #define MUTE_ON 1

class TDA7442 : public SendTransI2C{
  public:
    int8_t begin();

    int8_t UseValue(int8_t val = Use_POSITIVE);

    int8_t Input(int8_t val);   //Input

    int8_t Volume(int8_t val);  //Volume
    int8_t Bass(int8_t val);    //Bass
    int8_t Treble(int8_t val);  //Treble

    int8_t Balance(int8_t val);
    int8_t Balance(int8_t val,int8_t val2);

    int8_t PhaseResistor(int8_t val);

    int8_t EffectControl(int8_t val);
    
    int8_t SurroundMode(int8_t val);  //Surround Mode
    int8_t Surround_SIMULATED();      //SIMULATED
    int8_t Surround_MUSIC();          //MUSIC
    int8_t Surround_OFF();            //OFF

    int8_t Mute(int8_t val);
    int8_t Mute(int8_t val,int8_t val2);
    int8_t DisableMute();
    int8_t EnableMute();

  protected:
    byte _DATA[8];
    int8_t MaxInput(int8_t val = 4);
    int16_t Constrain(int16_t val,int16_t val2,int16_t val3);
    int8_t _UPN,_MInput;
};

#endif
