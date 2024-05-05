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

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "//VBoxSvr/windows_shared/school/lpnu/tadohast/labs/lab2/project/Porubaimikh_Lab2/TEST_BENCH_ARCH_SIM.vhd";
extern char *IEEE_P_1242562249;

char *ieee_p_1242562249_sub_180853171_1035706684(char *, char *, int , int );


static void work_a_2578365841_3553469787_p_0(char *t0)
{
    char t14[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    int64 t9;
    int t10;
    unsigned char t11;
    int t12;
    int t13;
    int t15;
    char *t16;
    char *t17;
    int t18;
    int t19;

LAB0:    t1 = (t0 + 2992U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(11, ng0);
    t2 = xsi_get_transient_memory(16U);
    memset(t2, 0, 16U);
    t3 = t2;
    memset(t3, (unsigned char)2, 16U);
    t4 = (t0 + 3376);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 16U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(12, ng0);
    t2 = xsi_get_transient_memory(4U);
    memset(t2, 0, 4U);
    t3 = t2;
    memset(t3, (unsigned char)2, 4U);
    t4 = (t0 + 3440);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 4U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(13, ng0);
    t2 = (t0 + 3504);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(14, ng0);
    t2 = (t0 + 3568);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(15, ng0);
    t2 = (t0 + 3632);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(16, ng0);
    t9 = (10 * 1000LL);
    t2 = (t0 + 2800);
    xsi_process_wait(t2, t9);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(18, ng0);
    t2 = (t0 + 3632);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(20, ng0);
    t2 = (t0 + 1832U);
    t3 = *((char **)t2);
    t10 = *((int *)t3);
    t11 = (t10 == 0);
    if (t11 != 0)
        goto LAB8;

LAB10:    t2 = (t0 + 1832U);
    t3 = *((char **)t2);
    t10 = *((int *)t3);
    t11 = (t10 == 1);
    if (t11 != 0)
        goto LAB50;

LAB51:    t2 = (t0 + 1832U);
    t3 = *((char **)t2);
    t10 = *((int *)t3);
    t11 = (t10 == 2);
    if (t11 != 0)
        goto LAB96;

LAB97:
LAB9:    xsi_set_current_line(114, ng0);

LAB136:    *((char **)t1) = &&LAB137;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    xsi_set_current_line(21, ng0);
    t2 = (t0 + 3504);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(22, ng0);
    t2 = (t0 + 3568);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(23, ng0);
    t9 = (10 * 1000LL);
    t2 = (t0 + 2800);
    xsi_process_wait(t2, t9);

LAB13:    *((char **)t1) = &&LAB14;
    goto LAB1;

LAB11:    xsi_set_current_line(26, ng0);
    t10 = (16U - 1);
    t2 = (t0 + 6136);
    *((int *)t2) = 0;
    t3 = (t0 + 6140);
    *((int *)t3) = t10;
    t12 = 0;
    t13 = t10;

LAB15:    if (t12 <= t13)
        goto LAB16;

LAB18:    xsi_set_current_line(32, ng0);
    t9 = (10 * 1000LL);
    t2 = (t0 + 2800);
    xsi_process_wait(t2, t9);

LAB26:    *((char **)t1) = &&LAB27;
    goto LAB1;

LAB12:    goto LAB11;

LAB14:    goto LAB12;

LAB16:    xsi_set_current_line(27, ng0);
    t4 = (t0 + 6136);
    t15 = xsi_vhdl_pow(2, *((int *)t4));
    t5 = ieee_p_1242562249_sub_180853171_1035706684(IEEE_P_1242562249, t14, t15, 16);
    t6 = (t0 + 3376);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t16 = (t8 + 56U);
    t17 = *((char **)t16);
    memcpy(t17, t5, 16U);
    xsi_driver_first_trans_fast_port(t6);
    xsi_set_current_line(28, ng0);
    t2 = xsi_get_transient_memory(4U);
    memset(t2, 0, 4U);
    t3 = t2;
    memset(t3, (unsigned char)2, 4U);
    t4 = (t0 + 3440);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 4U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(29, ng0);
    t9 = (10 * 1000LL);
    t2 = (t0 + 2800);
    xsi_process_wait(t2, t9);

LAB21:    *((char **)t1) = &&LAB22;
    goto LAB1;

LAB17:    t2 = (t0 + 6136);
    t12 = *((int *)t2);
    t3 = (t0 + 6140);
    t13 = *((int *)t3);
    if (t12 == t13)
        goto LAB18;

LAB23:    t10 = (t12 + 1);
    t12 = t10;
    t4 = (t0 + 6136);
    *((int *)t4) = t12;
    goto LAB15;

LAB19:    goto LAB17;

LAB20:    goto LAB19;

LAB22:    goto LAB20;

LAB24:    xsi_set_current_line(34, ng0);
    t10 = (16U - 1);
    t2 = (t0 + 6144);
    *((int *)t2) = 0;
    t3 = (t0 + 6148);
    *((int *)t3) = t10;
    t12 = 0;
    t13 = t10;

LAB28:    if (t12 <= t13)
        goto LAB29;

LAB31:    goto LAB9;

LAB25:    goto LAB24;

LAB27:    goto LAB25;

LAB29:    xsi_set_current_line(35, ng0);
    t4 = (t0 + 6144);
    t15 = xsi_vhdl_pow(2, *((int *)t4));
    t5 = ieee_p_1242562249_sub_180853171_1035706684(IEEE_P_1242562249, t14, t15, 16);
    t6 = (t0 + 3376);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t16 = (t8 + 56U);
    t17 = *((char **)t16);
    memcpy(t17, t5, 16U);
    xsi_driver_first_trans_fast_port(t6);
    xsi_set_current_line(36, ng0);
    t2 = xsi_get_transient_memory(4U);
    memset(t2, 0, 4U);
    t3 = t2;
    memset(t3, (unsigned char)3, 4U);
    t4 = (t0 + 3440);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 4U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(37, ng0);
    t9 = (10 * 1000LL);
    t2 = (t0 + 2800);
    xsi_process_wait(t2, t9);

LAB34:    *((char **)t1) = &&LAB35;
    goto LAB1;

LAB30:    t2 = (t0 + 6144);
    t12 = *((int *)t2);
    t3 = (t0 + 6148);
    t13 = *((int *)t3);
    if (t12 == t13)
        goto LAB31;

LAB49:    t10 = (t12 + 1);
    t12 = t10;
    t4 = (t0 + 6144);
    *((int *)t4) = t12;
    goto LAB28;

LAB32:    xsi_set_current_line(39, ng0);
    t2 = (t0 + 3504);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(40, ng0);
    t2 = (t0 + 3568);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(42, ng0);
    t10 = (16U - 1);
    t2 = (t0 + 6152);
    *((int *)t2) = 0;
    t3 = (t0 + 6156);
    *((int *)t3) = t10;
    t15 = 0;
    t18 = t10;

LAB36:    if (t15 <= t18)
        goto LAB37;

LAB39:    xsi_set_current_line(47, ng0);
    t2 = (t0 + 3504);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(48, ng0);
    t2 = (t0 + 3568);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(49, ng0);
    t2 = (t0 + 6144);
    t10 = xsi_vhdl_pow(2, *((int *)t2));
    t3 = ieee_p_1242562249_sub_180853171_1035706684(IEEE_P_1242562249, t14, t10, 16);
    t4 = (t0 + 3376);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t3, 16U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(50, ng0);
    t2 = xsi_get_transient_memory(4U);
    memset(t2, 0, 4U);
    t3 = t2;
    memset(t3, (unsigned char)2, 4U);
    t4 = (t0 + 3440);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 4U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(51, ng0);
    t9 = (10 * 1000LL);
    t2 = (t0 + 2800);
    xsi_process_wait(t2, t9);

LAB47:    *((char **)t1) = &&LAB48;
    goto LAB1;

LAB33:    goto LAB32;

LAB35:    goto LAB33;

LAB37:    xsi_set_current_line(43, ng0);
    t4 = (t0 + 6152);
    t19 = xsi_vhdl_pow(2, *((int *)t4));
    t5 = ieee_p_1242562249_sub_180853171_1035706684(IEEE_P_1242562249, t14, t19, 16);
    t6 = (t0 + 3376);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t16 = (t8 + 56U);
    t17 = *((char **)t16);
    memcpy(t17, t5, 16U);
    xsi_driver_first_trans_fast_port(t6);
    xsi_set_current_line(44, ng0);
    t9 = (10 * 1000LL);
    t2 = (t0 + 2800);
    xsi_process_wait(t2, t9);

LAB42:    *((char **)t1) = &&LAB43;
    goto LAB1;

LAB38:    t2 = (t0 + 6152);
    t15 = *((int *)t2);
    t3 = (t0 + 6156);
    t18 = *((int *)t3);
    if (t15 == t18)
        goto LAB39;

LAB44:    t10 = (t15 + 1);
    t15 = t10;
    t4 = (t0 + 6152);
    *((int *)t4) = t15;
    goto LAB36;

LAB40:    goto LAB38;

LAB41:    goto LAB40;

LAB43:    goto LAB41;

LAB45:    goto LAB30;

LAB46:    goto LAB45;

LAB48:    goto LAB46;

LAB50:    xsi_set_current_line(55, ng0);
    t2 = (t0 + 6160);
    t5 = (t0 + 3376);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t16 = *((char **)t8);
    memcpy(t16, t2, 16U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(56, ng0);
    t2 = (t0 + 3504);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(57, ng0);
    t2 = (t0 + 3568);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(58, ng0);
    t2 = (t0 + 3632);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(59, ng0);
    t9 = (10 * 1000LL);
    t2 = (t0 + 2800);
    xsi_process_wait(t2, t9);

LAB54:    *((char **)t1) = &&LAB55;
    goto LAB1;

LAB52:    xsi_set_current_line(61, ng0);
    t2 = (t0 + 3504);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(63, ng0);
    t2 = (t0 + 6176);
    t4 = (t0 + 3440);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 4U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(63, ng0);
    t9 = (10 * 1000LL);
    t2 = (t0 + 2800);
    xsi_process_wait(t2, t9);

LAB58:    *((char **)t1) = &&LAB59;
    goto LAB1;

LAB53:    goto LAB52;

LAB55:    goto LAB53;

LAB56:    xsi_set_current_line(64, ng0);
    t2 = (t0 + 6180);
    t4 = (t0 + 3440);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 4U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(64, ng0);
    t9 = (10 * 1000LL);
    t2 = (t0 + 2800);
    xsi_process_wait(t2, t9);

LAB62:    *((char **)t1) = &&LAB63;
    goto LAB1;

LAB57:    goto LAB56;

LAB59:    goto LAB57;

LAB60:    xsi_set_current_line(65, ng0);
    t2 = (t0 + 6184);
    t4 = (t0 + 3440);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 4U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(65, ng0);
    t9 = (10 * 1000LL);
    t2 = (t0 + 2800);
    xsi_process_wait(t2, t9);

LAB66:    *((char **)t1) = &&LAB67;
    goto LAB1;

LAB61:    goto LAB60;

LAB63:    goto LAB61;

LAB64:    xsi_set_current_line(66, ng0);
    t2 = (t0 + 6188);
    t4 = (t0 + 3440);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 4U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(66, ng0);
    t9 = (10 * 1000LL);
    t2 = (t0 + 2800);
    xsi_process_wait(t2, t9);

LAB70:    *((char **)t1) = &&LAB71;
    goto LAB1;

LAB65:    goto LAB64;

LAB67:    goto LAB65;

LAB68:    xsi_set_current_line(67, ng0);
    t2 = (t0 + 6192);
    t4 = (t0 + 3440);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 4U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(67, ng0);
    t9 = (10 * 1000LL);
    t2 = (t0 + 2800);
    xsi_process_wait(t2, t9);

LAB74:    *((char **)t1) = &&LAB75;
    goto LAB1;

LAB69:    goto LAB68;

LAB71:    goto LAB69;

LAB72:    xsi_set_current_line(69, ng0);
    t2 = (t0 + 6196);
    t4 = (t0 + 3440);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 4U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(69, ng0);
    t9 = (10 * 1000LL);
    t2 = (t0 + 2800);
    xsi_process_wait(t2, t9);

LAB78:    *((char **)t1) = &&LAB79;
    goto LAB1;

LAB73:    goto LAB72;

LAB75:    goto LAB73;

LAB76:    xsi_set_current_line(70, ng0);
    t2 = (t0 + 6200);
    t4 = (t0 + 3440);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 4U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(70, ng0);
    t9 = (10 * 1000LL);
    t2 = (t0 + 2800);
    xsi_process_wait(t2, t9);

LAB82:    *((char **)t1) = &&LAB83;
    goto LAB1;

LAB77:    goto LAB76;

LAB79:    goto LAB77;

LAB80:    xsi_set_current_line(71, ng0);
    t2 = (t0 + 6204);
    t4 = (t0 + 3440);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 4U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(71, ng0);
    t9 = (10 * 1000LL);
    t2 = (t0 + 2800);
    xsi_process_wait(t2, t9);

LAB86:    *((char **)t1) = &&LAB87;
    goto LAB1;

LAB81:    goto LAB80;

LAB83:    goto LAB81;

LAB84:    xsi_set_current_line(72, ng0);
    t2 = (t0 + 6208);
    t4 = (t0 + 3440);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 4U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(72, ng0);
    t9 = (10 * 1000LL);
    t2 = (t0 + 2800);
    xsi_process_wait(t2, t9);

LAB90:    *((char **)t1) = &&LAB91;
    goto LAB1;

LAB85:    goto LAB84;

LAB87:    goto LAB85;

LAB88:    xsi_set_current_line(73, ng0);
    t2 = (t0 + 6212);
    t4 = (t0 + 3440);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 4U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(73, ng0);
    t9 = (10 * 1000LL);
    t2 = (t0 + 2800);
    xsi_process_wait(t2, t9);

LAB94:    *((char **)t1) = &&LAB95;
    goto LAB1;

LAB89:    goto LAB88;

LAB91:    goto LAB89;

LAB92:    goto LAB9;

LAB93:    goto LAB92;

LAB95:    goto LAB93;

LAB96:    xsi_set_current_line(78, ng0);
    t2 = (t0 + 3504);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(79, ng0);
    t2 = (t0 + 3568);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(81, ng0);
    t2 = (t0 + 6216);
    *((int *)t2) = 0;
    t3 = (t0 + 6220);
    *((int *)t3) = 65535;
    t10 = 0;
    t12 = 65535;

LAB98:    if (t10 <= t12)
        goto LAB99;

LAB101:    xsi_set_current_line(87, ng0);
    t2 = (t0 + 3568);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(88, ng0);
    t2 = (t0 + 3504);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(90, ng0);
    t2 = (t0 + 6224);
    *((int *)t2) = 0;
    t3 = (t0 + 6228);
    *((int *)t3) = 65535;
    t10 = 0;
    t12 = 65535;

LAB107:    if (t10 <= t12)
        goto LAB108;

LAB110:    xsi_set_current_line(96, ng0);
    t2 = (t0 + 3568);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(97, ng0);
    t2 = (t0 + 3504);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(99, ng0);
    t2 = (t0 + 6232);
    *((int *)t2) = 0;
    t3 = (t0 + 6236);
    *((int *)t3) = 65535;
    t10 = 0;
    t12 = 65535;

LAB116:    if (t10 <= t12)
        goto LAB117;

LAB119:    xsi_set_current_line(105, ng0);
    t2 = (t0 + 3568);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(106, ng0);
    t2 = (t0 + 3504);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(108, ng0);
    t2 = (t0 + 6240);
    *((int *)t2) = 0;
    t3 = (t0 + 6244);
    *((int *)t3) = 65535;
    t10 = 0;
    t12 = 65535;

LAB125:    if (t10 <= t12)
        goto LAB126;

LAB128:    goto LAB9;

LAB99:    xsi_set_current_line(82, ng0);
    t4 = (t0 + 6216);
    t5 = ieee_p_1242562249_sub_180853171_1035706684(IEEE_P_1242562249, t14, *((int *)t4), 16);
    t6 = (t0 + 3376);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t16 = (t8 + 56U);
    t17 = *((char **)t16);
    memcpy(t17, t5, 16U);
    xsi_driver_first_trans_fast_port(t6);
    xsi_set_current_line(83, ng0);
    t2 = xsi_get_transient_memory(4U);
    memset(t2, 0, 4U);
    t3 = t2;
    memset(t3, (unsigned char)2, 4U);
    t4 = (t0 + 3440);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 4U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(84, ng0);
    t9 = (10 * 1000LL);
    t2 = (t0 + 2800);
    xsi_process_wait(t2, t9);

LAB104:    *((char **)t1) = &&LAB105;
    goto LAB1;

LAB100:    t2 = (t0 + 6216);
    t10 = *((int *)t2);
    t3 = (t0 + 6220);
    t12 = *((int *)t3);
    if (t10 == t12)
        goto LAB101;

LAB106:    t13 = (t10 + 1);
    t10 = t13;
    t4 = (t0 + 6216);
    *((int *)t4) = t10;
    goto LAB98;

LAB102:    goto LAB100;

LAB103:    goto LAB102;

LAB105:    goto LAB103;

LAB108:    xsi_set_current_line(91, ng0);
    t4 = (t0 + 6224);
    t5 = ieee_p_1242562249_sub_180853171_1035706684(IEEE_P_1242562249, t14, *((int *)t4), 16);
    t6 = (t0 + 3376);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t16 = (t8 + 56U);
    t17 = *((char **)t16);
    memcpy(t17, t5, 16U);
    xsi_driver_first_trans_fast_port(t6);
    xsi_set_current_line(92, ng0);
    t9 = (10 * 1000LL);
    t2 = (t0 + 2800);
    xsi_process_wait(t2, t9);

LAB113:    *((char **)t1) = &&LAB114;
    goto LAB1;

LAB109:    t2 = (t0 + 6224);
    t10 = *((int *)t2);
    t3 = (t0 + 6228);
    t12 = *((int *)t3);
    if (t10 == t12)
        goto LAB110;

LAB115:    t13 = (t10 + 1);
    t10 = t13;
    t4 = (t0 + 6224);
    *((int *)t4) = t10;
    goto LAB107;

LAB111:    goto LAB109;

LAB112:    goto LAB111;

LAB114:    goto LAB112;

LAB117:    xsi_set_current_line(100, ng0);
    t4 = (t0 + 6232);
    t5 = ieee_p_1242562249_sub_180853171_1035706684(IEEE_P_1242562249, t14, *((int *)t4), 16);
    t6 = (t0 + 3376);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t16 = (t8 + 56U);
    t17 = *((char **)t16);
    memcpy(t17, t5, 16U);
    xsi_driver_first_trans_fast_port(t6);
    xsi_set_current_line(101, ng0);
    t2 = xsi_get_transient_memory(4U);
    memset(t2, 0, 4U);
    t3 = t2;
    memset(t3, (unsigned char)3, 4U);
    t4 = (t0 + 3440);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 4U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(102, ng0);
    t9 = (10 * 1000LL);
    t2 = (t0 + 2800);
    xsi_process_wait(t2, t9);

LAB122:    *((char **)t1) = &&LAB123;
    goto LAB1;

LAB118:    t2 = (t0 + 6232);
    t10 = *((int *)t2);
    t3 = (t0 + 6236);
    t12 = *((int *)t3);
    if (t10 == t12)
        goto LAB119;

LAB124:    t13 = (t10 + 1);
    t10 = t13;
    t4 = (t0 + 6232);
    *((int *)t4) = t10;
    goto LAB116;

LAB120:    goto LAB118;

LAB121:    goto LAB120;

LAB123:    goto LAB121;

LAB126:    xsi_set_current_line(109, ng0);
    t4 = (t0 + 6240);
    t5 = ieee_p_1242562249_sub_180853171_1035706684(IEEE_P_1242562249, t14, *((int *)t4), 16);
    t6 = (t0 + 3376);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t16 = (t8 + 56U);
    t17 = *((char **)t16);
    memcpy(t17, t5, 16U);
    xsi_driver_first_trans_fast_port(t6);
    xsi_set_current_line(110, ng0);
    t9 = (10 * 1000LL);
    t2 = (t0 + 2800);
    xsi_process_wait(t2, t9);

LAB131:    *((char **)t1) = &&LAB132;
    goto LAB1;

LAB127:    t2 = (t0 + 6240);
    t10 = *((int *)t2);
    t3 = (t0 + 6244);
    t12 = *((int *)t3);
    if (t10 == t12)
        goto LAB128;

LAB133:    t13 = (t10 + 1);
    t10 = t13;
    t4 = (t0 + 6240);
    *((int *)t4) = t10;
    goto LAB125;

LAB129:    goto LAB127;

LAB130:    goto LAB129;

LAB132:    goto LAB130;

LAB134:    goto LAB2;

LAB135:    goto LAB134;

LAB137:    goto LAB135;

}


extern void work_a_2578365841_3553469787_init()
{
	static char *pe[] = {(void *)work_a_2578365841_3553469787_p_0};
	xsi_register_didat("work_a_2578365841_3553469787", "isim/TEST_BENCH_isim_beh.exe.sim/work/a_2578365841_3553469787.didat");
	xsi_register_executes(pe);
}
