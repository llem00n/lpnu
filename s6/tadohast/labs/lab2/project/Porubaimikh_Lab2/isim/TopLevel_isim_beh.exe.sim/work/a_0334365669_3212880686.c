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
static const char *ng0 = "//VBoxSvr/windows_shared/school/lpnu/tadohast/labs/lab2/project/Porubaimikh_Lab2/RAM_Err.vhd";
extern char *IEEE_P_1242562249;
extern char *IEEE_P_3972351953;

int ieee_p_1242562249_sub_1657552908_1035706684(char *, char *, char *);
void ieee_p_3972351953_sub_3007962107_2984157535(char *, char *, char *, char *, char *);


static void work_a_0334365669_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    char *t8;
    char *t9;
    int t10;
    int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    double t20;

LAB0:    xsi_set_current_line(27, ng0);
    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)2);
    if (t4 != 0)
        goto LAB2;

LAB4:    xsi_set_current_line(45, ng0);
    t1 = xsi_get_transient_memory(4U);
    memset(t1, 0, 4U);
    t2 = t1;
    memset(t2, (unsigned char)4, 4U);
    t5 = (t0 + 3976);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t15 = (t9 + 56U);
    t16 = *((char **)t15);
    memcpy(t16, t1, 4U);
    xsi_driver_first_trans_fast_port(t5);

LAB3:    t1 = (t0 + 3832);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(28, ng0);
    t1 = (t0 + 1512U);
    t5 = *((char **)t1);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    if (t7 != 0)
        goto LAB5;

LAB7:
LAB6:    xsi_set_current_line(31, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB8;

LAB10:    xsi_set_current_line(42, ng0);
    t1 = xsi_get_transient_memory(4U);
    memset(t1, 0, 4U);
    t2 = t1;
    memset(t2, (unsigned char)4, 4U);
    t5 = (t0 + 3976);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t15 = (t9 + 56U);
    t16 = *((char **)t15);
    memcpy(t16, t1, 4U);
    xsi_driver_first_trans_fast_port(t5);

LAB9:    goto LAB3;

LAB5:    xsi_set_current_line(29, ng0);
    t1 = (t0 + 1192U);
    t8 = *((char **)t1);
    t1 = (t0 + 1032U);
    t9 = *((char **)t1);
    t1 = (t0 + 6916U);
    t10 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t9, t1);
    t11 = (t10 - 0);
    t12 = (t11 * 1);
    t13 = (4U * t12);
    t14 = (0U + t13);
    t15 = (t0 + 3912);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    memcpy(t19, t8, 4U);
    xsi_driver_first_trans_delta(t15, t14, 4U, 0LL);
    goto LAB6;

LAB8:    xsi_set_current_line(32, ng0);
    t1 = (t0 + 1992U);
    t5 = *((char **)t1);
    t1 = (t0 + 1032U);
    t8 = *((char **)t1);
    t1 = (t0 + 6916U);
    t10 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t8, t1);
    t11 = (t10 - 0);
    t12 = (t11 * 1);
    xsi_vhdl_check_range_of_index(0, 65535, 1, t10);
    t13 = (4U * t12);
    t14 = (0 + t13);
    t9 = (t5 + t14);
    t15 = (t0 + 3976);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    memcpy(t19, t9, 4U);
    xsi_driver_first_trans_fast_port(t15);
    xsi_set_current_line(35, ng0);
    t1 = (t0 + 3320);
    t2 = (t0 + 2408U);
    t5 = *((char **)t2);
    t2 = (t5 + 0);
    t8 = (t0 + 2528U);
    t9 = *((char **)t8);
    t8 = (t9 + 0);
    t15 = (t0 + 2288U);
    t16 = *((char **)t15);
    t15 = (t16 + 0);
    ieee_p_3972351953_sub_3007962107_2984157535(IEEE_P_3972351953, t1, t2, t8, t15);
    xsi_set_current_line(36, ng0);
    t1 = (t0 + 2288U);
    t2 = *((char **)t1);
    t20 = *((double *)t2);
    t3 = (t20 < 0.10000000000000001);
    if (t3 != 0)
        goto LAB11;

LAB13:    xsi_set_current_line(39, ng0);
    t1 = (t0 + 3976);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_delta(t1, 2U, 1, 0LL);

LAB12:    goto LAB9;

LAB11:    xsi_set_current_line(37, ng0);
    t1 = (t0 + 3976);
    t5 = (t1 + 56U);
    t8 = *((char **)t5);
    t9 = (t8 + 56U);
    t15 = *((char **)t9);
    *((unsigned char *)t15) = (unsigned char)3;
    xsi_driver_first_trans_delta(t1, 2U, 1, 0LL);
    goto LAB12;

}


extern void work_a_0334365669_3212880686_init()
{
	static char *pe[] = {(void *)work_a_0334365669_3212880686_p_0};
	xsi_register_didat("work_a_0334365669_3212880686", "isim/TopLevel_isim_beh.exe.sim/work/a_0334365669_3212880686.didat");
	xsi_register_executes(pe);
}
