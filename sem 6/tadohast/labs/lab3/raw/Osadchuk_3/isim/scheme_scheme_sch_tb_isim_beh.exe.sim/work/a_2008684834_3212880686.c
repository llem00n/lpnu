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
static const char *ng0 = "/media/sf_TDPZ/Osadchuk_3/DA_B.vhd";
extern char *IEEE_P_2592010699;

unsigned char ieee_p_2592010699_sub_2763492388968962707_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_2008684834_3212880686_p_0(char *t0)
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

LAB0:    xsi_set_current_line(23, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 1632U);
    t3 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t3 != 0)
        goto LAB5;

LAB6:
LAB3:    t1 = (t0 + 4312);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(24, ng0);
    t1 = (t0 + 6751);
    t6 = (t0 + 4408);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 3U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(25, ng0);
    t1 = (t0 + 6754);
    t5 = (t0 + 4472);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 3U);
    xsi_driver_first_trans_fast_port(t5);
    goto LAB3;

LAB5:    xsi_set_current_line(27, ng0);
    t2 = (t0 + 2312U);
    t5 = *((char **)t2);
    t2 = (t0 + 4408);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t5, 3U);
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(28, ng0);
    t1 = (t0 + 2312U);
    t2 = *((char **)t1);
    t1 = (t0 + 4472);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 3U);
    xsi_driver_first_trans_fast_port(t1);
    goto LAB3;

}

