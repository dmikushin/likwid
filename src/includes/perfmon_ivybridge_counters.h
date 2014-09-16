/*
 * =======================================================================================
 *
 *      Filename:  perfmon_ivybridge_counters.h
 *
 *      Description: Counter header file of perfmon module for Ivy Bridge.
 *
 *      Version:   <VERSION>
 *      Released:  <DATE>
 *
 *      Author:  Jan Treibig (jt), jan.treibig@gmail.com
 *      Project:  likwid
 *
 *      Copyright (C) 2013 Jan Treibig 
 *
 *      This program is free software: you can redistribute it and/or modify it under
 *      the terms of the GNU General Public License as published by the Free Software
 *      Foundation, either version 3 of the License, or (at your option) any later
 *      version.
 *
 *      This program is distributed in the hope that it will be useful, but WITHOUT ANY
 *      WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 *      PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License along with
 *      this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * =======================================================================================
 */

#define NUM_COUNTERS_CORE_IVYBRIDGE 8
#define NUM_COUNTERS_UNCORE_IVYBRIDGE 119
#define NUM_COUNTERS_IVYBRIDGE 127

#define IVB_VALID_OPTIONS_PMC EVENT_OPTION_EDGE_MASK|EVENT_OPTION_COUNT_KERNEL_MASK|EVENT_OPTION_INVERT_MASK|EVENT_OPTION_ANYTHREAD_MASK
#define IVB_VALID_OPTIONS_FIXED EVENT_OPTION_ANYTHREAD_MASK|EVENT_OPTION_COUNT_KERNEL_MASK

