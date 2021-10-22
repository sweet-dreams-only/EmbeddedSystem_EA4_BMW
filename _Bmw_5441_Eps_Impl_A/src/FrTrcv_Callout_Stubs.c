#include "FrTrcv_30_Tja1082_Cbk.h"
/* Vector manual TechnicalReference_FrTrcv_Tja1082.pdf page 11 recommends time delay when switching between different Transceiver modes.
Since, the transceiver is always in NORMAL mode, no time delay required */
FUNC(void, FRTRCV_30_TJA1082_CODE) Appl_FrTrcv_30_Tja1082_Wait(uint8 TimerIndex)
{
	return;
}
