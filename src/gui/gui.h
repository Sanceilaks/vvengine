//
// Created by Admin on 24.07.2021.
//

#ifndef VLUASTUDIO_GUI_H
#define VLUASTUDIO_GUI_H

#include "../observer.h"

namespace gui {
    class c_gui : public observer::i_observer {
    public:
        void new_frame();

        c_gui();
        ~c_gui();
    };
}

#endif //VLUASTUDIO_GUI_H
