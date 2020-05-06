/*
  ******************************
  *                            *
  * AMLS On-board system  V2.0 *
  *                            *
  ********************************************************************************************
  *
  * COPYRIGHT(c) 2020 Pavel Evgenyevich Neshumov
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Any use of code and / or binary files is prohibited without the written and certified
  *      consent of the owner (Pavel Evgenyevich Neshumov)
  *   2. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   3. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *
  * THIS SOFTWARE WAS DEVELOPED AS PART OF PROJECT ACTIVITY IN GROUP 181-311 AT THE
  * MOSCOW POLYTECHNIC UNIVERCITY. HOWEVER, THE OWNER (Pavel Evgenyevich Neshumov) 
  * REMAINS THE RIGHT, WITHOUT NOTICE, TO CHANGE THE PURPOSE AND ENVIRONMENT OF APPLICATION 
  * OF THIS SOFTWARE. ALSO THE OWNER (Pavel Evgenyevich Neshumov) MAY PROHIBIT USE OF THIS 
  * SOFTWARE FOR ANY ORGANIZATION, PEOPLE, STRUCTURES.
  *
  ********************************************************************************************
*/


// ===========================
// Libraries
// ===========================
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/tracking.hpp>
#include <iostream>
#include <time.h>
#include <thread>

#include "Camera_capture.h"
#include "Tracker.h"
#include "Config.h"

Tracker tracker(TRACKER_TYPE);
Camera_capture camera_capture(CAMERA_ID);
cv::Mat frame;

int main()
{
	if (!camera_capture.start())
		return 1;

	for (;;)
	{
		//Capture frame
		frame = camera_capture.frame;
		if (frame.empty()) break;
		camera_capture.update_cycle_fps();

		//DEBUG
#ifdef DEBUG_FRAME
		putText(frame, "Cycle FPS: " + std::to_string(camera_capture.cycle_fps)
			+ " Video FPS: " + std::to_string(camera_capture.video_fps),
			cv::Point(0, 32), cv::FONT_HERSHEY_DUPLEX, 1.0, cv::Scalar(0, 255, 0), 1);
		cv::imshow("frame", frame);
#endif // DEBUG_FRAME

		//Exit by q key pressed
		if (cv::waitKey(10) == 'q') break;
	}
	exit(0);
	return 0;
}