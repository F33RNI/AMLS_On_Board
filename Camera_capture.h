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

#pragma once
#ifndef CAMERA_CAPTURE_H
#define CAMERA_CAPTURE_H

#include <opencv2/videoio/videoio_c.h>
#include <opencv2/highgui/highgui.hpp>
#include <thread>
#include <time.h>
#include <iostream>

class Camera_capture {
public:
	Camera_capture(uint8_t camera_id);
	cv::VideoCapture cap;
	cv::Mat frame;
	bool start(void);
	void update_cycle_fps(void);
	uint16_t cycle_fps = 0;
	uint16_t video_fps = 0;
private:
	uint8_t _camera_id;
	void camera_accumulator(void);
	std::vector<std::thread> threads;
	uint8_t fps_counter = 0;
	float time_taken = 1;
	clock_t fps_time_start = 0;
};

#endif