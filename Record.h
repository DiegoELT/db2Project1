template <class k>
class Record {
    protected:
    virtual void setData() = 0;
    virtual void showData() = 0;
    virtual k getKey() = 0;
};