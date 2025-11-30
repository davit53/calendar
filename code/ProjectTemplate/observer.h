class Observer {
public:
    // any class that wants updates from an Observable implements update().
    virtual ~Observer() {}
    virtual void update() = 0;
};