static RegisterMap ivybridge_counter_map[NUM_COUNTERS_IVYBRIDGE] = {
    /* Fixed Counters: instructions retired, cycles unhalted core */
    {"FIXC0", PMC0, FIXED, MSR_PERF_FIXED_CTR_CTRL, MSR_PERF_FIXED_CTR0, 0, 0, IVB_VALID_OPTIONS_FIXED},
    {"FIXC1", PMC1, FIXED, MSR_PERF_FIXED_CTR_CTRL, MSR_PERF_FIXED_CTR1, 0, 0, IVB_VALID_OPTIONS_FIXED},
    {"FIXC2", PMC2, FIXED, MSR_PERF_FIXED_CTR_CTRL, MSR_PERF_FIXED_CTR2, 0, 0, IVB_VALID_OPTIONS_FIXED},
    /* PMC Counters: 4 48bit wide */
    {"PMC0", PMC3, PMC, MSR_PERFEVTSEL0, MSR_PMC0, 0, 0, IVB_VALID_OPTIONS_PMC},
    {"PMC1", PMC4, PMC, MSR_PERFEVTSEL1, MSR_PMC1, 0, 0, IVB_VALID_OPTIONS_PMC},
    {"PMC2", PMC5, PMC, MSR_PERFEVTSEL2, MSR_PMC2, 0, 0, IVB_VALID_OPTIONS_PMC},
    {"PMC3", PMC6, PMC, MSR_PERFEVTSEL3, MSR_PMC3, 0, 0, IVB_VALID_OPTIONS_PMC},
    /* Temperature Sensor*/
    {"TMP0", PMC7, THERMAL, 0, 0, 0, 0, EVENT_OPTION_NONE_MASK},
    /* RAPL counters */
    {"PWR0", PMC8, POWER, 0, MSR_PKG_ENERGY_STATUS, 0, 0, EVENT_OPTION_NONE_MASK},
    {"PWR1", PMC9, POWER, 0, MSR_PP0_ENERGY_STATUS, 0, 0, EVENT_OPTION_NONE_MASK},
    {"PWR2", PMC10, POWER, 0, MSR_PP1_ENERGY_STATUS, 0, 0, EVENT_OPTION_NONE_MASK},
    {"PWR3", PMC11, POWER, 0, MSR_DRAM_ENERGY_STATUS, 0, 0, EVENT_OPTION_NONE_MASK},
    /* CBOX counters */
    {"CBOX0C0", PMC12, CBOX0, MSR_UNC_C0_PMON_CTL0, MSR_UNC_C0_PMON_CTR0, 0, 0},
    {"CBOX0C1", PMC13, CBOX0, MSR_UNC_C0_PMON_CTL1, MSR_UNC_C0_PMON_CTR1, 0, 0},
    {"CBOX0C2", PMC14, CBOX0, MSR_UNC_C0_PMON_CTL2, MSR_UNC_C0_PMON_CTR2, 0, 0},
    {"CBOX0C3", PMC15, CBOX0, MSR_UNC_C0_PMON_CTL3, MSR_UNC_C0_PMON_CTR3, 0, 0},
    {"CBOX1C0", PMC16, CBOX1, MSR_UNC_C1_PMON_CTL0, MSR_UNC_C1_PMON_CTR0, 0, 0},
    {"CBOX1C1", PMC17, CBOX1, MSR_UNC_C1_PMON_CTL1, MSR_UNC_C1_PMON_CTR1, 0, 0},
    {"CBOX1C2", PMC18, CBOX1, MSR_UNC_C1_PMON_CTL2, MSR_UNC_C1_PMON_CTR2, 0, 0},
    {"CBOX1C3", PMC19, CBOX1, MSR_UNC_C1_PMON_CTL3, MSR_UNC_C1_PMON_CTR3, 0, 0},
    {"CBOX2C0", PMC20, CBOX2, MSR_UNC_C2_PMON_CTL0, MSR_UNC_C2_PMON_CTR0, 0, 0},
    {"CBOX2C1", PMC21, CBOX2, MSR_UNC_C2_PMON_CTL1, MSR_UNC_C2_PMON_CTR1, 0, 0},
    {"CBOX2C2", PMC22, CBOX2, MSR_UNC_C2_PMON_CTL2, MSR_UNC_C2_PMON_CTR2, 0, 0},
    {"CBOX2C3", PMC23, CBOX2, MSR_UNC_C2_PMON_CTL3, MSR_UNC_C2_PMON_CTR3, 0, 0},
    {"CBOX3C0", PMC24, CBOX3, MSR_UNC_C3_PMON_CTL0, MSR_UNC_C3_PMON_CTR0, 0, 0},
    {"CBOX3C1", PMC25, CBOX3, MSR_UNC_C3_PMON_CTL1, MSR_UNC_C3_PMON_CTR1, 0, 0},
    {"CBOX3C2", PMC26, CBOX3, MSR_UNC_C3_PMON_CTL2, MSR_UNC_C3_PMON_CTR2, 0, 0},
    {"CBOX3C3", PMC27, CBOX3, MSR_UNC_C3_PMON_CTL3, MSR_UNC_C3_PMON_CTR3, 0, 0},
    {"CBOX4C0", PMC28, CBOX4, MSR_UNC_C4_PMON_CTL0, MSR_UNC_C4_PMON_CTR0, 0, 0},
    {"CBOX4C1", PMC29, CBOX4, MSR_UNC_C4_PMON_CTL1, MSR_UNC_C4_PMON_CTR1, 0, 0},
    {"CBOX4C2", PMC30, CBOX4, MSR_UNC_C4_PMON_CTL2, MSR_UNC_C4_PMON_CTR2, 0, 0},
    {"CBOX4C3", PMC31, CBOX4, MSR_UNC_C4_PMON_CTL3, MSR_UNC_C4_PMON_CTR3, 0, 0},
    {"CBOX5C0", PMC32, CBOX5, MSR_UNC_C5_PMON_CTL0, MSR_UNC_C5_PMON_CTR0, 0, 0},
    {"CBOX5C1", PMC33, CBOX5, MSR_UNC_C5_PMON_CTL1, MSR_UNC_C5_PMON_CTR1, 0, 0},
    {"CBOX5C2", PMC34, CBOX5, MSR_UNC_C5_PMON_CTL2, MSR_UNC_C5_PMON_CTR2, 0, 0},
    {"CBOX5C3", PMC35, CBOX5, MSR_UNC_C5_PMON_CTL3, MSR_UNC_C5_PMON_CTR3, 0, 0},
    {"CBOX6C0", PMC36, CBOX6, MSR_UNC_C6_PMON_CTL0, MSR_UNC_C6_PMON_CTR0, 0, 0},
    {"CBOX6C1", PMC37, CBOX6, MSR_UNC_C6_PMON_CTL1, MSR_UNC_C6_PMON_CTR1, 0, 0},
    {"CBOX6C2", PMC38, CBOX6, MSR_UNC_C6_PMON_CTL2, MSR_UNC_C6_PMON_CTR2, 0, 0},
    {"CBOX6C3", PMC39, CBOX6, MSR_UNC_C6_PMON_CTL3, MSR_UNC_C6_PMON_CTR3, 0, 0},
    {"CBOX7C0", PMC40, CBOX7, MSR_UNC_C7_PMON_CTL0, MSR_UNC_C7_PMON_CTR0, 0, 0},
    {"CBOX7C1", PMC41, CBOX7, MSR_UNC_C7_PMON_CTL1, MSR_UNC_C7_PMON_CTR1, 0, 0},
    {"CBOX7C2", PMC42, CBOX7, MSR_UNC_C7_PMON_CTL2, MSR_UNC_C7_PMON_CTR2, 0, 0},
    {"CBOX7C3", PMC43, CBOX7, MSR_UNC_C7_PMON_CTL3, MSR_UNC_C7_PMON_CTR3, 0, 0},
    {"CBOX8C0", PMC44, CBOX8, MSR_UNC_C8_PMON_CTL0, MSR_UNC_C8_PMON_CTR0, 0, 0},
    {"CBOX8C1", PMC45, CBOX8, MSR_UNC_C8_PMON_CTL1, MSR_UNC_C8_PMON_CTR1, 0, 0},
    {"CBOX8C2", PMC46, CBOX8, MSR_UNC_C8_PMON_CTL2, MSR_UNC_C8_PMON_CTR2, 0, 0},
    {"CBOX8C3", PMC47, CBOX8, MSR_UNC_C8_PMON_CTL3, MSR_UNC_C8_PMON_CTR3, 0, 0},
    {"CBOX9C0", PMC48, CBOX9, MSR_UNC_C9_PMON_CTL0, MSR_UNC_C9_PMON_CTR0, 0, 0},
    {"CBOX9C1", PMC49, CBOX9, MSR_UNC_C9_PMON_CTL1, MSR_UNC_C9_PMON_CTR1, 0, 0},
    {"CBOX9C2", PMC50, CBOX9, MSR_UNC_C9_PMON_CTL2, MSR_UNC_C9_PMON_CTR2, 0, 0},
    {"CBOX9C3", PMC51, CBOX9, MSR_UNC_C9_PMON_CTL3, MSR_UNC_C9_PMON_CTR3, 0, 0},
    {"CBOX10C0", PMC52, CBOX10, MSR_UNC_C10_PMON_CTL0, MSR_UNC_C10_PMON_CTR0, 0, 0},
    {"CBOX10C1", PMC53, CBOX10, MSR_UNC_C10_PMON_CTL1, MSR_UNC_C10_PMON_CTR1, 0, 0},
    {"CBOX10C2", PMC54, CBOX10, MSR_UNC_C10_PMON_CTL2, MSR_UNC_C10_PMON_CTR2, 0, 0},
    {"CBOX10C3", PMC55, CBOX10, MSR_UNC_C10_PMON_CTL3, MSR_UNC_C10_PMON_CTR3, 0, 0},
    {"CBOX11C0", PMC56, CBOX11, MSR_UNC_C11_PMON_CTL0, MSR_UNC_C11_PMON_CTR0, 0, 0},
    {"CBOX11C1", PMC57, CBOX11, MSR_UNC_C11_PMON_CTL1, MSR_UNC_C11_PMON_CTR1, 0, 0},
    {"CBOX11C2", PMC58, CBOX11, MSR_UNC_C11_PMON_CTL2, MSR_UNC_C11_PMON_CTR2, 0, 0},
    {"CBOX11C3", PMC59, CBOX11, MSR_UNC_C11_PMON_CTL3, MSR_UNC_C11_PMON_CTR3, 0, 0},
    {"CBOX12C0", PMC60, CBOX12, MSR_UNC_C12_PMON_CTL0, MSR_UNC_C12_PMON_CTR0, 0, 0},
    {"CBOX12C1", PMC61, CBOX12, MSR_UNC_C12_PMON_CTL1, MSR_UNC_C12_PMON_CTR1, 0, 0},
    {"CBOX12C2", PMC62, CBOX12, MSR_UNC_C12_PMON_CTL2, MSR_UNC_C12_PMON_CTR2, 0, 0},
    {"CBOX12C3", PMC63, CBOX12, MSR_UNC_C12_PMON_CTL3, MSR_UNC_C12_PMON_CTR3, 0, 0},
    {"CBOX13C0", PMC64, CBOX13, MSR_UNC_C13_PMON_CTL0, MSR_UNC_C13_PMON_CTR0, 0, 0},
    {"CBOX13C1", PMC65, CBOX13, MSR_UNC_C13_PMON_CTL1, MSR_UNC_C13_PMON_CTR1, 0, 0},
    {"CBOX13C2", PMC66, CBOX13, MSR_UNC_C13_PMON_CTL2, MSR_UNC_C13_PMON_CTR2, 0, 0},
    {"CBOX13C3", PMC67, CBOX13, MSR_UNC_C13_PMON_CTL3, MSR_UNC_C13_PMON_CTR3, 0, 0},
    {"CBOX14C0", PMC68, CBOX14, MSR_UNC_C14_PMON_CTL0, MSR_UNC_C14_PMON_CTR0, 0, 0},
    {"CBOX14C1", PMC69, CBOX14, MSR_UNC_C14_PMON_CTL1, MSR_UNC_C14_PMON_CTR1, 0, 0},
    {"CBOX14C2", PMC70, CBOX14, MSR_UNC_C14_PMON_CTL2, MSR_UNC_C14_PMON_CTR2, 0, 0},
    {"CBOX14C3", PMC71, CBOX14, MSR_UNC_C14_PMON_CTL3, MSR_UNC_C14_PMON_CTR3, 0, 0},
    /* IMC Counters: 4 48bit wide per memory channel, split in two reads */
    {"MBOX0C0",PMC72, MBOX0, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_0_CH_2},
    {"MBOX0C1",PMC73, MBOX0, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_0_CH_2},
    {"MBOX0C2",PMC74, MBOX0, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_0_CH_2},
    {"MBOX0C3",PMC75, MBOX0, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_0_CH_2},
    {"MBOX0FIX",PMC76, MBOX0FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_0_CH_2},
    {"MBOX1C0",PMC77, MBOX1, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_0_CH_3},
    {"MBOX1C1",PMC78, MBOX1, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_0_CH_3},
    {"MBOX1C2",PMC79, MBOX1, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_0_CH_3},
    {"MBOX1C3",PMC80, MBOX1, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_0_CH_3},
    {"MBOX1FIX",PMC81, MBOX1FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_0_CH_3},
    {"MBOX2C0",PMC82, MBOX2, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_0_CH_0},
    {"MBOX2C1",PMC83, MBOX2, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_0_CH_0},
    {"MBOX2C2",PMC84, MBOX2, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_0_CH_0},
    {"MBOX2C3",PMC85, MBOX2, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_0_CH_0},
    {"MBOX2FIX",PMC86, MBOX2FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_0_CH_0},
    {"MBOX3C0",PMC87, MBOX3, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_0_CH_1},
    {"MBOX3C1",PMC88, MBOX3, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_0_CH_1},
    {"MBOX3C2",PMC89, MBOX3, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_0_CH_1},
    {"MBOX3C3",PMC90, MBOX3, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_0_CH_1},
    {"MBOX3FIX",PMC91, MBOX3FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_0_CH_1},
    /* QPI counters four 48bit  wide per port, split in two reads */
    {"SBOX0C0",PMC92, SBOX0, PCI_UNC_QPI_PMON_CTL_0, PCI_UNC_QPI_PMON_CTR_0_A, PCI_UNC_QPI_PMON_CTR_0_B, PCI_QPI_DEVICE_PORT_0},
    {"SBOX0C1",PMC93, SBOX0, PCI_UNC_QPI_PMON_CTL_1, PCI_UNC_QPI_PMON_CTR_1_A, PCI_UNC_QPI_PMON_CTR_1_B, PCI_QPI_DEVICE_PORT_0},
    {"SBOX0C2",PMC94, SBOX0, PCI_UNC_QPI_PMON_CTL_2, PCI_UNC_QPI_PMON_CTR_2_A, PCI_UNC_QPI_PMON_CTR_2_B, PCI_QPI_DEVICE_PORT_0},
    {"SBOX0C3",PMC95, SBOX0, PCI_UNC_QPI_PMON_CTL_3, PCI_UNC_QPI_PMON_CTR_3_A, PCI_UNC_QPI_PMON_CTR_3_B, PCI_QPI_DEVICE_PORT_0},
    {"SBOX1C0",PMC96, SBOX1, PCI_UNC_QPI_PMON_CTL_0, PCI_UNC_QPI_PMON_CTR_0_A, PCI_UNC_QPI_PMON_CTR_0_B, PCI_QPI_DEVICE_PORT_1},
    {"SBOX1C1",PMC97, SBOX1, PCI_UNC_QPI_PMON_CTL_1, PCI_UNC_QPI_PMON_CTR_1_A, PCI_UNC_QPI_PMON_CTR_1_B, PCI_QPI_DEVICE_PORT_1},
    {"SBOX1C2",PMC98, SBOX1, PCI_UNC_QPI_PMON_CTL_2, PCI_UNC_QPI_PMON_CTR_2_A, PCI_UNC_QPI_PMON_CTR_2_B, PCI_QPI_DEVICE_PORT_1},
    {"SBOX1C3",PMC99, SBOX1, PCI_UNC_QPI_PMON_CTL_3, PCI_UNC_QPI_PMON_CTR_3_A, PCI_UNC_QPI_PMON_CTR_3_B, PCI_QPI_DEVICE_PORT_1},
    {"SBOX0FIX",PMC100, SBOX0FIX, 0, PCI_UNC_QPI_RATE_STATUS, 0, PCI_QPI_MISC_DEVICE_PORT_0},
    {"SBOX1FIX",PMC101, SBOX1FIX, 0, PCI_UNC_QPI_RATE_STATUS, 0, PCI_QPI_MISC_DEVICE_PORT_1},
    {"SBOX2FIX",PMC102, SBOX2FIX, 0, PCI_UNC_QPI_RATE_STATUS, 0, PCI_QPI_MISC_DEVICE_PORT_2},
    {"UBOX0", PMC103, UBOX, MSR_UNC_U_PMON_CTL0, MSR_UNC_U_PMON_CTR0, 0, 0},
    {"UBOX1", PMC104, UBOX, MSR_UNC_U_PMON_CTL1, MSR_UNC_U_PMON_CTR1, 0, 0},
    {"UBOXFIX", PMC105, UBOXFIX, MSR_UNC_U_UCLK_FIXED_CTL, MSR_UNC_U_UCLK_FIXED_CTR, 0, 0},
    {"BBOX0C0", PMC106, BBOX0, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_HA_PMON_CTR_0_A, PCI_UNC_HA_PMON_CTR_0_B, PCI_HA_DEVICE_0},
    {"BBOX0C1", PMC107, BBOX0, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_HA_PMON_CTR_1_A, PCI_UNC_HA_PMON_CTR_1_B, PCI_HA_DEVICE_0},
    {"BBOX0C2", PMC108, BBOX0, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_HA_PMON_CTR_2_A, PCI_UNC_HA_PMON_CTR_2_B, PCI_HA_DEVICE_0},
    {"BBOX0C3", PMC109, BBOX0, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_HA_PMON_CTR_3_A, PCI_UNC_HA_PMON_CTR_3_B, PCI_HA_DEVICE_0},
    {"BBOX1C0", PMC110, BBOX1, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_HA_PMON_CTR_0_A, PCI_UNC_HA_PMON_CTR_0_B, PCI_HA_DEVICE_1},
    {"BBOX1C1", PMC111, BBOX1, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_HA_PMON_CTR_1_A, PCI_UNC_HA_PMON_CTR_1_B, PCI_HA_DEVICE_1},
    {"BBOX1C2", PMC112, BBOX1, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_HA_PMON_CTR_2_A, PCI_UNC_HA_PMON_CTR_2_B, PCI_HA_DEVICE_1},
    {"BBOX1C3", PMC113, BBOX1, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_HA_PMON_CTR_3_A, PCI_UNC_HA_PMON_CTR_3_B, PCI_HA_DEVICE_1},
    {"PBOX0", PMC114, PBOX, PCI_UNC_R2PCIE_PMON_CTL_0, PCI_UNC_R2PCIE_PMON_CTR_0_A, PCI_UNC_R2PCIE_PMON_CTR_0_B, PCI_R2PCIE_DEVICE},
    {"PBOX1", PMC115, PBOX, PCI_UNC_R2PCIE_PMON_CTL_1, PCI_UNC_R2PCIE_PMON_CTR_1_A, PCI_UNC_R2PCIE_PMON_CTR_1_B, PCI_R2PCIE_DEVICE},
    {"PBOX2", PMC116, PBOX, PCI_UNC_R2PCIE_PMON_CTL_2, PCI_UNC_R2PCIE_PMON_CTR_2_A, PCI_UNC_R2PCIE_PMON_CTR_2_B, PCI_R2PCIE_DEVICE},
    {"PBOX3", PMC117, PBOX, PCI_UNC_R2PCIE_PMON_CTL_3, PCI_UNC_R2PCIE_PMON_CTR_3_A, PCI_UNC_R2PCIE_PMON_CTR_3_B, PCI_R2PCIE_DEVICE},
    {"RBOX0C0", PMC118, RBOX0, PCI_UNC_R3QPI_PMON_CTL_0, PCI_UNC_R3QPI_PMON_CTR_0_A, PCI_UNC_R3QPI_PMON_CTR_0_B, PCI_R3QPI_DEVICE_LINK_0},
    {"RBOX0C1", PMC119, RBOX0, PCI_UNC_R3QPI_PMON_CTL_1, PCI_UNC_R3QPI_PMON_CTR_1_A, PCI_UNC_R3QPI_PMON_CTR_1_B, PCI_R3QPI_DEVICE_LINK_0},
    {"RBOX0C2", PMC120, RBOX0, PCI_UNC_R3QPI_PMON_CTL_2, PCI_UNC_R3QPI_PMON_CTR_2_A, PCI_UNC_R3QPI_PMON_CTR_2_B, PCI_R3QPI_DEVICE_LINK_0},
    {"RBOX1C0", PMC121, RBOX1, PCI_UNC_R3QPI_PMON_CTL_0, PCI_UNC_R3QPI_PMON_CTR_0_A, PCI_UNC_R3QPI_PMON_CTR_0_B, PCI_R3QPI_DEVICE_LINK_1},
    {"RBOX1C1", PMC122, RBOX1, PCI_UNC_R3QPI_PMON_CTL_1, PCI_UNC_R3QPI_PMON_CTR_1_A, PCI_UNC_R3QPI_PMON_CTR_1_B, PCI_R3QPI_DEVICE_LINK_1},
    {"RBOX1C2", PMC123, RBOX1, PCI_UNC_R3QPI_PMON_CTL_2, PCI_UNC_R3QPI_PMON_CTR_2_A, PCI_UNC_R3QPI_PMON_CTR_2_B, PCI_R3QPI_DEVICE_LINK_1},
    {"RBOX2C0", PMC124, RBOX2, PCI_UNC_R3QPI_PMON_CTL_0, PCI_UNC_R3QPI_PMON_CTR_0_A, PCI_UNC_R3QPI_PMON_CTR_0_B, PCI_R3QPI_DEVICE_LINK_2},
    {"RBOX2C1", PMC125, RBOX2, PCI_UNC_R3QPI_PMON_CTL_1, PCI_UNC_R3QPI_PMON_CTR_1_A, PCI_UNC_R3QPI_PMON_CTR_1_B, PCI_R3QPI_DEVICE_LINK_2},
    {"RBOX2C2", PMC126, RBOX2, PCI_UNC_R3QPI_PMON_CTL_2, PCI_UNC_R3QPI_PMON_CTR_2_A, PCI_UNC_R3QPI_PMON_CTR_2_B, PCI_R3QPI_DEVICE_LINK_2}
};

