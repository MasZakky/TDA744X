#include "TDA744X.h"

int8_t TDA7442::begin(){
  _Address = 0x40;
}

int8_t TDA7442::UseValue(int8_t val){
  _UPN = val;
  return Process_OK;
}

int8_t TDA7442::Input(int8_t val){
  val = constrain(val,1,4);
  if(_MInput == 4){
    if(val == 1) val = 3;
    else val = val - 2;

    if((int8_t)_DATA[7] == val) return Process_OK;
    
    _DATA[7] = val;
    return TDA7442::setWrite(9,_DATA[7]);
  }
}

int8_t TDA7442::Volume(int8_t val){
  val = Constrain(val,0,63);
  if((int8_t)_DATA[0] == val) return Process_OK;
  
   _DATA[0] = val;
  return TDA7442::setWrite(0,_DATA[0]);
}

int8_t TDA7442::Bass(int8_t val){
  val = constrain(val,-7,7);
  if(val < 0)  val = val + 7;
  else val = 8 + (7 - val);
  if((int8_t)_DATA[3] == val )  return Process_OK;
  
  _DATA[3] = val;
  return TDA7442::setWrite(3,_DATA[3]);
}

int8_t TDA7442::Treble(int8_t val){
  val = constrain(val,-7,7);
  if(val < 0)  val = val + 7;
  else val = 8 + (7 - val);
  if((int8_t)(_DATA[4]>>4) == val)  return Process_OK;
  _DATA[4] = (val<<4) | 0x0E;
  return TDA7442::setWrite(4,_DATA[4]);
}

int8_t TDA7442::Balance(int8_t val){
  TDA7442::Balance(val,ATT_LR);
  return TDA7442::Balance(val,ATT_LR);
}
int8_t TDA7442::Balance(int8_t val,int8_t val2){
  val = Constrain(val,0,79);
  val2 = constrain(val2,0,1);
  switch(val2){
    case ATT_LR: if(_DATA[5] != val) return TDA7442::setWrite(5,(_DATA[5] = val)); break;
    case ATT_RR: if(_DATA[6] != val) return TDA7442::setWrite(6,(_DATA[6] = val)); break;
  }
  return Process_OK;
}

int8_t TDA7442::PhaseResistor(int8_t val){
  val = constrain(val,0,3);
  if(_DATA[2] == val) return Process_OK;
  return TDA7442::setWrite(2,(_DATA[2] = val));
}

int8_t TDA7442::EffectControl(int8_t val){
  val = constrain(val,-21,-6);
  val = val * -1 - 6;
  if((_DATA[1]>>4) == val) return Process_OK;

  return TDA7442::setWrite(1,(_DATA[0] = val));
}

int8_t TDA7442::SurroundMode(int8_t val){
  val = constrain(val,0,2);
  if((_DATA[1]&0x0F) == val) return Process_OK;
  _DATA[1] = (_DATA[1]&(~(0x0F))) | val;
  return TDA7442::setWrite(1,_DATA[1]);
}

int8_t TDA7442::Surround_SIMULATED(){
  return TDA7442::SurroundMode(Surr_SIMULATED);
}
int8_t TDA7442::Surround_MUSIC(){
  return TDA7442::SurroundMode(Surr_MUSIC);
}
int8_t TDA7442::Surround_OFF(){
  return TDA7442::SurroundMode(Surr_OFF);  
}


int8_t TDA7442::Mute(int8_t val){
  TDA7442::Mute(val,ATT_LR);
  return TDA7442::Mute(val,ATT_RR);
}
int8_t TDA7442::Mute(int8_t val,int8_t val2){
  val = constrain(val,0,1);
  val2 = constrain(val2,0,3);
  if(val == 0){
    switch(val2){
      case ATT_LR: return TDA7442::Balance(_DATA[3],val2); break;
      case ATT_RR: return TDA7442::Balance(_DATA[4],val2); break;
    }
  }
  else{
    switch(val2){
      case ATT_LR: return TDA7442::setWrite(3,0x50); break;
      case ATT_RR: return TDA7442::setWrite(4,0x50); break;
    }
  }
}
int8_t TDA7442::DisableMute(){
  return TDA7442::Mute(MUTE_OFF);
}
int8_t TDA7442::EnableMute(){
  return TDA7442::Mute(MUTE_ON);
}

int16_t TDA7442::Constrain(int16_t val,int16_t val2,int16_t val3){
  if(_UPN != Use_POSITIVE){
    return constrain(val,(-1*val3),val2);
  }
  else{
    return constrain(val,val2,val3);
  }
}

int8_t TDA7442::MaxInput(int8_t val){
  _MInput = val;
}
