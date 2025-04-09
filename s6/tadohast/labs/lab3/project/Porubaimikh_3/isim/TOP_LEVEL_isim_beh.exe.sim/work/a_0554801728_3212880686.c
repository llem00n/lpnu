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
static const char *ng0 = "//VBoxSvr/windows_shared/school/lpnu/tadohast/labs/lab3/project/Porubaimikh_3/DD_Err.vhd";
extern char *IEEE_P_2592010699;

unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_0554801728_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;

LAB0:    xsi_set_current_line(21, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 1472U);
    t3 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t3 != 0)
        goto LAB5;

LAB6:
LAB3:    t1 = (t0 + 4040);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(22, ng0);
    t1 = (t0 + 7105);
    t6 = (t0 + 4136);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 3U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(23, ng0);
    t1 = (t0 + 7108);
    t5 = (t0 + 4200);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 3U);
    xsi_driver_first_trans_fast_port(t5);
    goto LAB3;

LAB5:    xsi_set_current_line(25, ng0);
    t2 = (t0 + 2152U);
    t5 = *((char **)t2);
    t2 = (t0 + 4136);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t5, 3U);
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(26, ng0);
    t1 = (t0 + 2152U);
    t2 = *((char **)t1);
    t1 = (t0 + 4200);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 3U);
    xsi_driver_first_trans_fast_port(t1);
    goto LAB3;

}

static void work_a_0554801728_3212880686_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int t7;
    int t8;
    char *t9;
    int t10;
    char *t11;
    char *t12;
    int t13;
    char *t14;
    int t16;
    char *t17;
    int t19;
    char *t20;
    int t22;
    char *t23;
    int t25;
    char *t26;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    unsigned char t33;
    unsigned char t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;

LAB0:    xsi_set_current_line(32, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 4264);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 2U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(33, ng0);
    t1 = (t0 + 4264);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_delta(t1, 1U, 1, 0LL);
    xsi_set_current_line(35, ng0);
    t1 = (t0 + 1992U);
    t2 = *((char **)t1);
    t1 = (t0 + 7111);
    t7 = xsi_mem_cmp(t1, t2, 3U);
    if (t7 == 1)
        goto LAB3;

LAB12:    t4 = (t0 + 7114);
    t8 = xsi_mem_cmp(t4, t2, 3U);
    if (t8 == 1)
        goto LAB4;

LAB13:    t6 = (t0 + 7117);
    t10 = xsi_mem_cmp(t6, t2, 3U);
    if (t10 == 1)
        goto LAB5;

LAB14:    t11 = (t0 + 7120);
    t13 = xsi_mem_cmp(t11, t2, 3U);
    if (t13 == 1)
        goto LAB6;

LAB15:    t14 = (t0 + 7123);
    t16 = xsi_mem_cmp(t14, t2, 3U);
    if (t16 == 1)
        goto LAB7;

LAB16:    t17 = (t0 + 7126);
    t19 = xsi_mem_cmp(t17, t2, 3U);
    if (t19 == 1)
        goto LAB8;

LAB17:    t20 = (t0 + 7129);
    t22 = xsi_mem_cmp(t20, t2, 3U);
    if (t22 == 1)
        goto LAB9;

LAB18:    t23 = (t0 + 7132);
    t25 = xsi_mem_cmp(t23, t2, 3U);
    if (t25 == 1)
        goto LAB10;

LAB19:
LAB11:    xsi_set_current_line(92, ng0);
    t1 = (t0 + 7193);
    t3 = (t0 + 4392);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t9 = *((char **)t6);
    memcpy(t9, t1, 3U);
    xsi_driver_first_trans_fast(t3);

LAB2:    t1 = (t0 + 4056);
    *((int *)t1) = 1;

