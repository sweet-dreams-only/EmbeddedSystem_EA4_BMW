/* for contract folder of CM107A_MemProtn */

#ifndef OS_H
#define OS_H

void Call_IpgInin(void);

extern void SuspendAllInterrupts(void);
extern void ResumeAllInterrupts(void);
extern void SuspendOSInterrupts(void);
extern void ResumeOSInterrupts(void);

#endif
