/**********************************************************************************************************************
* Copyright 2017 Nxtr
* Nxtr Confidential
*
* Module File Name  : NxtrMathNonRte.c
* Module Description: Nxtr Math Library Source File
* Project           : CBD
* Author            : Jared Julien
***********************************************************************************************************************
* Version Control:
* %version:          3 %
* %derived_by:       kzdyfh %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                             SCR #
* --------  -------  --------  -----------------------------------------------------------------------------  ---------
* 05/24/17  1        JWJ       Created with sine table from NxtrMath.c and function to catch errno            EA4#12469
* 09/19/17  2        JWJ       Added error injection function called by DF003A                                EA4#15504
* 10/10/17  3        JWJ       Corrected the error inject function name                                       EA4#16067
**********************************************************************************************************************/

/************************************************ Include Statements *************************************************/
#include "Std_Types.h"
#include "NxtrMath.h"
#include "NxtrMath_private.h"
#include "McuErrInj.h"



/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */



/********************************************* Component Level Variables *********************************************/
#define GlobalShared_START_SEC_VAR_CLEARED_32
#include "MemMap.h"

VAR(sint32, AUTOMATIC) NxtrMathErrNo_C;

#define GlobalShared_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"



/**************************************************** Constants ******************************************************/
#define NxtrMath_START_SEC_CONST_16
#include "NxtrMath_MemMap.h"

CONST(uint16, AUTOMATIC) NXTRMATH_SINCNVNCONTBL_ULS_U16[513] = {
	0u,    201u,  402u,  603u,  804u,  1005u, 1206u, 1407u, 1608u, 1809u, 2010u, 2211u, 2412u, 2613u, 2814u, 3015u,
	3216u, 3416u, 3617u, 3818u, 4019u, 4219u, 4420u, 4621u, 4821u, 5022u, 5222u, 5422u, 5623u, 5823u, 6023u, 6223u,
	6424u, 6624u, 6824u, 7024u, 7223u, 7423u, 7623u, 7823u, 8022u, 8222u, 8421u, 8620u, 8820u, 9019u, 9218u, 9417u,
	9616u, 9815u, 10014u,10212u,10411u,10609u,10808u,11006u,11204u,11402u,11600u,11798u,11996u,12193u,12391u,12588u,
	12785u,12982u,13179u,13376u,13573u,13770u,13966u,14163u,14359u,14555u,14751u,14947u,15142u,15338u,15533u,15729u,
	15924u,16119u,16313u,16508u,16703u,16897u,17091u,17285u,17479u,17673u,17866u,18060u,18253u,18446u,18639u,18831u,
	19024u,19216u,19408u,19600u,19792u,19984u,20175u,20366u,20557u,20748u,20939u,21129u,21319u,21509u,21699u,21889u,
	22078u,22267u,22456u,22645u,22834u,23022u,23210u,23398u,23586u,23773u,23960u,24147u,24334u,24521u,24707u,24893u,
	25079u,25265u,25450u,25635u,25820u,26005u,26189u,26374u,26557u,26741u,26925u,27108u,27291u,27473u,27656u,27838u,
	28020u,28201u,28383u,28564u,28745u,28925u,29106u,29286u,29465u,29645u,29824u,30003u,30181u,30360u,30538u,30716u,
	30893u,31070u,31247u,31424u,31600u,31776u,31952u,32127u,32302u,32477u,32651u,32826u,32999u,33173u,33346u,33519u,
	33692u,33864u,34036u,34208u,34379u,34550u,34721u,34891u,35061u,35231u,35400u,35569u,35738u,35906u,36074u,36242u,
	36409u,36576u,36743u,36909u,37075u,37241u,37406u,37571u,37736u,37900u,38064u,38227u,38390u,38553u,38715u,38877u,
	39039u,39200u,39361u,39522u,39682u,39842u,40001u,40161u,40319u,40478u,40635u,40793u,40950u,41107u,41263u,41419u,
	41575u,41730u,41885u,42039u,42194u,42347u,42500u,42653u,42806u,42958u,43109u,43261u,43411u,43562u,43712u,43861u,
	44011u,44159u,44308u,44456u,44603u,44750u,44897u,45043u,45189u,45334u,45479u,45624u,45768u,45912u,46055u,46198u,
	46340u,46482u,46624u,46765u,46905u,47046u,47185u,47325u,47464u,47602u,47740u,47877u,48014u,48151u,48287u,48423u,
	48558u,48693u,48827u,48961u,49095u,49228u,49360u,49492u,49624u,49755u,49885u,50016u,50145u,50274u,50403u,50531u,
	50659u,50787u,50913u,51040u,51166u,51291u,51416u,51540u,51664u,51788u,51911u,52033u,52155u,52277u,52398u,52518u,
	52638u,52758u,52877u,52995u,53113u,53231u,53348u,53464u,53580u,53696u,53811u,53925u,54039u,54153u,54266u,54378u,
	54490u,54602u,54713u,54823u,54933u,55042u,55151u,55260u,55367u,55475u,55582u,55688u,55794u,55899u,56003u,56108u,
	56211u,56314u,56417u,56519u,56620u,56721u,56822u,56922u,57021u,57120u,57218u,57316u,57413u,57510u,57606u,57702u,
	57797u,57891u,57985u,58079u,58171u,58264u,58356u,58447u,58537u,58628u,58717u,58806u,58895u,58983u,59070u,59157u,
	59243u,59329u,59414u,59498u,59582u,59666u,59749u,59831u,59913u,59994u,60075u,60155u,60234u,60313u,60391u,60469u,
	60546u,60623u,60699u,60775u,60850u,60924u,60998u,61071u,61144u,61216u,61287u,61358u,61429u,61498u,61567u,61636u,
	61704u,61772u,61838u,61905u,61970u,62035u,62100u,62164u,62227u,62290u,62352u,62414u,62475u,62535u,62595u,62654u,
	62713u,62771u,62829u,62886u,62942u,62998u,63053u,63107u,63161u,63214u,63267u,63319u,63371u,63422u,63472u,63522u,
	63571u,63620u,63668u,63715u,63762u,63808u,63853u,63898u,63943u,63986u,64030u,64072u,64114u,64155u,64196u,64236u,
	64276u,64315u,64353u,64391u,64428u,64464u,64500u,64535u,64570u,64604u,64638u,64671u,64703u,64734u,64765u,64796u,
	64826u,64855u,64883u,64911u,64939u,64966u,64992u,65017u,65042u,65066u,65090u,65113u,65136u,65158u,65179u,65199u,
	65219u,65239u,65258u,65276u,65293u,65310u,65327u,65342u,65357u,65372u,65386u,65399u,65412u,65424u,65435u,65446u,
	65456u,65466u,65475u,65483u,65491u,65498u,65504u,65510u,65515u,65520u,65524u,65527u,65530u,65532u,65534u,65535u,
	65535u
};