LAB1:    return;
LAB3:    xsi_set_current_line(37, ng0);
    t26 = (t0 + 7135);
    t28 = (t0 + 4328);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    t31 = (t30 + 56U);
    t32 = *((char **)t31);
    memcpy(t32, t26, 2U);
    xsi_driver_first_trans_fast_port(t28);
    xsi_set_current_line(38, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t33 = *((unsigned char *)t2);
    t34 = (t33 == (unsigned char)2);
    if (t34 != 0)
        goto LAB21;

LAB23:    xsi_set_current_line(41, ng0);
    t1 = (t0 + 7140);
    t3 = (t0 + 4392);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t9 = *((char **)t6);
    memcpy(t9, t1, 3U);
    xsi_driver_first_trans_fast(t3);

LAB22:    goto LAB2;

LAB4:    xsi_set_current_line(45, ng0);
    t1 = (t0 + 7143);
    t3 = (t0 + 4328);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t9 = *((char **)t6);
    memcpy(t9, t1, 2U);
    xsi_driver_first_trans_fast_port(t3);
    xsi_set_current_line(46, ng0);
    t1 = (t0 + 2312U);
    t2 = *((char **)t1);
    t7 = (0 - 1);
    t35 = (t7 * -1);
    t36 = (1U * t35);
    t37 = (0 + t36);
    t1 = (t2 + t37);
    t33 = *((unsigned char *)t1);
    t34 = (t33 == (unsigned char)2);
    if (t34 != 0)
        goto LAB24;

LAB26:    xsi_set_current_line(49, ng0);
    t1 = (t0 + 7148);
    t3 = (t0 + 4392);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t9 = *((char **)t6);
    memcpy(t9, t1, 3U);
    xsi_driver_first_trans_fast(t3);

LAB25:    goto LAB2;

LAB5:    xsi_set_current_line(53, ng0);
    t1 = (t0 + 7151);
    t3 = (t0 + 4328);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t9 = *((char **)t6);
    memcpy(t9, t1, 2U);
    xsi_driver_first_trans_fast_port(t3);
    xsi_set_current_line(54, ng0);
    t1 = (t0 + 2312U);
    t2 = *((char **)t1);
    t7 = (0 - 1);
    t35 = (t7 * -1);
    t36 = (1U * t35);
    t37 = (0 + t36);
    t1 = (t2 + t37);
    t33 = *((unsigned char *)t1);
    t34 = (t33 == (unsigned char)2);
    if (t34 != 0)
        goto LAB27;

LAB29:    xsi_set_current_line(57, ng0);
    t1 = (t0 + 7156);
    t3 = (t0 + 4392);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t9 = *((char **)t6);
    memcpy(t9, t1, 3U);
    xsi_driver_first_trans_fast(t3);

LAB28:    goto LAB2;

LAB6:    xsi_set_current_line(61, ng0);
    t1 = (t0 + 7159);
    t3 = (t0 + 4328);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t9 = *((char **)t6);
    memcpy(t9, t1, 2U);
    xsi_driver_first_trans_fast_port(t3);
    xsi_set_current_line(62, ng0);
    t1 = (t0 + 2312U);
    t2 = *((char **)t1);
    t7 = (1 - 1);
    t35 = (t7 * -1);
    t36 = (1U * t35);
    t37 = (0 + t36);
    t1 = (t2 + t37);
    t33 = *((unsigned char *)t1);
    t34 = (t33 == (unsigned char)2);
    if (t34 != 0)
        goto LAB30;

LAB32:    xsi_set_current_line(65, ng0);
    t1 = (t0 + 7164);
    t3 = (t0 + 4392);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t9 = *((char **)t6);
    memcpy(t9, t1, 3U);
    xsi_driver_first_trans_fast(t3);

LAB31:    goto LAB2;

LAB7:    xsi_set_current_line(69, ng0);
    t1 = (t0 + 7167);
    t3 = (t0 + 4328);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t9 = *((char **)t6);
    memcpy(t9, t1, 2U);
    xsi_driver_first_trans_fast_port(t3);
    xsi_set_current_line(70, ng0);
    t1 = (t0 + 7169);
    t3 = (t0 + 4392);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t9 = *((char **)t6);
    memcpy(t9, t1, 3U);
    xsi_driver_first_trans_fast(t3);
    goto LAB2;

LAB8:    xsi_set_current_line(73, ng0);
    t1 = (t0 + 7172);
    t3 = (t0 + 4328);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t9 = *((char **)t6);
    memcpy(t9, t1, 2U);
    xsi_driver_first_trans_fast_port(t3);
    xsi_set_current_line(74, ng0);
    t1 = (t0 + 7174);
    t3 = (t0 + 4392);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t9 = *((char **)t6);
    memcpy(t9, t1, 3U);
    xsi_driver_first_trans_fast(t3);
    goto LAB2;

LAB9:    xsi_set_current_line(77, ng0);
    t1 = (t0 + 7177);
    t3 = (t0 + 4328);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t9 = *((char **)t6);
    memcpy(t9, t1, 2U);
    xsi_driver_first_trans_fast_port(t3);
    xsi_set_current_line(78, ng0);
    t1 = (t0 + 2312U);
    t2 = *((char **)t1);
    t7 = (1 - 1);
    t35 = (t7 * -1);
    t36 = (1U * t35);
    t37 = (0 + t36);
    t1 = (t2 + t37);
    t33 = *((unsigned char *)t1);
    t34 = (t33 == (unsigned char)2);
    if (t34 != 0)
        goto LAB33;

LAB35:    xsi_set_current_line(81, ng0);
    t1 = (t0 + 7182);
    t3 = (t0 + 4392);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t9 = *((char **)t6);
    memcpy(t9, t1, 3U);
    xsi_driver_first_trans_fast(t3);

LAB34:    goto LAB2;

LAB10:    xsi_set_current_line(85, ng0);
    t1 = (t0 + 7185);
    t3 = (t0 + 4328);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t9 = *((char **)t6);
    memcpy(t9, t1, 2U);
    xsi_driver_first_trans_fast_port(t3);
    xsi_set_current_line(86, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t33 = *((unsigned char *)t2);
    t34 = (t33 == (unsigned char)2);
    if (t34 != 0)
        goto LAB36;

LAB38:    xsi_set_current_line(89, ng0);
    t1 = (t0 + 7190);
    t3 = (t0 + 4392);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t9 = *((char **)t6);
    memcpy(t9, t1, 3U);
    xsi_driver_first_trans_fast(t3);

LAB37:    goto LAB2;

LAB20:;
LAB21:    xsi_set_current_line(39, ng0);
    t1 = (t0 + 7137);
    t4 = (t0 + 4392);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t9 = (t6 + 56U);
    t11 = *((char **)t9);
    memcpy(t11, t1, 3U);
    xsi_driver_first_trans_fast(t4);
    goto LAB22;

LAB24:    xsi_set_current_line(47, ng0);
    t3 = (t0 + 7145);
    t5 = (t0 + 4392);
    t6 = (t5 + 56U);
    t9 = *((char **)t6);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t3, 3U);
    xsi_driver_first_trans_fast(t5);
    goto LAB25;

LAB27:    xsi_set_current_line(55, ng0);
    t3 = (t0 + 7153);
    t5 = (t0 + 4392);
    t6 = (t5 + 56U);
    t9 = *((char **)t6);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t3, 3U);
    xsi_driver_first_trans_fast(t5);
    goto LAB28;