static BoxMap ivybridge_box_map[NUM_UNITS] = {
    [PMC] = {MSR_PERF_GLOBAL_CTRL, MSR_PERF_GLOBAL_STATUS, MSR_PERF_GLOBAL_OVF_CTRL, 0, 0, 48},
    [MBOX0] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 1, PCI_IMC_DEVICE_0_CH_2, 48},
    [MBOX1] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 1, PCI_IMC_DEVICE_0_CH_3, 48},
    [MBOX2] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 1, PCI_IMC_DEVICE_0_CH_0, 48},
    [MBOX3] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 1, PCI_IMC_DEVICE_0_CH_1, 48},
    [CBOX0] = {MSR_UNC_C0_PMON_BOX_CTL, 0, 0, 0, 0, 44},
    [CBOX1] = {MSR_UNC_C1_PMON_BOX_CTL, 0, 0, 0, 0, 44},
    [CBOX2] = {MSR_UNC_C2_PMON_BOX_CTL, 0, 0, 0, 0, 44},
    [CBOX3] = {MSR_UNC_C3_PMON_BOX_CTL, 0, 0, 0, 0, 44},
    [CBOX4] = {MSR_UNC_C4_PMON_BOX_CTL, 0, 0, 0, 0, 44},
    [CBOX5] = {MSR_UNC_C5_PMON_BOX_CTL, 0, 0, 0, 0, 44},
    [CBOX6] = {MSR_UNC_C6_PMON_BOX_CTL, 0, 0, 0, 0, 44},
    [CBOX7] = {MSR_UNC_C7_PMON_BOX_CTL, 0, 0, 0, 0, 44},
    [CBOX8] = {MSR_UNC_C8_PMON_BOX_CTL, 0, 0, 0, 0, 44},
    [CBOX9] = {MSR_UNC_C9_PMON_BOX_CTL, 0, 0, 0, 0, 44},
    [CBOX10] = {MSR_UNC_C10_PMON_BOX_CTL, 0, 0, 0, 0, 44},
    [CBOX11] = {MSR_UNC_C11_PMON_BOX_CTL, 0, 0, 0, 0, 44},
    [CBOX12] = {MSR_UNC_C12_PMON_BOX_CTL, 0, 0, 0, 0, 44},
    [CBOX13] = {MSR_UNC_C13_PMON_BOX_CTL, 0, 0, 0, 0, 44},
    [CBOX14] = {MSR_UNC_C14_PMON_BOX_CTL, 0, 0, 0, 0, 44},
    [BBOX0] = {PCI_UNC_HA_PMON_BOX_CTL, PCI_UNC_HA_PMON_BOX_STATUS, PCI_UNC_HA_PMON_BOX_STATUS, 1, PCI_HA_DEVICE_0, 48},
    [BBOX1] = {PCI_UNC_HA_PMON_BOX_CTL, PCI_UNC_HA_PMON_BOX_STATUS, PCI_UNC_HA_PMON_BOX_STATUS, 1, PCI_HA_DEVICE_1, 48},
    [SBOX0] = {PCI_UNC_QPI_PMON_BOX_CTL, PCI_UNC_QPI_PMON_BOX_STATUS, PCI_UNC_QPI_PMON_BOX_STATUS, 1, PCI_QPI_DEVICE_PORT_0, 48},
    [SBOX1] = {PCI_UNC_QPI_PMON_BOX_CTL, PCI_UNC_QPI_PMON_BOX_STATUS, PCI_UNC_QPI_PMON_BOX_STATUS, 1, PCI_QPI_DEVICE_PORT_1, 48},
    [WBOX] = {MSR_UNC_PCU_PMON_BOX_CTL, MSR_UNC_PCU_PMON_BOX_STATUS, MSR_UNC_PCU_PMON_BOX_STATUS, 0, 0, 48},
    [UBOX] = {0, MSR_UNC_U_PMON_BOX_STATUS, MSR_UNC_U_PMON_BOX_STATUS, 0, 0, 44},
    [PBOX] = {PCI_UNC_R2PCIE_PMON_BOX_CTL, PCI_UNC_R2PCIE_PMON_BOX_STATUS, PCI_UNC_R2PCIE_PMON_BOX_STATUS, 1,PCI_R2PCIE_DEVICE, 44},
    [RBOX0] = {PCI_UNC_R3QPI_PMON_BOX_CTL, PCI_UNC_R3QPI_PMON_BOX_STATUS, PCI_UNC_R3QPI_PMON_BOX_STATUS, 1,PCI_R3QPI_DEVICE_LINK_0, 44},
    [RBOX1] = {PCI_UNC_R3QPI_PMON_BOX_CTL, PCI_UNC_R3QPI_PMON_BOX_STATUS, PCI_UNC_R3QPI_PMON_BOX_STATUS, 1,PCI_R3QPI_DEVICE_LINK_1, 44},
    [RBOX2] = {PCI_UNC_R3QPI_PMON_BOX_CTL, PCI_UNC_R3QPI_PMON_BOX_STATUS, PCI_UNC_R3QPI_PMON_BOX_STATUS, 1,PCI_R3QPI_DEVICE_LINK_2, 44}
};
