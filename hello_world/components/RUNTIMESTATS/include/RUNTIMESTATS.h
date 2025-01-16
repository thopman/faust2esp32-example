#ifndef RUNTIMESTATS_H
#define RUNTIMESTATS_H

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

class RUNTIMESTATS
{
	public:

	// Constructor
	RUNTIMESTATS();

	// Destructor
	~RUNTIMESTATS();

	void start();

	void stop();



	private:


	///////////////////////////////////////////////
	/* RunTimeStatsTask variables and prototypes */

	// Prototypes

	// RunTimeStatsTask - prints runtime-statistics to 
	void RunTimeStatsTask();

	// Taskhandle for the displayTask
	TaskHandle_t RunTimeTaskHandle;

	// RunTimeStatsTask handler
	static void RunTimeStatsTaskHandler(void*);
    
};

#endif