LAB30:    xsi_set_current_line(63, ng0);
    t3 = (t0 + 7161);
    t5 = (t0 + 4392);
    t6 = (t5 + 56U);
    t9 = *((char **)t6);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t3, 3U);
    xsi_driver_first_trans_fast(t5);
    goto LAB31;

LAB33:    xsi_set_current_line(79, ng0);
    t3 = (t0 + 7179);
    t5 = (t0 + 4392);
    t6 = (t5 + 56U);
    t9 = *((char **)t6);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t3, 3U);
    xsi_driver_first_trans_fast(t5);
    goto LAB34;

LAB36:    xsi_set_current_line(87, ng0);
    t1 = (t0 + 7187);
    t4 = (t0 + 4392);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t9 = (t6 + 56U);
    t11 = *((char **)t9);
    memcpy(t11, t1, 3U);
    xsi_driver_first_trans_fast(t4);
    goto LAB37;

}


extern void work_a_0554801728_3212880686_init()
{
	static char *pe[] = {(void *)work_a_0554801728_3212880686_p_0,(void *)work_a_0554801728_3212880686_p_1};
	xsi_register_didat("work_a_0554801728_3212880686", "isim/TOP_LEVEL_isim_beh.exe.sim/work/a_0554801728_3212880686.didat");
	xsi_register_executes(pe);
}
