// ---------------------------------------------------------------------------------------------------
// Name: encoderTurnFunctions
//----------------------------------------------------------------------------------------------------
// Description:
// Computes the amount you want to move (in degrees), sets the brakes to coast if they are on, resets
// the motor encoders, then checks if we are turning left or right by seeing if the degreesToTurn is
// greater or equal to 0. If we are turning to the right the right wheel is stopped and the left wheel
// is going at the speed we want it to. If we are turning to the left, the left wheel is stopped and 
// the right wheel is going at the speed we want it to. We wait for the left motor encoder is greater
// than or equal to the degrees to move. Because we are stopped on the left or right encoder, we can
// add them together because one will always be zero.
//----------------------------------------------------------------------------------------------------
//Inputs:
//	speed		Float	Speed of left wheel
//	degreesToTurn	Float	Speed of the right wheel
//	brakeMode	Bool	True = Turn on brakes at the end;  False = Coast at the end
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
void sideTurnEncoder(float speed, float degreesToTurn, bool brakeMode)
{

	float degreesToMove;

	// Compute the degrees to move
	degreesToMove = abs(degreesToTurn) * 3.376162;

	// Remove the brakes if they are applied
	setDriveMotorsToCoast();

	// Reset the Motor Encoders
	resetDriveMotorEncoders();


	// Check if turning to the left or to the right

	if (degreesToTurn >= 0)					// Turning to the right  - right wheel stopped left wheel set to speed
	{

		setMotorSpeed(leftDrive, speed);
		setMotorSpeed(rightDrive, 0);

	}
	else														// Turning to the left  - left wheel stopped right wheel set to speed
	{
		setMotorSpeed(leftDrive, 0);
		setMotorSpeed(rightDrive, speed);

	}


	// Wait until the left motor encoder is greater than or equal to the degrees to move.
	// Because we are stopped on the left or right encoder, we can add them together because one will always be zero.
	while (abs(getLeftMotorEncoder()) + abs(getRightMotorEncoder()) <= degreesToMove)
	{

	}


	turnOffDriveMotors();

	setBrakeMode(brakeMode);

}


void centerTurnEncoder(float speed, float degreesToTurn, bool brakeMode)
{

	float degreesToMove;

	// Compute the degrees to move
	degreesToMove = abs(degreesToTurn) * 1.688081;

	// Remove the brakes if they are applied
	setDriveMotorsToCoast();

	// Reset the Motor Encoders
	resetDriveMotorEncoders();


	// Check if turning to the left or to the right
	if (degreesToTurn >= 0)					// Turning to the right  - Left motor forward; right motor backward
	{

		setMotorSpeed(leftDrive, speed);
		setMotorSpeed(rightDrive, -speed);

	}
	else														// Turning to the left  - Left motor backward; right motor forward
	{
		setMotorSpeed(leftDrive, -speed);
		setMotorSpeed(rightDrive, speed);


	}

	// Wait until the left motor encoder is greater than or equal to the degrees to move.
	while (abs(getLeftMotorEncoder()) <= degreesToMove)
	{

	}


	turnOffDriveMotors();


	setBrakeMode(brakeMode);


}
