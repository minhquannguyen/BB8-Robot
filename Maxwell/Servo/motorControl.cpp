// #include "motorControl.h"
#include <thread>
#include <future>
#include <chrono>
#include <math.h>
#include <iostream>
#include <string>
#include <cstring>
#include <libusb-1.0/libusb.h>
#include <unistd.h>
#include <stdlib.h>


using namespace std;


// Sends direction control to motors
int startMotors (libusb_device_handle *handle, float speed) {
	int r;
	// Assumed 4 servos
	for (int i = 0; i < 8; i+=2) {
			r = libusb_control_transfer( handle,
							0x40,	  //request type
							0x85,	  //request
							4*speed,  //speed/value
							i,		  //servo number
							NULL,
							0,
							5000);
			if (r < 0) {
				cout << "Error starting motor " << i << endl;
				return -1;
			}
	}
	return r;
}

// Two-Wheel method
// int motorOneDirection (libusb_device_handle *handle, float speed) {
// 	int r;
// 	// Assumed 4 servos
// 	r = libusb_control_transfer( handle,
// 				0x40,	  //request type
// 				0x85,	  //request
// 				4*speed,  //speed/value
// 				0,		  //servo number
// 				NULL,
// 				0,
// 				5000);
// 	if (r < 0) {
// 		cout << "Error starting motor " << 0 << endl;
// 		return -1;
// 	}
// 	r = libusb_control_transfer( handle,
// 				0x40,	  //request type
// 				0x85,	  //request
// 				4*((3000-speed)),  //speed/value
// 				4,		  //servo number
// 				NULL,
// 				0,
// 				5000);
// 	if (r < 0) {
// 		cout << "Error starting motor " << 2 << endl;
// 		return -1;
// 	}

// 	return r;

// }

int motorOneDirection (libusb_device_handle *handle, float rSpeed, float lSpeed) {
	int r;
	// Assumed 4 servos
	// std::thread t2 (libusb_control_transfer, handle,
	// 			0x40,	  //request type
	// 			0x85,	  //request
	// 			4*rSpeed,  //speed/value
	// 			0,		  //servo number
	// 			NULL,
	// 			0,
	// 			5000).join();
	// auto f1 = std::async(libusb_control_transfer, handle,
	// 			0x40,	  //request type
	// 			0x85,	  //request
	// 			4*rSpeed,  //speed/value
	// 			0,		  //servo number
	// 			NULL,
	// 			0,
	// 			5000);
	r = libusb_control_transfer( handle,
				0x40,	  //request type
				0x85,	  //request
				4*rSpeed,  //speed/value
				0,		  //servo number
				NULL,
				0,
				5000);
	// r = f1.get()
	if (r < 0) {
		cout << "Error starting motor " << 0 << endl;
		return -1;
	}
	// std::thread t3 (libusb_control_transfer, handle,
	// 			0x40,	  //request type
	// 			0x85,	  //request
	// 			4*rSpeed,  //speed/value
	// 			0,		  //servo number
	// 			NULL,
	// 			0,
	// 			5000).join();
	// auto f2 = std::async(libusb_control_transfer, handle,
	// 			0x40,	  //request type
	// 			0x85,	  //request
	// 			4*lSpeed,  //speed/value
	// 			4,		  //servo number
	// 			NULL,
	// 			0,
	// 			5000);
	r = libusb_control_transfer( handle,
				0x40,	  //request type
				0x85,	  //request
				4*lSpeed,  //speed/value
				4,		  //servo number
				NULL,
				0,
				5000);
	// r = f2.get()
	if (r < 0) {
		cout << "Error starting motor " << 2 << endl;
		return -1;
	}
	// t2.join();
	// t3.join();
	return r;
	// return 0;
}

// Two-Wheel method
int motorTurn (libusb_device_handle *handle, float rSpeed, float lSpeed) {
	int r;
	// Assumed 4 servos
	r = libusb_control_transfer( handle,
				0x40,	  //request type
				0x85,	  //request
				4*rSpeed, //speed/value
				0,		  //servo number
				NULL,
				0,
				5000);
	if (r < 0) {
		cout << "Error starting motor " << 0 << endl;
		return -1;
	}
	r = libusb_control_transfer( handle,
				0x40,	  //request type
				0x85,	  //request
				4*lSpeed, //speed/value
				4,		  //servo number
				NULL,
				0,
				5000);
	if (r < 0) {
		cout << "Error starting motor " << 2 << endl;
		return -1;
	}

	return r;

}


