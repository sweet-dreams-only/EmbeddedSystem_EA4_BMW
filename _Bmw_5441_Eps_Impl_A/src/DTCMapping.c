#include "DTCMapping.h"

Std_ReturnType SetSecondaryDTC21F100_Oper ( Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew )
{
    VAR(Dem_EventStatusType, AUTOMATIC) EveSts_Cnt_T_enum = DEM_EVENT_STATUS_PASSED;
    if( (EventStatusNew & DEM_UDS_STATUS_TF) > 0U )
    {
        EveSts_Cnt_T_enum = DEM_EVENT_STATUS_FAILED;
    }
    return Dem_SetEventStatus(DemConf_DemEventParameter_SecondaryEve_21F100, EveSts_Cnt_T_enum);
}

Std_ReturnType SetSecondaryDTC21F300_Oper ( Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew )
{
    VAR(Dem_EventStatusType, AUTOMATIC) EveSts_Cnt_T_enum = DEM_EVENT_STATUS_PASSED;
    if( (EventStatusNew & DEM_UDS_STATUS_TF) > 0U )
    {
        EveSts_Cnt_T_enum = DEM_EVENT_STATUS_FAILED;
    }
    return Dem_SetEventStatus(DemConf_DemEventParameter_SecondaryEve_21F300, EveSts_Cnt_T_enum);
}

Std_ReturnType SetSecondaryDTC31F100_Oper ( Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew )
{
    VAR(Dem_EventStatusType, AUTOMATIC) EveSts_Cnt_T_enum = DEM_EVENT_STATUS_PASSED;
    if( (EventStatusNew & DEM_UDS_STATUS_TF) > 0U )
    {
        EveSts_Cnt_T_enum = DEM_EVENT_STATUS_FAILED;
    }
    return Dem_SetEventStatus(DemConf_DemEventParameter_SecondaryEve_31F100, EveSts_Cnt_T_enum);
}

Std_ReturnType SetSecondaryDTC31F300_Oper ( Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew )
{
    VAR(Dem_EventStatusType, AUTOMATIC) EveSts_Cnt_T_enum = DEM_EVENT_STATUS_PASSED;
    if( (EventStatusNew & DEM_UDS_STATUS_TF) > 0U )
    {
        EveSts_Cnt_T_enum = DEM_EVENT_STATUS_FAILED;
    }
    return Dem_SetEventStatus(DemConf_DemEventParameter_SecondaryEve_31F300, EveSts_Cnt_T_enum);
}