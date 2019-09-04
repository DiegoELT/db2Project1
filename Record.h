
template <class T>
class Record {
protected:
    T key;
public:
    virtual void setData() = 0;
    virtual void showData() = 0;
    virtual void write() = 0;
    virtual void read() = 0;
};