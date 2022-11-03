#pragma once
#include "Worker.h"
namespace MySpace {
    class Chief : public Worker {
    private:
        int yearsOnPost;
    public:
        Chief();
        Chief(string name, int age, int salary, int yearOnPost, string specialization, string placeOfStudy,
            string nameOfDeparment, int workingArea);
        ~Chief();
        void showInfo();
    };
}
