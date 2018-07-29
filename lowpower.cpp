
#include "mbed.h"
#include "rtc_api.h"


RTC_HandleTypeDef RtcHandle;



void
enter_standy(uint8_t hours, uint8_t minutes, uint8_t seconds)
{
   set_time(0); // reset RTC time to 0

   // clear wakeup flag so that we dont wake up immediately again
   // after previous wakeup
   __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);

   // set the alarm for MCU wakeup
   RTC_AlarmTypeDef a;
   a.Alarm = RTC_ALARM_A;
   a.AlarmTime.Hours = hours;
   a.AlarmTime.Minutes = minutes;
   a.AlarmTime.Seconds = seconds;

   // we dont have access to static RtcHandle which is initialized in
   // mbed rtc_api.c but HAL_RTC_SetAlarm_IT() seems to work with
   // following
   RtcHandle.Instance = RTC;
   HAL_RTC_SetAlarm_IT(&RtcHandle, &a, RTC_FORMAT_BIN);

   HAL_PWR_EnterSTANDBYMode();

   // we will never reach here, program will start from beginning at
   // wakeup

}