// Angles output are in range [-180, 180]
// 
// Arguments:
// - angle: angle to turn in degrees
static int normalizeAngle(int angle) {
	angle %= 360;
	if (angle <= -180)
		angle += 180;
	else if (angle > 180)
		angle -= 180;
	return angle;
}

void pause_thread(int n) 
{
	this_thread::sleep_for(chrono::milliseconds(n));
	std::cout << "pause of " << n << " milliseconds ended\n";
}

// Turn a certain amount of degrees.
// Positive angles turn the robot right
// while negative angles turn left.
// 
// Arguments:
// - handle: used for communication with
// USB devices
// - angle: angle to turn in degrees
int turn(libusb_device_handle *handle, int angle) {

	int norm_angle = normalizeAngle(angle);
	cout << "norm_angle, " << norm_angle << "\n";

	float percentSpeed = 450 * 0.5;
	int lSpeed = 0;
	int rSpeed = 0;
	int timer = 0;
	if (norm_angle > 0){
		rSpeed = 1490 + percentSpeed;
		lSpeed = 1490 + percentSpeed;
		timer = (fabs(norm_angle) / 360) * 1.91 * 1000;
	} else {
		rSpeed = 1490 - percentSpeed;
		lSpeed = 1490 - percentSpeed;
		timer = (fabs(norm_angle) / 360) * 2.09 * 1000;

	}

	cout << "timer, " << timer << "\n";

	motorTurn(handle, rSpeed, lSpeed);
	std::thread t1 (pause_thread, timer);
	t1.join();
	// pause_thread(timer);
	startMotors(handle, 0);

	return 0;

	}

// Drive a certain amount of centimeters.
// Positive distances drive forward
// while negative distances drive back.
// 
// Arguments:
// - handle: used for communication with
// USB devices
// - distance: distance to travel in cm
int drive(libusb_device_handle *handle, float distance, float percent) {

	float percentSpeed = 450.f * percent;
	int lSpeed = 0;
	int rSpeed = 0;
	if (distance > 0){
		lSpeed = 1465 - percentSpeed;
		// No Weight
		// rSpeed = 1510 + percentSpeed;
		rSpeed = 1465 + percentSpeed;
	} else {
		lSpeed = 1515 + percentSpeed;
		// No Weight
		// rSpeed = 1445 - percentSpeed;
		rSpeed = 1515 - percentSpeed;
	}

	int timer = (fabs(distance) / 30.5) * 2.65 * 1000;

	motorOneDirection(handle, rSpeed, lSpeed);
	std::thread t1 (pause_thread, timer);
	t1.join();
	// pause_thread(timer);
	startMotors(handle, 0);

	return 0;
}

int main(int argc, char *argv[]) {

	if (argc < 3) {
		cout << "Not enough arguments: set args as ./testRun ['turn/drive'] [distance (cm)/angle (degrees)]" << endl;
	}

	char *action = argv[1];

	int speedInput = atoi(argv[2]);

	float percent = 0.7;

	if (argc > 3){
		percent = atof(argv[3]);
	}

	// if (speedInput < 0 || speedInput > 100) {
	// 	cout << "Speed must be between 0-100" << endl;
	// 	return -1;
	// }

	// Value of 1040 is max in forward direction
	// Value of 1450 and 0 is neutral
	// Value of 1940 is max in backward direction
	// float percentSpeed = 450 * (speedInput/100.0);

	libusb_context *ctx = NULL;
	libusb_device_handle *handle;

	// PID and VID of Maestro
	uint16_t pid = 0x008a;
	uint16_t vid = 0x1ffb;

	// error code
	int r;

	r = libusb_init(&ctx);

	if (r < 0 && r != LIBUSB_ERROR_NOT_FOUND) {
		cout << "Error: detach kernel driver failed" << endl;
		return -1;
	}

	handle = libusb_open_device_with_vid_pid(ctx, vid, pid);

	if (!handle) {
		cout << "Error: handle incorrect" << endl;
		return -1;
	}

	r = libusb_claim_interface(handle, 0);

	if (strcmp(action, "stop") == 0) {
		startMotors(handle, 0);	
	} else if (strcmp(action, "turn") == 0) {
		// int angle = 45;
		turn(handle, speedInput);
	} else if (strcmp(action, "drive") == 0) {
		// float dist = 30.5;
		drive(handle, speedInput, percent);
	} else {
		cout << "invalid string" << endl;
	}

	r = libusb_release_interface(handle, 0);
	libusb_close(handle);
	libusb_exit(ctx);
	return 0;
}