#include "global.h"

uint16_t  htou16(uint16_t data){
   uint16_t  rst = 0;
   uint8_t *pHeader =  reinterpret_cast<uint8_t*>(&rst);
   *pHeader = data >> 8;
   *(pHeader+1) = data & 0xff;
   return rst;
}
