#ifndef	_EE24_H
#define	_EE24_H

#ifdef __cplusplus
extern "C" {
#endif
/*
  Author:     Nima Askari
  WebSite:    http://www.github.com/NimaLTD
  Instagram:  http://instagram.com/github.NimaLTD
  Youtube:    https://www.youtube.com/channel/UCUhY7qY1klJm1d2kulr9ckw
  
  Version:    2.2.1
  
  
  Reversion History:
  
  (2.2.1)
  Fix erase chip bug.
  
  (2.2.0)
  Add erase chip function.
  
  (2.1.0)
  Fix write bytes.
  
  (2.0.0)
  Rewrite again.

*/


#include "main.h"


BOOL ee24_isConnected(void);
BOOL ee24_write(uint16_t address, uint8_t *data, size_t lenInBytes, uint32_t timeout);
BOOL ee24_read(uint16_t address, uint8_t *data, size_t lenInBytes, uint32_t timeout);
BOOL ee24_eraseChip(void);

#ifdef __cplusplus
}
#endif

#endif
