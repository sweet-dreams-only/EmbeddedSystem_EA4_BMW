#include "Os.h"
#include "SchM_Fr.h"
#include "FrIf.h"
#include "FrIf_Priv.h"


/* Synchronization interrupt for flexray */
void ApplFr_ISR_CycleStart(void)
{
	IncrementCounter(FrCycleCounter);
}
