class Record {
protected:
    int key;
public:
    virtual void setData() = 0;
    virtual void showData() = 0;
    virtual void write() = 0;
    virtual void read() = 0;
};