/* header file for contract folder of CM475A */

#ifndef CDD_MOTCTRLMGR_DATA_H
#define CDD_MOTCTRLMGR_DATA_H

#ifndef Rte_TypeDef_PhaDiscnctPwmVect1
    typedef uint8 PhaDiscnctPwmVect1;
#endif

#ifndef PHADISCNCTPWMVECT_NOCMD
    #define PHADISCNCTPWMVECT_NOCMD (0U)
#endif
#ifndef PHADISCNCTPWMVECT_PHAACMD
    #define PHADISCNCTPWMVECT_PHAACMD (1U)
#endif
#ifndef PHADISCNCTPWMVECT_PHABCMD
    #define PHADISCNCTPWMVECT_PHABCMD (2U)
#endif
#ifndef PHADISCNCTPWMVECT_PHACCMD
    #define PHADISCNCTPWMVECT_PHACCMD (4U)
#endif


extern MotCurrEolCalSt2 MOTCTRLMGR_MotCtrlMotCurrEolCalSt;
extern uint32 MOTCTRLMGR_MotCtrlPwmPerd;
extern uint32 MOTCTRLMGR_MotCtrlPhaOnTiA;
extern uint32 MOTCTRLMGR_MotCtrlPhaOnTiB;
extern uint32 MOTCTRLMGR_MotCtrlPhaOnTiC;
extern uint32 MOTCTRLMGR_MotCtrlTSG31DCMP0E;
extern uint32 MOTCTRLMGR_MotCtrlTSG31CMPUE;
extern uint32 MOTCTRLMGR_MotCtrlTSG31CMPVE;
extern uint32 MOTCTRLMGR_MotCtrlTSG31CMPWE;
extern uint32 MOTCTRLMGR_MotCtrlTSG31CMP0E;
extern uint32 MOTCTRLMGR_MotCtrlTSG31CMP12E;

extern boolean MOTCTRLMGR_MotCtrlPhaDiscnctDiagcActv;
extern PhaDiscnctPwmVect1 MOTCTRLMGR_MotCtrlPhaDiscnctDiagcPwmVect;


#endif

