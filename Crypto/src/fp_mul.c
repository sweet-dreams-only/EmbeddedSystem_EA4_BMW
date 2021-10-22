/**
*  \file
*
*  \brief       BMW Crypto Library
*
*  This file contains a mathematical function for the BMW Crypto Library
*  It is based on the WTFPL library TomFastMath but has been changed for BMW purposes.
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*/

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "Crypto_Math_Intern.h"
#include "Crypto_Version.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Crypto_CHECK_VERSION(5,2,0))
#error "Version of fp_mul.c does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Crypto_START_SEC_CODE
#include "Crypto_MemMap.h"


/* c = a * b */
void fp_mul(fp_int *A, fp_int *B, fp_int *C)
{
    sint32   y, old_used;
#if FP_SIZE >= 48
    sint32   yy;
#endif

    old_used = C->used;

    /* call generic if we're out of range */
    if (A->used + B->used > FP_SIZE) {
       fp_mul_comba(A, B, C);
       goto clean;
    }

     y  = MAX(A->used, B->used);
#if FP_SIZE >= 48
     yy = MIN(A->used, B->used);
#endif
    /* pick a comba (unrolled 4/8/16/32 x or rolled) based on the size
       of the largest input.  We also want to avoid doing excess mults if the
       inputs are not close to the next power of two.  That is, for example,
       if say y=17 then we would do (32-17)^2 = 225 unneeded multiplications
    */

#if defined(TFM_MUL3) && FP_SIZE >= 6
        if (y <= 3) {
           fp_mul_comba3(A,B,C);
           goto clean;
        }
#endif
#if defined(TFM_MUL4) && FP_SIZE >= 8
        if (y == 4) {
           fp_mul_comba4(A,B,C);
           goto clean;
        }
#endif
#if defined(TFM_MUL6) && FP_SIZE >= 12
        if (y <= 6) {
           fp_mul_comba6(A,B,C);
           goto clean;
        }
#endif
#if defined(TFM_MUL7) && FP_SIZE >= 14
        if (y == 7) {
           fp_mul_comba7(A,B,C);
           goto clean;
        }
#endif
#if defined(TFM_MUL8) && FP_SIZE >= 16
        if (y == 8) {
           fp_mul_comba8(A,B,C);
           goto clean;
        }
#endif
#if defined(TFM_MUL9) && FP_SIZE >= 18
        if (y == 9) {
           fp_mul_comba9(A,B,C);
           goto clean;
        }
#endif
#if defined(TFM_MUL12) && FP_SIZE >= 24
        if (y <= 12) {
           fp_mul_comba12(A,B,C);
           goto clean;
        }
#endif
#if defined(TFM_MUL17) && FP_SIZE >= 34
        if (y <= 17) {
           fp_mul_comba17(A,B,C);
           goto clean;
        }
#endif

#if defined(TFM_SMALL_SET) && FP_SIZE >= 32
        if (y <= 16) {
           fp_mul_comba_small(A,B,C);
           goto clean;
        }
#endif
#if defined(TFM_MUL20) && FP_SIZE >= 40
        if (y <= 20) {
           fp_mul_comba20(A,B,C);
           goto clean;
        }
#endif
#if defined(TFM_MUL24) && FP_SIZE >= 48
        if (yy >= 16 && y <= 24) {
           fp_mul_comba24(A,B,C);
           goto clean;
        }
#endif
#if defined(TFM_MUL28) && FP_SIZE >= 56
        if (yy >= 20 && y <= 28) {
           fp_mul_comba28(A,B,C);
           goto clean;
        }
#endif
#if defined(TFM_MUL32) && FP_SIZE >= 64
        if (yy >= 24 && y <= 32) {
           fp_mul_comba32(A,B,C);
           goto clean;
        }
#endif
#if defined(TFM_MUL48) && FP_SIZE >= 96
        if (yy >= 40 && y <= 48) {
           fp_mul_comba48(A,B,C);
           goto clean;
        }
#endif
#if defined(TFM_MUL64) && FP_SIZE >= 128
        if (yy >= 56 && y <= 64) {
           fp_mul_comba64(A,B,C);
           goto clean;
        }
#endif
        fp_mul_comba(A,B,C);
clean:
    for (y = C->used; y < old_used; y++) {
       C->dp[y] = 0;
    }
}


#define Crypto_STOP_SEC_CODE
#include "Crypto_MemMap.h"