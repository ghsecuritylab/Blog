/**
  ******************************************************************************
  * 文件名程: bsp_SysTick.c 
  * 作    者: 硬石嵌入式开发团队
  * 版    本: V1.0
  * 编写日期: 2015-10-04
  * 功    能: 系统滴答定时器底层驱动实现
  ******************************************************************************
  * 说明：
  * 本例程配套硬石stm32开发板YS-F1Pro使用。
  * 
  * 淘宝：
  * 论坛：http://www.ing10bbs.com
  * 版权归硬石嵌入式开发团队所有，请勿商用。
  ******************************************************************************
  */
/* 包含头文件 ----------------------------------------------------------------*/
#include "bsp_SysTick.h"

/* 私有类型定义 --------------------------------------------------------------*/
/* 私有宏定义 ----------------------------------------------------------------*/
/* 私有变量 ------------------------------------------------------------------*/
static __IO u32 TimingDelay,lwip_count;
uint32_t lwip_localtime;
/* 扩展变量 ------------------------------------------------------------------*/
/* 私有函数原形 --------------------------------------------------------------*/
/* 函数体 --------------------------------------------------------------------*/ 
/**
  * 函数功能: 初始化配置系统滴答定时器 SysTick
  * 输入参数: 无
  * 返 回 值: 无
  * 说    明：无
  */
void SysTick_Init(void)
{
	/* SystemFrequency / 1000    1ms中断一次
	 * SystemFrequency / 100000	 10us中断一次
	 * SystemFrequency / 1000000 1us中断一次
	 */
	if (SysTick_Config(SystemCoreClock / 1000))
	{ 
		/* Capture error */ 
		while (1);
	}
//	/* 关闭系统滴答定时器：初始化先不用开启，等需要延时时才开启定时器  */
//	SysTick->CTRL &= ~ SysTick_CTRL_ENABLE_Msk;
		SysTick->CTRL |=  SysTick_CTRL_ENABLE_Msk;
}

/**
  * 函数功能: us延时程序
  * 输入参数: nTime：延时时间
  * 返 回 值: 无
  * 说    明：无
  */
void Delay_ms(__IO u32 nTime)
{ 
	TimingDelay = nTime;	

	/* 使能滴答定时器 */ 
//	SysTick->CTRL |=  SysTick_CTRL_ENABLE_Msk;

	while(TimingDelay != 0);
  
  /* 关闭系统滴答定时器 */
//	SysTick->CTRL &= ~ SysTick_CTRL_ENABLE_Msk;
}

/**
  * 函数功能: 获取节拍程序
  * 输入参数: 无
  * 返 回 值: 无
  * 说    明：在 SysTick 中断函数 SysTick_Handler()调用
  */
void TimingDelay_Decrement(void)
{
	if (TimingDelay != 0x00)
	{ 
		TimingDelay--;
	}
}

void SysTick_Handler(void)
{
    TimingDelay_Decrement();
    if(lwip_count >=20)
    {
        lwip_count = 0;
        lwip_localtime++;
    }
    
}
/******************* (C) COPYRIGHT 2015-2020 硬石嵌入式开发团队 *****END OF FILE****/
