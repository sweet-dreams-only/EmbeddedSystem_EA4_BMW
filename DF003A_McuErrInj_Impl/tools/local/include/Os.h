/* header file for contract folder of CM101A */

#ifndef OS_H
#define OS_H

extern void SuspendAllInterrupts(void);
extern void ResumeAllInterrupts(void);
extern void SuspendOSInterrupts(void);
extern void ResumeOSInterrupts(void);

extern void osSetIMRmEI(uint16);

extern uint32 osGlobalShared_StartAddr;

#define Call_McuDiagcTestTrustd		McuDiagcTestTrustd

extern void ActivateTask(uint8);
#endif

