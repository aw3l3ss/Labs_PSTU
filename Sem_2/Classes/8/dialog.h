#ifndef DIALOG_H
#define DIALOG_H

#include "vector.h"
#include "event.h"

class Dialog : public Vector {
    protected:
        int EndState;
    public:
        Dialog(void);
        virtual ~Dialog(void);
        virtual void GetEvent(TEvent &event);
        virtual int Execute();
        virtual void HandleEvent(TEvent &event);
        virtual void ClearEvent(TEvent &event);
        int Valid();
        void EndExec();
};

#endif