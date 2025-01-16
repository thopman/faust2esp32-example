#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "RUNTIMESTATS.h"


// Constructor
RUNTIMESTATS::RUNTIMESTATS() {

}

// Destructor
RUNTIMESTATS::~RUNTIMESTATS() {

}

// Start RUNTIMESTATS tasks
void RUNTIMESTATS::start() {


    xTaskCreatePinnedToCore(
        RunTimeStatsTaskHandler,    /* Function that implements the task. */
        "RunTimeStats",             /* Text name for the task. */
        3072,                       /* Stack size in words, not bytes. */
        (void*)this,                /* Parameter passed into the task. */
        1,                          /* Priority at which the task is created. */
        &RunTimeTaskHandle,         /* Used to pass out the created task's handle. */
        1                           /* Number of the core the task will be pinned to */
    );

}

// stop and delete RUNTIMESTATS task
void RUNTIMESTATS::stop() {
    if (RunTimeTaskHandle != NULL) {
        vTaskDelete(RunTimeTaskHandle);
        RunTimeTaskHandle = NULL;
    }
}

// RunTimeStatsTask - prints runtime-statistics to terminal
void RUNTIMESTATS::RunTimeStatsTask() {

    // used as buffer for vTaskGetRunTimeStats();
    char pmem[1024]; 

    // setup variables to time the execution
    TickType_t xLastWakeTime;
    const TickType_t xFrequency = 5000;

    // debug overflow 
    UBaseType_t test;

    while(1){
        // debug overflow
        printf("\n");
        //test = uxTaskGetStackHighWaterMark( RunTimeTaskHandle );
        //std::string buffer = std::to_string(test);
        //printf(buffer.data());
        //printf("\n");
        // 
        printf("\n");
        vTaskGetRunTimeStats(pmem);
        printf(pmem);
        xLastWakeTime = xTaskGetTickCount();
        vTaskDelayUntil(&xLastWakeTime, xFrequency);
    }
}

// RunTimeStatsTask handler
void RUNTIMESTATS::RunTimeStatsTaskHandler(void* arg) {

    RUNTIMESTATS* doRun = (RUNTIMESTATS*)arg;
    doRun->RunTimeStatsTask();
}