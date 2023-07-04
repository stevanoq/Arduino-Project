
#include <WString.h>
class myfirebase
{
private:
    
public:
    void begin();
    void send(String PATH, String data);
    void send_time(String path);
    void get_time(String path);
    int count;
    float TIME1, TIME2;
};

class ota
{
    private:
        const char* ssid = "PerAiran";
        const char* pass = "1234567890";
    public:
        void begin();
};