#define NxtrMath_STOP_SEC_CONST_16
#include "NxtrMath_MemMap.h"



/************************************************ Global Functions ***************************************************/
#define NxtrMath_START_SEC_CODE
#include "NxtrMath_MemMap.h"

/**********************************************************************************************************************
 * Name        :   __gh_set_errno
 * Description :   Nxtr variant of the ANSI C library error handling function.
 * Inputs      :   ErrNo:  Enumerated error number defined by ANSI C standard.
 * Outputs     :   None
 * Usage Notes :   The existence of this function overrides the default error handling function defined as part of the
 *                 standard library and allows the error code (which could be logged at any time, from any application)
 *                 to be stored into Global Shared memory.  The error code is later accessed by a periodic function in
 *                 this component to set an NTC.
 *********************************************************************************************************************/
FUNC(void, NxtrMath_CODE) __gh_set_errno(VAR(sint32, AUTOMATIC) ErrNo_Cnt_T_s32)
{
    NxtrMathErrNo_C = ErrNo_Cnt_T_s32;
}


#if (MCUDIAGCERRINJ == STD_ON)
/**********************************************************************************************************************
  * Name:        InjSwFpuErr
  * Description: Non-RTE function for injecting errors for software math library functions.
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: To be called on event from DF003
  ********************************************************************************************************************/
FUNC(void, NxtrMath_CODE) InjSwFpuErr(void)
{
	VAR(uint32, AUTOMATIC) ErrId_Cnt_T_u32;

	ReadErrInjReg_Oper(&ErrId_Cnt_T_u32);

	/* Software floating point library underflow */
	if (ErrId_Cnt_T_u32 == MCUERRINJ_NTC003ABIT22CASE01_CNT_U32)
	{
		/* This value (-125) was selected from past experiences with issues observer on SF009A that generated anomalies
		 * that eventually resulted in the creation of the diagnostic that this code is verifying.
		 */
		(void)Exp_f32(-125.0f);
	}
	else
	{
		/* Do Nothing */
	}

}
#endif /* MCUDIAGCERRINJ */


#define NxtrMath_STOP_SEC_CODE
#include "NxtrMath_MemMap.h"
