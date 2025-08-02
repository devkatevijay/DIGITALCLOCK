#include <project.h>
#include <stdio.h>
#include <stdbool.h>

/* How many alarms do we support? */
#define NUM_ALARMS  3

/* Alarm duration (how many 250 ms loops to keep the buzzer/LCD in “ALARM” state) */
#define ALARM_DURATION_ITERATIONS  20

/* Alarm definitions: year, month, day, hour, minute, second */
typedef struct {
    uint16_t year;
    uint8_t  month;
    uint8_t  day;
    uint8_t  hour;
    uint8_t  minute;
    uint8_t  second;
} AlarmDef;

/* Fill in your alarms here */
static const AlarmDef alarmDefs[NUM_ALARMS] = {
    {2025, 4, 14, 14, 31, 0},  // Alarm #0
    {2025, 4, 14, 14,  32, 0},  // Alarm #1
    {2025, 4, 14, 14, 33, 0},  // Alarm #2
};

int main(void)
{
    CyGlobalIntEnable;
    RTC_Start();
    LCD_Start();
    
    /* Initialize RTC to some known time/date */
    RTC_WriteHour(14);
    RTC_WriteMinute(30);
    RTC_WriteSecond(10);
    RTC_WriteDayOfMonth(14);
    RTC_WriteMonth(4);
    RTC_WriteYear(2025);
    
    /* Per‑alarm state: whether it’s currently active, and its remaining iterations */
    bool  alarmActive[NUM_ALARMS]  = { false };
    int   alarmCounter[NUM_ALARMS] = { 0 };
    
    /* Stopwatch state (unchanged) */
    bool     stopwatchMode    = false;
    bool     stopwatchFrozen  = false;
    bool     startButtonPrev  = false;
    bool     stopButtonPrev   = false;
    uint16_t stopwatchTick    = 0;
    uint32_t stopwatchSeconds = 0;
    
    for(;;)
    {
        /* --- START/RESET STOPWATCH: Pin (P6_3, active low) --- */
        if (Pin_Read() == 0) {
            if (!startButtonPrev) {
                stopwatchMode   = !stopwatchMode;
                stopwatchFrozen = false;
                if (stopwatchMode) {
                    stopwatchTick    = 0;
                    stopwatchSeconds = 0;
                }
                startButtonPrev = true;
            }
        } else {
            startButtonPrev = false;
        }
        
        /* --- STOP/FREEZE STOPWATCH: Pin2 (P15_5, active low) --- */
        if (Pin2_Read() == 0) {
            if (!stopButtonPrev) {
                if (stopwatchMode) {
                    stopwatchMode   = false;
                    stopwatchFrozen = true;
                }
                stopButtonPrev = true;
            }
        } else {
            stopButtonPrev = false;
        }
        
        /* --- UPDATE STOPWATCH IF RUNNING --- */
        if (stopwatchMode) {
            stopwatchTick += 250;
            if (stopwatchTick >= 1000) {
                stopwatchSeconds += stopwatchTick / 1000;
                stopwatchTick %= 1000;
            }
        }
        
        /* --- READ CURRENT RTC --- */
        uint16_t year   = RTC_ReadYear();
        uint8_t  month  = RTC_ReadMonth();
        uint8_t  day    = RTC_ReadDayOfMonth();
        uint8_t  hour   = RTC_ReadHour();
        uint8_t  minute = RTC_ReadMinute();
        uint8_t  second = RTC_ReadSecond();
        
        /* --- CHECK EACH ALARM FOR TRIGGER --- */
        for (int i = 0; i < NUM_ALARMS; i++) {
            if (!alarmActive[i]
                && year   == alarmDefs[i].year
                && month  == alarmDefs[i].month
                && day    == alarmDefs[i].day
                && hour   == alarmDefs[i].hour
                && minute == alarmDefs[i].minute
                && second == alarmDefs[i].second)
            {
                alarmActive[i]  = true;
                alarmCounter[i] = ALARM_DURATION_ITERATIONS;
                // Buzzer_Write(1);
            }
        }
        
        /* --- DRAW LINE 1: DATE --- */
        char line1[16];
        snprintf(line1, sizeof(line1),
                 "Date:%02d/%02d/%04d",
                 day, month, year);
        LCD_Position(0, 0);
        LCD_PrintString(line1);
        
        /* --- DRAW LINE 2: priority: stopwatch running → frozen → any alarm → clock --- */
        char line2[16];
        
        if (stopwatchMode) {
            /* running */
            uint8_t h = stopwatchSeconds / 3600;
            uint8_t m = (stopwatchSeconds % 3600) / 60;
            uint8_t s = stopwatchSeconds % 60;
            snprintf(line2, sizeof(line2),
                     "Stop:%02d:%02d:%02d", h, m, s);
        }
        else if (stopwatchFrozen) {
            /* frozen */
            uint8_t h = stopwatchSeconds / 3600;
            uint8_t m = (stopwatchSeconds % 3600) / 60;
            uint8_t s = stopwatchSeconds % 60;
            snprintf(line2, sizeof(line2),
                     "Hold:%02d:%02d:%02d", h, m, s);
        }
        else {
            /* check if any alarm is active right now */
            int activeIdx = -1;
            for (int i = 0; i < NUM_ALARMS; i++) {
                if (alarmActive[i]) {
                    activeIdx = i;
                    break;
                }
            }
            if (activeIdx >= 0) {
                /* show ALARM for the first active one */
                snprintf(line2, sizeof(line2),
                         "ALARM !!!");
                
                /* countdown and clear when done */
                if (--alarmCounter[activeIdx] <= 0) {
                    alarmActive[activeIdx] = false;
                    // Buzzer_Write(0);
                }
            }
            else {
                /* normal clock display */
                snprintf(line2, sizeof(line2),
                         "Time:%02d:%02d:%02d", hour, minute, second);
            }
        }
        
        LCD_Position(1, 0);
        LCD_PrintString(line2);
        
        CyDelay(250);
    }
}
