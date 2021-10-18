#pragma config(Sensor, S1,     leftColor,      sensorEV3_Color)
#pragma config(Sensor, S2,     attachmentColor, sensorEV3_Color)
#pragma config(Sensor, S3,     gyro,           sensorEV3_Gyro)
#pragma config(Sensor, S4,     rightColor,     sensorEV3_Color)
#pragma config(Motor,  motorA,          leftAttachment, tmotorEV3_Medium, PIDControl, encoder)
#pragma config(Motor,  motorB,          rightDrive,    tmotorEV3_Large, PIDControl, reversed, driveRight, encoder)
#pragma config(Motor,  motorC,          leftDrive,     tmotorEV3_Large, PIDControl, reversed, driveLeft, encoder)
#pragma config(Motor,  motorD,          rightAttachment, tmotorEV3_Medium, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


// Files to Include  
#include "MiscDriveFunctions.C"
#include "GyroDriveFunctions.C"
#include "EncoderDriveFunctions.C"
#include "EncoderTurnFunctions.C"
#include "LineFollowingFunctions.C"


// Global Variables - These can be used anywhere in any function.  They are global in scope.  
float wheelDiameterInMM;  
int reflectedLightIntensityOnBlack; 
int reflectedLightIntensityOnWhite;  
float widthBetweenWheelsInMM;  
bool forwardMotorMovementIsPositive;

task main()
{

	// Setup parameters that may be different on different robots
	wheelDiameterInMM = 62.4;				// This is on the side of every lego wheel.   
	widthBetweenWheelsInMM = 96.72; 			// Width between wheels in mm.  Each lift arm width is 7.44mm wide 
	reflectedLightIntensityOnBlack = 0;			// Color sensor reading when reading black.  
	reflectedLightIntensityOnWhite = 100; 			// Color Sensor reading when reading white. 
	forwardMotorMovementIsPositive = false;  		// Do the encoders go posiitive when moving forward. (False = negative)	
	
	
	// Line Follow For Rotations
	lineFollowForRotations(8,30,1,1,true);

	
}
