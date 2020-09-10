//Init
#include "dbus.h"
#include "chassis_task.h"
#include "timer_task.h"
#include "infantry_cmd.h"
#include "drv_io.h"
#include "rc_light.h"


//static float vx, vy, wz;

void rc_light(void const *argument)
{
  uint32_t period = osKernelSysTick();

  rc_device_t prc_dev = NULL;
  rc_info_t prc_info = NULL;

  prc_dev = rc_device_find("uart_rc");

  if (prc_dev != NULL)
  {
    prc_info = rc_device_get_info(prc_dev);
  }
  else
  {
  }
  int flag = 0;
  while (1)
  {
    LED_R_OFF();
    LED_G_OFF();
    if(prc_info->kb.bit.W){
      LED_R_ON();
      LED_G_OFF();
    }
    if (prc_info->kb.bit.S)
    {
      LED_G_ON();
      LED_R_OFF();
    }

     //
     // if(rc_device_get_state(prc_dev, RC_S1_MID2UP) == RM_OK){
     //  LED_G_ON();
     //  LED_R_OFF();
     // }
     // else if(prc_info->sw1 == 2){
     //   LED_R_ON();
     //  LED_G_ON();
     // }else{
			// LED_G_OFF();
     //  LED_R_ON();
		 // }
  }
}
