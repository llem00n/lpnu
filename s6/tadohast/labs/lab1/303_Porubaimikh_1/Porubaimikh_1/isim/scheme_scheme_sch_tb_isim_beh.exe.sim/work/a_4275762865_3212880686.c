/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xfbc00daa */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/media/sf_TDPZ/Porubaimikh_1/ALU_B.vhd";
extern char *IEEE_P_1242562249;

char *ieee_p_1242562249_sub_17249857350030274602_1035706684(char *, char *, char *, char *, int );


static void work_a_4275762865_3212880686_p_0(char *t0)
{
    char t1[16];
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned char t14;

LAB0:    xsi_set_current_line(16, ng0);
    t2 = (t0 + 1032U);
    t3 = *((char **)t2);
    t2 = (t0 + 4448U);
    t4 = ieee_p_1242562249_sub_17249857350030274602_1035706684(IEEE_P_1242562249, t1, t3, t2, 1);
    t5 = (t0 + 2904);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t4, 4U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(17, ng0);
    t2 = (t0 + 1352U);
    t3 = *((char **)t2);
    t10 = (1 - 3);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t2 = (t3 + t13);
    t14 = *((unsigned char *)t2);
    t4 = (t0 + 2904);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = t14;
    xsi_driver_first_trans_delta(t4, 3U, 1, 0LL);
    xsi_set_current_line(18, ng0);
    t2 = (t0 + 1352U);
    t3 = *((char **)t2);
    t2 = (t0 + 2968);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memcpy(t7, t3, 4U);
    xsi_driver_first_trans_fast_port(t2);
    t2 = (t0 + 2824);
    *((int *)t2) = 1;

LAB1:    return;
}


extern void work_a_4275762865_3212880686_init()
{
	static char *pe[] = {(void *)work_a_4275762865_3212880686_p_0};
	xsi_register_didat("work_a_4275762865_3212880686", "isim/scheme_scheme_sch_tb_isim_beh.exe.sim/work/a_4275762865_3212880686.didat");
	xsi_register_executes(pe);
}