static void work_a_2008684834_3212880686_p_1(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    int t8;
    int t9;
    char *t10;
    int t11;
    char *t12;
    int t14;
    char *t15;
    int t17;
    char *t18;
    int t20;
    char *t21;
    int t23;
    char *t24;
    int t26;
    char *t27;
    char *t28;
    unsigned char t29;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;

LAB0:    xsi_set_current_line(35, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 4536);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(36, ng0);
    t1 = (t0 + 4536);
    t2 = (t1 + 56U);
    t4 = *((char **)t2);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(37, ng0);
    t1 = (t0 + 2152U);
    t2 = *((char **)t1);
    t1 = (t0 + 6757);
    t8 = xsi_mem_cmp(t1, t2, 3U);
    if (t8 == 1)
        goto LAB3;

LAB12:    t5 = (t0 + 6760);
    t9 = xsi_mem_cmp(t5, t2, 3U);
    if (t9 == 1)
        goto LAB4;

LAB13:    t7 = (t0 + 6763);
    t11 = xsi_mem_cmp(t7, t2, 3U);
    if (t11 == 1)
        goto LAB5;

LAB14:    t12 = (t0 + 6766);
    t14 = xsi_mem_cmp(t12, t2, 3U);
    if (t14 == 1)
        goto LAB6;

LAB15:    t15 = (t0 + 6769);
    t17 = xsi_mem_cmp(t15, t2, 3U);
    if (t17 == 1)
        goto LAB7;

LAB16:    t18 = (t0 + 6772);
    t20 = xsi_mem_cmp(t18, t2, 3U);
    if (t20 == 1)
        goto LAB8;

LAB17:    t21 = (t0 + 6775);
    t23 = xsi_mem_cmp(t21, t2, 3U);
    if (t23 == 1)
        goto LAB9;

LAB18:    t24 = (t0 + 6778);
    t26 = xsi_mem_cmp(t24, t2, 3U);
    if (t26 == 1)
        goto LAB10;

LAB19:
LAB11:    xsi_set_current_line(99, ng0);
    t1 = (t0 + 6851);
    t4 = (t0 + 4600);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t10 = *((char **)t7);
    memcpy(t10, t1, 3U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(100, ng0);
    t1 = (t0 + 6854);
    t4 = (t0 + 4664);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t10 = *((char **)t7);
    memcpy(t10, t1, 2U);
    xsi_driver_first_trans_fast_port(t4);

LAB2:    t1 = (t0 + 4328);
    *((int *)t1) = 1;

LAB1:    return;
LAB3:    xsi_set_current_line(40, ng0);
    t27 = (t0 + 1192U);
    t28 = *((char **)t27);
    t3 = *((unsigned char *)t28);
    t29 = (t3 == (unsigned char)2);
    if (t29 != 0)
        goto LAB21;

LAB23:    xsi_set_current_line(44, ng0);
    t1 = (t0 + 6786);
    t4 = (t0 + 4600);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t10 = *((char **)t7);
    memcpy(t10, t1, 3U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(45, ng0);
    t1 = (t0 + 6789);
    t4 = (t0 + 4664);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t10 = *((char **)t7);
    memcpy(t10, t1, 2U);
    xsi_driver_first_trans_fast_port(t4);

LAB22:    goto LAB2;

LAB4:    xsi_set_current_line(50, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t29 = (t3 == (unsigned char)2);
    if (t29 != 0)
        goto LAB24;

LAB26:    xsi_set_current_line(54, ng0);
    t1 = (t0 + 6796);
    t4 = (t0 + 4600);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t10 = *((char **)t7);
    memcpy(t10, t1, 3U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(55, ng0);
    t1 = (t0 + 6799);
    t4 = (t0 + 4664);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t10 = *((char **)t7);
    memcpy(t10, t1, 2U);
    xsi_driver_first_trans_fast_port(t4);

LAB25:    goto LAB2;

LAB5:    xsi_set_current_line(59, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t29 = (t3 == (unsigned char)2);
    if (t29 != 0)
        goto LAB27;

LAB29:    xsi_set_current_line(63, ng0);
    t1 = (t0 + 6806);
    t4 = (t0 + 4600);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t10 = *((char **)t7);
    memcpy(t10, t1, 3U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(64, ng0);
    t1 = (t0 + 6809);
    t4 = (t0 + 4664);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t10 = *((char **)t7);
    memcpy(t10, t1, 2U);
    xsi_driver_first_trans_fast_port(t4);

LAB28:    goto LAB2;

LAB6:    xsi_set_current_line(68, ng0);
    t1 = (t0 + 2472U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t29 = (t3 == (unsigned char)2);
    if (t29 != 0)
        goto LAB30;

LAB32:    xsi_set_current_line(72, ng0);
    t1 = (t0 + 6816);
    t4 = (t0 + 4600);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t10 = *((char **)t7);
    memcpy(t10, t1, 3U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(73, ng0);
    t1 = (t0 + 6819);
    t4 = (t0 + 4664);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t10 = *((char **)t7);
    memcpy(t10, t1, 2U);
    xsi_driver_first_trans_fast_port(t4);

LAB31:    goto LAB2;

LAB7:    xsi_set_current_line(76, ng0);
    t1 = (t0 + 6821);
    t4 = (t0 + 4600);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t10 = *((char **)t7);
    memcpy(t10, t1, 3U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(77, ng0);
    t1 = (t0 + 6824);
    t4 = (t0 + 4664);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t10 = *((char **)t7);
    memcpy(t10, t1, 2U);
    xsi_driver_first_trans_fast_port(t4);
    goto LAB2;

LAB8:    xsi_set_current_line(80, ng0);
    t1 = (t0 + 6826);
    t4 = (t0 + 4600);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t10 = *((char **)t7);
    memcpy(t10, t1, 3U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(81, ng0);
    t1 = (t0 + 6829);
    t4 = (t0 + 4664);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t10 = *((char **)t7);
    memcpy(t10, t1, 2U);
    xsi_driver_first_trans_fast_port(t4);
    goto LAB2;

LAB9:    xsi_set_current_line(83, ng0);
    t1 = (t0 + 2472U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t29 = (t3 == (unsigned char)2);
    if (t29 != 0)
        goto LAB33;

LAB35:    xsi_set_current_line(87, ng0);
    t1 = (t0 + 6836);
    t4 = (t0 + 4600);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t10 = *((char **)t7);
    memcpy(t10, t1, 3U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(88, ng0);
    t1 = (t0 + 6839);
    t4 = (t0 + 4664);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t10 = *((char **)t7);
    memcpy(t10, t1, 2U);
    xsi_driver_first_trans_fast_port(t4);

LAB34:    goto LAB2;

LAB10:    xsi_set_current_line(91, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t29 = (t3 == (unsigned char)2);
    if (t29 != 0)
        goto LAB36;

LAB38:    xsi_set_current_line(95, ng0);
    t1 = (t0 + 6846);
    t4 = (t0 + 4600);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t10 = *((char **)t7);
    memcpy(t10, t1, 3U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(96, ng0);
    t1 = (t0 + 6849);
    t4 = (t0 + 4664);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t10 = *((char **)t7);
    memcpy(t10, t1, 2U);
    xsi_driver_first_trans_fast_port(t4);

LAB37:    goto LAB2;

LAB20:;
LAB21:    xsi_set_current_line(41, ng0);
    t27 = (t0 + 6781);
    t31 = (t0 + 4600);
    t32 = (t31 + 56U);
    t33 = *((char **)t32);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    memcpy(t35, t27, 3U);
    xsi_driver_first_trans_fast(t31);
    xsi_set_current_line(42, ng0);
    t1 = (t0 + 6784);
    t4 = (t0 + 4664);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t10 = *((char **)t7);
    memcpy(t10, t1, 2U);
    xsi_driver_first_trans_fast_port(t4);
    goto LAB22;

LAB24:    xsi_set_current_line(51, ng0);
    t1 = (t0 + 6791);
    t5 = (t0 + 4600);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t10 = (t7 + 56U);
    t12 = *((char **)t10);
    memcpy(t12, t1, 3U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(52, ng0);
    t1 = (t0 + 6794);
    t4 = (t0 + 4664);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t10 = *((char **)t7);
    memcpy(t10, t1, 2U);
    xsi_driver_first_trans_fast_port(t4);
    goto LAB25;

LAB27:    xsi_set_current_line(60, ng0);
    t1 = (t0 + 6801);
    t5 = (t0 + 4600);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t10 = (t7 + 56U);
    t12 = *((char **)t10);
    memcpy(t12, t1, 3U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(61, ng0);
    t1 = (t0 + 6804);
    t4 = (t0 + 4664);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t10 = *((char **)t7);
    memcpy(t10, t1, 2U);
    xsi_driver_first_trans_fast_port(t4);
    goto LAB28;

LAB30:    xsi_set_current_line(69, ng0);
    t1 = (t0 + 6811);
    t5 = (t0 + 4600);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t10 = (t7 + 56U);
    t12 = *((char **)t10);
    memcpy(t12, t1, 3U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(70, ng0);
    t1 = (t0 + 6814);
    t4 = (t0 + 4664);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t10 = *((char **)t7);
    memcpy(t10, t1, 2U);
    xsi_driver_first_trans_fast_port(t4);
    goto LAB31;

LAB33:    xsi_set_current_line(84, ng0);
    t1 = (t0 + 6831);
    t5 = (t0 + 4600);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t10 = (t7 + 56U);
    t12 = *((char **)t10);
    memcpy(t12, t1, 3U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(85, ng0);
    t1 = (t0 + 6834);
    t4 = (t0 + 4664);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t10 = *((char **)t7);
    memcpy(t10, t1, 2U);
    xsi_driver_first_trans_fast_port(t4);
    goto LAB34;

LAB36:    xsi_set_current_line(92, ng0);
    t1 = (t0 + 6841);
    t5 = (t0 + 4600);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t10 = (t7 + 56U);
    t12 = *((char **)t10);
    memcpy(t12, t1, 3U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(93, ng0);
    t1 = (t0 + 6844);
    t4 = (t0 + 4664);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t10 = *((char **)t7);
    memcpy(t10, t1, 2U);
    xsi_driver_first_trans_fast_port(t4);
    goto LAB37;

}


extern void work_a_2008684834_3212880686_init()
{
	static char *pe[] = {(void *)work_a_2008684834_3212880686_p_0,(void *)work_a_2008684834_3212880686_p_1};
	xsi_register_didat("work_a_2008684834_3212880686", "isim/scheme_scheme_sch_tb_isim_beh.exe.sim/work/a_2008684834_3212880686.didat");
	xsi_register_executes(pe);
}
