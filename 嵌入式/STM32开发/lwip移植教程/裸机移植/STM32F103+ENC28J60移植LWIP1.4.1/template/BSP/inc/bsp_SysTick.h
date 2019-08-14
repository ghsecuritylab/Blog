#ifndef __BSP_SYSTICK_H__
#define __BSP_SYSTICK_H__

/* 包含头文件 ----------------------------------------------------------------*/
#include <stm32f10x.h>

/* 类型定义 ------------------------------------------------------------------*/
/* 宏定义 --------------------------------------------------------------------*/
//#define Delay_ms(x) Delay_us(x)	 //单位ms

/* 扩展变量 ------------------------------------------------------------------*/
/* 函数声明 ------------------------------------------------------------------*/
void SysTick_Init(void);
void TimingDelay_Decrement(void);
void Delay_ms(__IO u32 nTime);

#endif /* __BSP_SYSTICK_H__ */

/******************* (C) COPYRIGHT 2015-2020 硬石嵌入式开发团队 *****END OF FILE****/
