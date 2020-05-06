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
#ifndef TRACKER_H
#define TRACKER_H

#include <opencv2/tracking.hpp>

class Tracker {
public:
	Tracker(const char* tracker_type);
	bool init_tracker(cv::Mat frame, cv::Rect2d bounding_box);
	bool update_tracker(cv::Mat frame, cv::Rect2d bounding_box);
private:
	cv::Ptr<cv::Tracker> _tracker;
	cv::Rect2d _bounding_box;
	cv::Mat _frame;
};

#endif