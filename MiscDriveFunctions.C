//----------------------------------------------------------------------------------------------------
// Name: turnOffDriveMotors 
//----------------------------------------------------------------------------------------------------
// Description:
//	turns off drive motors
//----------------------------------------------------------------------------------------------------
//Inputs: None
//
//----------------------------------------------------------------------------------------------------
void turnOffDriveMotors()
{

	setMotorSpeed(leftDrive, 0);
	setMotorSpeed(rightDrive, 0);

}

//----------------------------------------------------------------------------------------------------
// Name: getLeftMotorEncoder
//----------------------------------------------------------------------------------------------------
// Description:
//	Return the left motor encoder.   Because the encoder is backwards, we use this function to 
//	return the negative.
//----------------------------------------------------------------------------------------------------
//Inputs: None
//
//----------------------------------------------------------------------------------------------------
float getLeftMotorEncoder()
{

	return -nMotorEncoder[leftDrive]; 													// Get the value of the left motor encoder, make it negative and assign it to the encoderValue

}

//----------------------------------------------------------------------------------------------------
// Name: getRightMotorEncoder
//----------------------------------------------------------------------------------------------------
// Description:
// 	Return right motor encoder.
//	
//----------------------------------------------------------------------------------------------------
//Inputs: None
//
//----------------------------------------------------------------------------------------------------
float getRightMotorEncoder()
{

	return -nMotorEncoder[rightDrive]; 													// Get the value of the left motor encoder, make it negative and assign it to the encoderValue

}

//----------------------------------------------------------------------------------------------------
// Name: setDriveMotorsToBrake
//----------------------------------------------------------------------------------------------------
// Description: Makes motors brake
//	
//----------------------------------------------------------------------------------------------------
//Inputs: None
//
//----------------------------------------------------------------------------------------------------
void setDriveMotorsToBrake()
{

	setMotorBrakeMode(leftDrive,motorBrake);
	setMotorBrakeMode(rightDrive,motorBrake);

}

//----------------------------------------------------------------------------------------------------
// Name: setDriveMotorsToCoast
//----------------------------------------------------------------------------------------------------
// Description: Makes motors Coast 
 //	
//----------------------------------------------------------------------------------------------------
//Inputs: None
//
//----------------------------------------------------------------------------------------------------
void setDriveMotorsToCoast()
{

	setMotorBrakeMode(leftDrive,motorCoast);
	setMotorBrakeMode(rightDrive,motorCoast);

}

//----------------------------------------------------------------------------------------------------
// Name: setAllMotorsToCoast 
//----------------------------------------------------------------------------------------------------
// Description: Sets all motors to coast
//	
//----------------------------------------------------------------------------------------------------
//Inputs: None
//
//----------------------------------------------------------------------------------------------------
void setAllMotorsToCoast()
{
	setMotorBrakeMode(leftDrive,motorCoast);
	setMotorBrakeMode(rightDrive,motorCoast);
	setMotorBrakeMode(leftAttachment,motorCoast);
	setMotorBrakeMode(rightAttachment,motorCoast);
}


//----------------------------------------------------------------------------------------------------
// Name: resetDriveMotorEncoders
//----------------------------------------------------------------------------------------------------
// Description: resets the drive motor encoders
//	
//----------------------------------------------------------------------------------------------------
//Inputs:
//
//----------------------------------------------------------------------------------------------------
void resetDriveMotorEncoders()
{
	nMotorEncoder[leftDrive] = 0;
	nMotorEncoder[rightDrive] = 0;
}


//----------------------------------------------------------------------------------------------------
// Name: resetAllMotorEncoders
//----------------------------------------------------------------------------------------------------
// Description: resets all of the motor encoders
//	
//----------------------------------------------------------------------------------------------------
//Inputs:  None
//
//----------------------------------------------------------------------------------------------------
void resetAllMotorEncoders()
{
	nMotorEncoder[leftDrive] = 0;
	nMotorEncoder[rightDrive] = 0;
	nMotorEncoder[leftAttachment] = 0;
	nMotorEncoder[rightAttachment] = 0;
}


//----------------------------------------------------------------------------------------------------
// Name: setBrakeMode
//----------------------------------------------------------------------------------------------------
// Description:  Set brakes on the drive motors or sets the motors to coast
//	
//----------------------------------------------------------------------------------------------------
//Inputs:
//       brakeMode     Bool       brakeMode (on/off)
//----------------------------------------------------------------------------------------------------
void setBrakeMode(bool brakeMode)
{

	if (brakeMode)
	{
		// Set the brakes on the drive motors
		setMotorBrakeMode(leftDrive, motorBrake);
		setMotorBrakeMode(rightDrive, motorBrake);
	}
	else
	{
		// Set the motors to coast
		setMotorBrakeMode(leftDrive,motorCoast);
		setMotorBrakeMode(rightDrive,motorCoast);
	}


}
