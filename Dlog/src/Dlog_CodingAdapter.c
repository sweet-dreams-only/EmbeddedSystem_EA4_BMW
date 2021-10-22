/**
 * \file
 *
 * \brief       Dlog Coding adapter.
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2015 - 2017
 *
 * \version     5.3.1
 *
 */

#include "Dlog_CodingAdapter.h"
#include "DlogClassic_Cfg.h"

#if DLOG_USE_CODING == STD_ON
#include "Rte_Dlog.h"
#endif

void Dlog_Coding_GetCafIds(uint8* data, uint16* numberOfCafIds) {
#if DLOG_USE_CODING == STD_ON
  if (E_OK != Rte_Call_Coding_Svk_GetCafIds(data, numberOfCafIds)) {
    *numberOfCafIds = 0;
  }
#else
  (void)data;
  *numberOfCafIds = 0;
#endif
}
