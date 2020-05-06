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

#include "Camera_capture.h"

Camera_capture::Camera_capture(uint8_t camera_id) {
	_camera_id = camera_id;
}

bool Camera_capture::start(void) {
	if (!cap.open(_camera_id))
		return 0;
	cap >> frame;
	if (frame.empty())
		return 0;
	std::thread t = std::thread(&Camera_capture::camera_accumulator, this);
	t.detach();
	fps_time_start = clock() - 1;
	return 1;
}

void Camera_capture::update_cycle_fps(void) {
	fps_counter += 1;
	if (fps_counter > 14) {
		time_taken = (float)(clock() - fps_time_start) / CLOCKS_PER_SEC;
		fps_time_start = clock();
		cycle_fps = fps_counter / time_taken;
		fps_counter = 0;
	}
}

void Camera_capture::camera_accumulator(void) {
	for (;;) {
		cap >> frame;
		if (frame.empty()) break;
		video_fps = cap.get(CV_CAP_PROP_FPS);
	}
}
