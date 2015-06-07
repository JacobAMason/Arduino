#include <Arduino.h>
#include "SerialCommunicator.h"


SerialCommunicator::SerialCommunicator(int baudRate=9600) : baudRate(baudRate){};


void SerialCommunicator::setup()
{
    Serial.begin(baudRate);
    Serial.println(String(ResponseCode::OK) + " Connected");
}


bool SerialCommunicator::process_data(String &inputData)
{
    bool result;
    Command command;
    String response;
    parse_command(inputData, command);
    result = act(inputData, command, response);
    respond(response);
    return result;
}


void SerialCommunicator::parse_command(String &inputData, Command &command)
{
    // Get leading numeric intruction.
    inputData.trim();
    int commandSeparatorIdx = inputData.indexOf(' ', 0);
    String numericStr = inputData.substring(0, commandSeparatorIdx);
    inputData = inputData.substring(commandSeparatorIdx+1);
    long numeric = numericStr.toInt();

    switch(numeric)
    {
        case 1:
            command = ECHO;
            break;

        default:
            command = UNKNOWN;
    }
}


bool SerialCommunicator::act(String &inputData, Command &command, String &response)
{
    bool LEDResponse = false;
    
    switch(command)
    {
        case ECHO:
            response = String(ResponseCode::OK) + " " + inputData;
            LEDResponse = true;
            break;
            
        case UNKNOWN:
            response = String(ResponseCode::BAD_REQ) + " '" + inputData + "'";
            break;
    }

    return LEDResponse;
}


void SerialCommunicator::respond(String &response)
{
    Serial.println(response);
}
