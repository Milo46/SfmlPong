#include "PointsCounter.h"

namespace Pong
{
    PointsCounter::PointsCounter()
    {
        this->left = 0;
        this->right = 0;
    }

    PointsCounter::~PointsCounter()
    {

    }

    void PointsCounter::incrementLeft()
    {
        this->left++;
    }

    void PointsCounter::incrementRight()
    {
        this->right++;
    }

    void PointsCounter::reset()
    {
        this->left = 0;
        this->right = 0;
    }

    void PointsCounter::render()
    {
        std::cout << this->left << " : " << this->right << std::endl;
    }
}
