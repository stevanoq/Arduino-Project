class MonitorKiri
{
private:
    
public:
    void begin();
    void sensor(float atas, float bawah, float up, float down);
    void selectAction();
    void done();
};

class MonitorKanan
{
private:
    int count;
public:
    void begin();
    void sensor(float suhu, float kel, float volt, float current);
    void selectAction();
    void setting();
    void done();
};

