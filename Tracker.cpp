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

#include "Tracker.h"

Tracker::Tracker(const char* tracker_type) {
#if (CV_MINOR_VERSION < 3)
	{
		_tracker = Tracker::create(trackerType);
	}
#else
	{
		if (tracker_type == "BOOSTING")
			_tracker = cv::TrackerBoosting::create();
		else if (tracker_type == "MIL")
			_tracker = cv::TrackerMIL::create();
		else if (tracker_type == "KCF")
			_tracker = cv::TrackerKCF::create();
		else if (tracker_type == "TLD")
			_tracker = cv::TrackerTLD::create();
		else if (tracker_type == "MEDIANFLOW")
			_tracker = cv::TrackerMedianFlow::create();
		else if (tracker_type == "GOTURN")
			_tracker = cv::TrackerGOTURN::create();
		else if (tracker_type == "MOSSE")
			_tracker = cv::TrackerMOSSE::create();
		else if (tracker_type == "CSRT")
			_tracker = cv::TrackerCSRT::create();
	}
#endif
}
bool Tracker::init_tracker(cv::Mat frame, cv::Rect2d bounding_box) {
	_bounding_box = bounding_box;
	_frame = frame;
	return _tracker->init(_frame, _bounding_box);
}

bool Tracker::update_tracker(cv::Mat frame, cv::Rect2d bounding_box) {
	return _tracker->update(frame, bounding_box);
}