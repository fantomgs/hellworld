/******************************************************************************
 ** File Name:    sprdfb_chip_common.c                                     *
 ** Author:       congfu.zhao                                           *
 ** DATE:         30/04/2013                                        *
 ** Copyright:    2013 Spreatrum, Incoporated. All Rights Reserved. *
 ** Description:                                                    *
 ******************************************************************************/
/******************************************************************************
 **                   Edit    History                               *
 **---------------------------------------------------------------------------*
 ** DATE          NAME            DESCRIPTION                       *

 ******************************************************************************/



#include "sprdfb_chip_common.h"

void __raw_bits_and(unsigned int v, unsigned int a)
{
	__raw_writel((__raw_readl(a) & v), a);
}

void __raw_bits_or(unsigned int v, unsigned int a)
{
	__raw_writel((__raw_readl(a) | v), a);
}

void __raw_bits_set_value(unsigned int reg, unsigned int value, unsigned int bit, unsigned int mask)
{
        __raw_writel(((__raw_readl(reg) & (~mask)) | (value << bit)), reg);
}

void dispc_pll_clk_set(unsigned int clk_src, unsigned int clk_div)
{
	__raw_bits_set_value(DISPC_PLL_SEL_CFG, clk_src, BITS_DISPC_PLL_SEL_CFG, BIT_DISPC_PLL_SEL_MSK);
	__raw_bits_set_value(DISPC_PLL_DIV_CFG, clk_div, BITS_DISPC_PLL_DIV_CFG, BIT_DISPC_PLL_DIV_MSK);
}

void dispc_dbi_clk_set(unsigned int clk_src, unsigned int clk_div)
{
	__raw_bits_set_value(DISPC_DBI_SEL_CFG, clk_src, BITS_DISPC_DBI_SEL_CFG, BIT_DISPC_DBI_SEL_MSK);
	__raw_bits_set_value(DISPC_DBI_DIV_CFG, clk_div, BITS_DISPC_DBI_DIV_CFG, BIT_DISPC_DBI_DIV_MSK);
}

void dispc_dpi_clk_set(unsigned int clk_src, unsigned int clk_div)
{
	__raw_bits_set_value(DISPC_DPI_SEL_CFG, clk_src, BITS_DISPC_DPI_SEL_CFG, BIT_DISPC_DPI_SEL_MSK);
	__raw_bits_set_value(DISPC_DPI_DIV_CFG, clk_div, BITS_DISPC_DPI_DIV_CFG, BIT_DISPC_DPI_DIV_MSK);
}















