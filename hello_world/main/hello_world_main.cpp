/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "esp_spi_flash.h"
#include "AC101.h"
#include "FaustSawtooth.h"
#include "RUNTIMESTATS.h"
#include "sdkconfig.h"
#include "soc/timer_group_struct.h"
#include "soc/timer_group_reg.h"

extern "C"
{
    void app_main(void);
}

void app_main(void)
{

    AC101 ac101;
    ac101.begin();

    RUNTIMESTATS RunTimeStats;
    RunTimeStats.start();

    int SR = 48000;
    int BS = 32;

        printf("esp_get_free_heap_size = %u", esp_get_free_heap_size());
        printf("\n");
        printf("heap_caps_get_free_size(MALLOC_CAP_INTERNAL) =  %u\t", heap_caps_get_free_size(MALLOC_CAP_INTERNAL));
        printf("\n");
        printf("heap_caps_get_free_size(MALLOC_CAP_SPIRAM)   = %u\t", heap_caps_get_free_size(MALLOC_CAP_SPIRAM));
        printf("\n");

    FaustSawtooth *faustDSP;
    faustDSP = new FaustSawtooth(SR, BS);
    faustDSP->start();

        printf("esp_get_free_heap_size = %u", esp_get_free_heap_size());
        printf("\n");
        printf("heap_caps_get_free_size(MALLOC_CAP_INTERNAL) =  %u\t", heap_caps_get_free_size(MALLOC_CAP_INTERNAL));
        printf("\n");
        printf("heap_caps_get_free_size(MALLOC_CAP_SPIRAM)   = %u\t", heap_caps_get_free_size(MALLOC_CAP_SPIRAM));
        printf("\n");

    while (1)
    {
        //faustDSP.setParamValue("gate", 1.0);
        //vTaskDelay(400 / portTICK_PERIOD_MS);
        //faustDSP.setParamValue("gate", 0.0);
        vTaskDelay(1000/ portTICK_PERIOD_MS);
        // TIMERG0.wdt_wprotect = TIMG_WDT_WKEY_VALUE;
        // TIMERG0.wdt_feed = 1;
        // TIMERG0.wdt_wprotect = 0;
        faustDSP->setParamValue("freq",rand()%(2000-50 + 1) + 50);
        // faustDSP->setParamValue("freq2",rand()%(2000-50 + 1) + 50);

        // printf("esp_get_free_heap_size = %lu", esp_get_free_heap_size());
        // printf("\n");
        // printf("heap_caps_get_free_size(MALLOC_CAP_INTERNAL) =  %u\t", heap_caps_get_free_size(MALLOC_CAP_INTERNAL));
        // printf("\n");
        // printf("heap_caps_get_free_size(MALLOC_CAP_SPIRAM)   = %u\t", heap_caps_get_free_size(MALLOC_CAP_SPIRAM));
        // printf("\n");
        // vTaskDelay(980 / portTICK_PERIOD_MS);
    }
}
