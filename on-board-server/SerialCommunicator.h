#include <String.h>
#ifndef SerialCommunicator_H
#define SerialCommunicator_H

class SerialCommunicator
{
private:

    int baudRate;

    enum Command
    {
        UNKNOWN,
        ECHO
    };

    // This is a hacky way to do the C++11 'enum class'
    // https://stackoverflow.com/questions/6936030/do-we-really-need-enum-class-in-c11
    struct ResponseCode
    {
        enum _ResponseCode
        {
            OK = 200,
            BAD_REQ = 400
        };
    };

public:
    SerialCommunicator(int baudRate);

    void setup();

    bool process_data(String &inputData);
    void parse_command(String &inputData, Command &command);
    bool act(String &inputData, Command &command, String &response);
    void respond(String &response);
};

#endif
